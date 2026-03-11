#include <iostream>

void unsafe_modify_const(const int* ptr) {
    int* modPtr = const_cast<int*>(ptr);
    std::cout << "[unsafe] Trying to modify a truly const object..." << std::endl;
    *modPtr = 20; // UNDEFINED BEHAVIOR! May crash, segfault, or seem to work.
}

void safe_modify_nonconst(const int* ptr) {
    int* modPtr = const_cast<int*>(ptr);
    std::cout << "[safe] Modifying original non-const variable." << std::endl;
    *modPtr = 99; // OK, since original was non-const
}

int main() {
    // Unsafe (undefined behavior)
    const int x = 10;
    std::cout << "[main] x before = " << x << std::endl;
    unsafe_modify_const(&x); // DO NOT DO THIS IN REAL CODE!
    std::cout << "[main] x after = " << x << std::endl; // May not print 20!

    // Safe use: non-const variable passed as const*
    int y = 123;
    const int* py = &y;
    std::cout << "[main] y before = " << y << std::endl;
    safe_modify_nonconst(py);
    std::cout << "[main] y after = " << y << std::endl; // Will print 99

    /*
    SUMMARY:
    - It is ONLY safe to write via const_cast when the original variable wasn't really declared as const.
    - Writing to a truly const object (e.g., global/static const, string/const literal) is undefined behavior (often segfaults).
    - Use const_cast only for legacy APIs, never to break logical constness!
    */
    return 0;
}
