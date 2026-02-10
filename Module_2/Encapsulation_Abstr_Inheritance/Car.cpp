#include <iostream>
using namespace std;

class Car {
private:
    bool engineOn;
    int speed;
    int rpm;

public:
    // Constructor to initialize state safely
    Car() {
        engineOn = false;
        speed = 0;
        rpm = 0;
    }

    void start() {
        if (!engineOn) {
            engineOn = true;
            speed = 0;
            rpm = 800;   // idle RPM
            cout << "Car started. Engine ON.\n";
        } else {
            cout << "Car is already running.\n";
        }
    }

    void accelerate() {
        if (engineOn) {
            if (speed < 120) {          // speed limit
                speed += 10;
                rpm += 500;
                cout << "Accelerating -> Speed: " << speed
                     << " km/h, RPM: " << rpm << endl;
            } else {
                cout << "Maximum speed reached!\n";
            }
        } else {
            cout << "Start the car first.\n";
        }
    }

    void brake() {
        if (engineOn && speed > 0) {
            speed -= 10;
            rpm -= 500;

            if (speed < 0) speed = 0;
            if (rpm < 800) rpm = 800;

            cout << "Braking -> Speed: " << speed
                 << " km/h, RPM: " << rpm << endl;
        } else {
            cout << "Car is already stopped.\n";
        }
    }
};

int main() {
    Car c;
    c.start();
    c.accelerate();
    c.accelerate();
    c.brake();
}
