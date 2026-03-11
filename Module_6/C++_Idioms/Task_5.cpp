#include<iostream>
#include<chrono>
using namespace std;

class Timer{
    chrono::high_resolution_clock::time_point start;
    string label;
    public:
        Timer(const string& lbl): start(std::chrono::high_resolution_clock::now()), label(lbl) {
            if(!label.empty()){
                cout<<"Time started: "<<label<<endl;
            }
        }

        ~Timer(){
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
            cout<<(label.empty()? "Elapsed time: ":"Timer ["+label+"] elapsed: ");
            std::cout << duration.count() << "us" << std::endl;
        }
};
int main() {
    {
        Timer t("Loop block timing");
        int sum = 0;
        for (int i = 0; i < 1000000; ++i)
            sum += i;
        std::cout << "Sum: " << sum << std::endl;
    } // Timer destructor prints here!

    return 0;
}
