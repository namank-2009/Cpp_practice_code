// crash_test.cpp
int main() {
    int* ptr = nullptr;
    *ptr = 42; // Null pointer dereference triggers crash
    return 0;
}
