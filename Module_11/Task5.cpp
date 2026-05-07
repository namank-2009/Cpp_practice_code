// use_after_free.cpp
#include <iostream>
int main() {
    int* p = new int(7);
    delete p;
    *p = 42;               // Use-after-free crash or undefined behavior
    std::cout << *p << std::endl;
    return 0;
}

/*
PS C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11> g++ -g -o use_after_free Task5.cpp
PS C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11> gdb ./use_after_free
GNU gdb (GDB) 7.6.1
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "mingw32".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11\use_after_free.exe...done.
(gdb) run
Starting program: C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11/./use_after_free.exe 
[New Thread 29732.0x11c]
[New Thread 29732.0x6d0c]
[New Thread 29732.0x7604]
[New Thread 29732.0x5614]
42
[Inferior 1 (process 29732) exited normally]
(gdb) bt
No stack.
(gdb) l
1       // use_after_free.cpp
2       #include <iostream>
3       int main() {
4           int* p = new int(7);
5           delete p;
6           *p = 42;               // Use-after-free crash or undefined behavior
7           std::cout << *p << std::endl;
8           return 0;
9       }
(gdb) */