#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class ThreadPool {
private:
    vector<thread> workers;
    queue<function<void()>> tasks;

    mutex mtx;
    condition_variable cv;
    bool stop;

public:
    // Constructor
    ThreadPool(int n) : stop(false) {
        for (int i = 0; i < n; i++) {
            workers.emplace_back([this]() {
                while (true) {
                    function<void()> task;

                    {
                        unique_lock<mutex> lock(this->mtx);

                        // Wait until task available OR stop signal
                        this->cv.wait(lock, [this]() {
                            return !this->tasks.empty() || this->stop;
                        });

                        // If stopping and no tasks left → exit
                        if (this->stop && this->tasks.empty())
                            return;

                        // Get task
                        task = move(this->tasks.front());
                        this->tasks.pop();
                    }

                    // Execute outside lock
                    task();
                }
            });
        }
    }

    // Submit task
    void submit(function<void()> f) {
        {
            unique_lock<mutex> lock(mtx);

            if (stop) {
                throw runtime_error("ThreadPool is stopped!");
            }

            tasks.push(move(f));
        }
        cv.notify_one();
    }

    // Destructor
    ~ThreadPool() {
        {
            unique_lock<mutex> lock(mtx);
            stop = true;
        }

        cv.notify_all();

        for (thread &t : workers) {
            if (t.joinable())
                t.join();
        }
    }
};

int main() {
    ThreadPool pool(3);

    for (int i = 1; i <= 10; i++) {
        pool.submit([i]() {
            cout << "Task " << i << " is running on thread "
                 << this_thread::get_id() << endl;

            this_thread::sleep_for(chrono::milliseconds(500));
        });
    }

    return 0;
}