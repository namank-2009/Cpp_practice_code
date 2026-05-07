#include <iostream>
int main() {
    int* ptr = nullptr;
    *ptr = 10; // Deliberate null pointer dereference
    return 0;
}

/*PS C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11\output> gdb --version
GNU gdb (GDB) 7.6.1
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "mingw32".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
PS C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11\output> cd ..                            
PS C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11> g++ -g -o crash_nullptr Task1.cpp
PS C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11> gdb ./crash_nullptr
GNU gdb (GDB) 7.6.1
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "mingw32".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11\crash_nullptr.exe...done.
(gdb) run
Starting program: C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11/./crash_nullptr.exe 
[New Thread 29988.0x667c]
[New Thread 29988.0x3680]
[New Thread 29988.0xe38]
[New Thread 29988.0x47b0]

Program received signal SIGSEGV, Segmentation fault.
0x0040147a in main () at Task1.cpp:4
4           *ptr = 10; // Deliberate null pointer dereference
(gdb) -bt
Undefined command: "-bt".  Try "help".
(gdb) bt
#0  0x0040147a in main () at Task1.cpp:4
(gdb) l 
1       #include <iostream>
2       int main() {
3           int* ptr = nullptr;
4           *ptr = 10; // Deliberate null pointer dereference
5           return 0;
6       }(gdb) */ 

/*
PS C:\Users\NamanGupta1\Desktop\C++_Course_Practise> cd 'c:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11\output'

PS C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11\output> & .\'Task1.exe'
PS C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11\output> cd 'c:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11\output'
PS C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11\output> & .\'Task2.exe'
42
PS C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11\output> cd..
PS C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11> g++ -g -o access_voilation Task2.cpp
PS C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11> gdb ./access_voilation
GNU gdb (GDB) 7.6.1
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "mingw32".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11\access_voilation.exe...done.
(gdb) run
Starting program: C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11/./access_voilation.exe 
[New Thread 25752.0x6b04]
[New Thread 25752.0x6370]
[New Thread 25752.0x5c90]
[New Thread 25752.0x4670]
42
[Inferior 1 (process 25752) exited normally]
(gdb) bt
No stack.
(gdb) l
1       // access_violation.cpp
2       #include <iostream>
3       int main() {
4           int* ptr = nullptr;
5           {
6               int local = 42;
7               ptr = &local;
8           } // local goes out of scope, ptr now dangling
9           std::cout << *ptr << std::endl; // Access violation/undefined behavior!
10          return 0;
(gdb) */