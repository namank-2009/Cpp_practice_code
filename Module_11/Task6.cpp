// div_by_zero.cpp
#include <iostream>
int main() {
    int a = 10 / 0; // Division by zero
    std::cout << "Result: " << a << std::endl;
    return 0;
}

/*
PS C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11> g++ -g -o div_by_zero Task6.cpp
Task6.cpp: In function 'int main()':
Task6.cpp:4:16: warning: division by zero [-Wdiv-by-zero]
     int a = 10 / 0; // Division by zero
             ~~~^~~
PS C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11> gdb ./div_by_zero
GNU gdb (GDB) 7.6.1
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "mingw32".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11\div_by_zero.exe...done.
(gdb) run
Starting program: C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11/./div_by_zero.exe 
[New Thread 9284.0x4914]
[New Thread 9284.0x2990]
[New Thread 9284.0x6c24]
[New Thread 9284.0x56c0]

Program received signal SIGFPE, Arithmetic exception.
0x00401481 in main () at Task6.cpp:4
4           int a = 10 / 0; // Division by zero
(gdb) bt
#0  0x00401481 in main () at Task6.cpp:4
(gdb) l
1       // div_by_zero.cpp
2       #include <iostream>
3       int main() {
4           int a = 10 / 0; // Division by zero
5           std::cout << "Result: " << a << std::endl;
6           return 0;
7       }
(gdb) */