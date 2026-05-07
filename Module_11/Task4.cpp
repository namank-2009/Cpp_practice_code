// stack_overflow.cpp
#include <iostream>
void recurse() {
    recurse(); // No base case!
}
int main() {
    recurse();
    return 0;
}

/*
PS C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11> g++ -g -o stack_overflow Task4.cpp
PS C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11> gdb ./stack_overflow
GNU gdb (GDB) 7.6.1
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "mingw32".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11\stack_overflow.exe...done.
(gdb) run
Starting program: C:\Users\NamanGupta1\Desktop\C++_Course_Practise\Module_11/./stack_overflow.exe 
[New Thread 30516.0x79f4]
[New Thread 30516.0x31c]
[New Thread 30516.0x6814]
[New Thread 30516.0x7974]

Program received signal SIGSEGV, Segmentation fault.
recurse () at Task4.cpp:4
4           recurse(); // No base case!
(gdb) bt
#0  recurse () at Task4.cpp:4
#1  0x0040146b in recurse () at Task4.cpp:4
#2  0x0040146b in recurse () at Task4.cpp:4
#3  0x0040146b in recurse () at Task4.cpp:4
#4  0x0040146b in recurse () at Task4.cpp:4
#5  0x0040146b in recurse () at Task4.cpp:4
#6  0x0040146b in recurse () at Task4.cpp:4
#7  0x0040146b in recurse () at Task4.cpp:4
#8  0x0040146b in recurse () at Task4.cpp:4
#9  0x0040146b in recurse () at Task4.cpp:4
#10 0x0040146b in recurse () at Task4.cpp:4
#11 0x0040146b in recurse () at Task4.cpp:4
#12 0x0040146b in recurse () at Task4.cpp:4
#13 0x0040146b in recurse () at Task4.cpp:4
#14 0x0040146b in recurse () at Task4.cpp:4
#15 0x0040146b in recurse () at Task4.cpp:4
#16 0x0040146b in recurse () at Task4.cpp:4
#17 0x0040146b in recurse () at Task4.cpp:4
#18 0x0040146b in recurse () at Task4.cpp:4
#19 0x0040146b in recurse () at Task4.cpp:4
#20 0x0040146b in recurse () at Task4.cpp:4
#21 0x0040146b in recurse () at Task4.cpp:4
#22 0x0040146b in recurse () at Task4.cpp:4
#23 0x0040146b in recurse () at Task4.cpp:4
#24 0x0040146b in recurse () at Task4.cpp:4
#25 0x0040146b in recurse () at Task4.cpp:4
#26 0x0040146b in recurse () at Task4.cpp:4
#27 0x0040146b in recurse () at Task4.cpp:4
#28 0x0040146b in recurse () at Task4.cpp:4
#29 0x0040146b in recurse () at Task4.cpp:4
#30 0x0040146b in recurse () at Task4.cpp:4
#31 0x0040146b in recurse () at Task4.cpp:4
#32 0x0040146b in recurse () at Task4.cpp:4
#33 0x0040146b in recurse () at Task4.cpp:4
#34 0x0040146b in recurse () at Task4.cpp:4
#35 0x0040146b in recurse () at Task4.cpp:4
#36 0x0040146b in recurse () at Task4.cpp:4
#37 0x0040146b in recurse () at Task4.cpp:4
#38 0x0040146b in recurse () at Task4.cpp:4
#39 0x0040146b in recurse () at Task4.cpp:4
#40 0x0040146b in recurse () at Task4.cpp:4
#41 0x0040146b in recurse () at Task4.cpp:4
#42 0x0040146b in recurse () at Task4.cpp:4
#43 0x0040146b in recurse () at Task4.cpp:4
#44 0x0040146b in recurse () at Task4.cpp:4
#45 0x0040146b in recurse () at Task4.cpp:4
#46 0x0040146b in recurse () at Task4.cpp:4
#47 0x0040146b in recurse () at Task4.cpp:4
#48 0x0040146b in recurse () at Task4.cpp:4
#49 0x0040146b in recurse () at Task4.cpp:4
#50 0x0040146b in recurse () at Task4.cpp:4
#51 0x0040146b in recurse () at Task4.cpp:4
#52 0x0040146b in recurse () at Task4.cpp:4
#53 0x0040146b in recurse () at Task4.cpp:4
#54 0x0040146b in recurse () at Task4.cpp:4
#55 0x0040146b in recurse () at Task4.cpp:4
#56 0x0040146b in recurse () at Task4.cpp:4
#57 0x0040146b in recurse () at Task4.cpp:4
#58 0x0040146b in recurse () at Task4.cpp:4
#59 0x0040146b in recurse () at Task4.cpp:4
#60 0x0040146b in recurse () at Task4.cpp:4
#61 0x0040146b in recurse () at Task4.cpp:4
#62 0x0040146b in recurse () at Task4.cpp:4
#63 0x0040146b in recurse () at Task4.cpp:4
#64 0x0040146b in recurse () at Task4.cpp:4
#65 0x0040146b in recurse () at Task4.cpp:4
#66 0x0040146b in recurse () at Task4.cpp:4
#67 0x0040146b in recurse () at Task4.cpp:4
#68 0x0040146b in recurse () at Task4.cpp:4
#69 0x0040146b in recurse () at Task4.cpp:4
#70 0x0040146b in recurse () at Task4.cpp:4
#71 0x0040146b in recurse () at Task4.cpp:4
#72 0x0040146b in recurse () at Task4.cpp:4
#73 0x0040146b in recurse () at Task4.cpp:4
#74 0x0040146b in recurse () at Task4.cpp:4
#75 0x0040146b in recurse () at Task4.cpp:4
#76 0x0040146b in recurse () at Task4.cpp:4
#77 0x0040146b in recurse () at Task4.cpp:4
#78 0x0040146b in recurse () at Task4.cpp:4
#79 0x0040146b in recurse () at Task4.cpp:4
#80 0x0040146b in recurse () at Task4.cpp:4
#81 0x0040146b in recurse () at Task4.cpp:4
#82 0x0040146b in recurse () at Task4.cpp:4
#83 0x0040146b in recurse () at Task4.cpp:4
#84 0x0040146b in recurse () at Task4.cpp:4
#85 0x0040146b in recurse () at Task4.cpp:4
#86 0x0040146b in recurse () at Task4.cpp:4
#87 0x0040146b in recurse () at Task4.cpp:4
#88 0x0040146b in recurse () at Task4.cpp:4
#89 0x0040146b in recurse () at Task4.cpp:4
#90 0x0040146b in recurse () at Task4.cpp:4
#91 0x0040146b in recurse () at Task4.cpp:4
#92 0x0040146b in recurse () at Task4.cpp:4
#93 0x0040146b in recurse () at Task4.cpp:4
#94 0x0040146b in recurse () at Task4.cpp:4
#95 0x0040146b in recurse () at Task4.cpp:4
#96 0x0040146b in recurse () at Task4.cpp:4
#97 0x0040146b in recurse () at Task4.cpp:4
#98 0x0040146b in recurse () at Task4.cpp:4
#99 0x0040146b in recurse () at Task4.cpp:4
#100 0x0040146b in recurse () at Task4.cpp:4
#101 0x0040146b in recurse () at Task4.cpp:4
#102 0x0040146b in recurse () at Task4.cpp:4
#103 0x0040146b in recurse () at Task4.cpp:4
#104 0x0040146b in recurse () at Task4.cpp:4
#105 0x0040146b in recurse () at Task4.cpp:4
#106 0x0040146b in recurse () at Task4.cpp:4
#107 0x0040146b in recurse () at Task4.cpp:4
#108 0x0040146b in recurse () at Task4.cpp:4
#109 0x0040146b in recurse () at Task4.cpp:4
#110 0x0040146b in recurse () at Task4.cpp:4
#111 0x0040146b in recurse () at Task4.cpp:4
#112 0x0040146b in recurse () at Task4.cpp:4
#113 0x0040146b in recurse () at Task4.cpp:4
#114 0x0040146b in recurse () at Task4.cpp:4
#115 0x0040146b in recurse () at Task4.cpp:4
#116 0x0040146b in recurse () at Task4.cpp:4
#117 0x0040146b in recurse () at Task4.cpp:4
#118 0x0040146b in recurse () at Task4.cpp:4
#119 0x0040146b in recurse () at Task4.cpp:4
#120 0x0040146b in recurse () at Task4.cpp:4
#121 0x0040146b in recurse () at Task4.cpp:4
#122 0x0040146b in recurse () at Task4.cpp:4
#123 0x0040146b in recurse () at Task4.cpp:4
#124 0x0040146b in recurse () at Task4.cpp:4
#125 0x0040146b in recurse () at Task4.cpp:4
#126 0x0040146b in recurse () at Task4.cpp:4
#127 0x0040146b in recurse () at Task4.cpp:4
#128 0x0040146b in recurse () at Task4.cpp:4
#129 0x0040146b in recurse () at Task4.cpp:4
#130 0x0040146b in recurse () at Task4.cpp:4
#131 0x0040146b in recurse () at Task4.cpp:4
#132 0x0040146b in recurse () at Task4.cpp:4
#133 0x0040146b in recurse () at Task4.cpp:4
#134 0x0040146b in recurse () at Task4.cpp:4
#135 0x0040146b in recurse () at Task4.cpp:4
#136 0x0040146b in recurse () at Task4.cpp:4
#137 0x0040146b in recurse () at Task4.cpp:4
#138 0x0040146b in recurse () at Task4.cpp:4
#139 0x0040146b in recurse () at Task4.cpp:4
#140 0x0040146b in recurse () at Task4.cpp:4
#141 0x0040146b in recurse () at Task4.cpp:4
#142 0x0040146b in recurse () at Task4.cpp:4
#143 0x0040146b in recurse () at Task4.cpp:4
#144 0x0040146b in recurse () at Task4.cpp:4
#145 0x0040146b in recurse () at Task4.cpp:4
#146 0x0040146b in recurse () at Task4.cpp:4
#147 0x0040146b in recurse () at Task4.cpp:4
#148 0x0040146b in recurse () at Task4.cpp:4
#149 0x0040146b in recurse () at Task4.cpp:4
#150 0x0040146b in recurse () at Task4.cpp:4
#151 0x0040146b in recurse () at Task4.cpp:4
#152 0x0040146b in recurse () at Task4.cpp:4
#153 0x0040146b in recurse () at Task4.cpp:4
#154 0x0040146b in recurse () at Task4.cpp:4
#155 0x0040146b in recurse () at Task4.cpp:4
#156 0x0040146b in recurse () at Task4.cpp:4
#157 0x0040146b in recurse () at Task4.cpp:4
#158 0x0040146b in recurse () at Task4.cpp:4
#159 0x0040146b in recurse () at Task4.cpp:4
#160 0x0040146b in recurse () at Task4.cpp:4
#161 0x0040146b in recurse () at Task4.cpp:4
#162 0x0040146b in recurse () at Task4.cpp:4
#163 0x0040146b in recurse () at Task4.cpp:4
#164 0x0040146b in recurse () at Task4.cpp:4
#165 0x0040146b in recurse () at Task4.cpp:4
#166 0x0040146b in recurse () at Task4.cpp:4
#167 0x0040146b in recurse () at Task4.cpp:4
#168 0x0040146b in recurse () at Task4.cpp:4
#169 0x0040146b in recurse () at Task4.cpp:4
#170 0x0040146b in recurse () at Task4.cpp:4
#171 0x0040146b in recurse () at Task4.cpp:4
#172 0x0040146b in recurse () at Task4.cpp:4
#173 0x0040146b in recurse () at Task4.cpp:4
#174 0x0040146b in recurse () at Task4.cpp:4
#175 0x0040146b in recurse () at Task4.cpp:4
#176 0x0040146b in recurse () at Task4.cpp:4
#177 0x0040146b in recurse () at Task4.cpp:4
#178 0x0040146b in recurse () at Task4.cpp:4
#179 0x0040146b in recurse () at Task4.cpp:4
#180 0x0040146b in recurse () at Task4.cpp:4
#181 0x0040146b in recurse () at Task4.cpp:4
#182 0x0040146b in recurse () at Task4.cpp:4
#183 0x0040146b in recurse () at Task4.cpp:4
#184 0x0040146b in recurse () at Task4.cpp:4
#185 0x0040146b in recurse () at Task4.cpp:4
#186 0x0040146b in recurse () at Task4.cpp:4
#187 0x0040146b in recurse () at Task4.cpp:4
#188 0x0040146b in recurse () at Task4.cpp:4
#189 0x0040146b in recurse () at Task4.cpp:4
#190 0x0040146b in recurse () at Task4.cpp:4
#191 0x0040146b in recurse () at Task4.cpp:4
#192 0x0040146b in recurse () at Task4.cpp:4
#193 0x0040146b in recurse () at Task4.cpp:4
#194 0x0040146b in recurse () at Task4.cpp:4
#195 0x0040146b in recurse () at Task4.cpp:4
#196 0x0040146b in recurse () at Task4.cpp:4
#197 0x0040146b in recurse () at Task4.cpp:4
#198 0x0040146b in recurse () at Task4.cpp:4
#199 0x0040146b in recurse () at Task4.cpp:4
#200 0x0040146b in recurse () at Task4.cpp:4
#201 0x0040146b in recurse () at Task4.cpp:4
#202 0x0040146b in recurse () at Task4.cpp:4
#203 0x0040146b in recurse () at Task4.cpp:4
#204 0x0040146b in recurse () at Task4.cpp:4
#205 0x0040146b in recurse () at Task4.cpp:4
#206 0x0040146b in recurse () at Task4.cpp:4
#207 0x0040146b in recurse () at Task4.cpp:4
#208 0x0040146b in recurse () at Task4.cpp:4
#209 0x0040146b in recurse () at Task4.cpp:4
#210 0x0040146b in recurse () at Task4.cpp:4
#211 0x0040146b in recurse () at Task4.cpp:4
#212 0x0040146b in recurse () at Task4.cpp:4
#213 0x0040146b in recurse () at Task4.cpp:4
#214 0x0040146b in recurse () at Task4.cpp:4
#215 0x0040146b in recurse () at Task4.cpp:4
#216 0x0040146b in recurse () at Task4.cpp:4
#217 0x0040146b in recurse () at Task4.cpp:4
#218 0x0040146b in recurse () at Task4.cpp:4
#219 0x0040146b in recurse () at Task4.cpp:4
#220 0x0040146b in recurse () at Task4.cpp:4
#221 0x0040146b in recurse () at Task4.cpp:4
#222 0x0040146b in recurse () at Task4.cpp:4
#223 0x0040146b in recurse () at Task4.cpp:4
#224 0x0040146b in recurse () at Task4.cpp:4
#225 0x0040146b in recurse () at Task4.cpp:4
#226 0x0040146b in recurse () at Task4.cpp:4
#227 0x0040146b in recurse () at Task4.cpp:4
#228 0x0040146b in recurse () at Task4.cpp:4
#229 0x0040146b in recurse () at Task4.cpp:4
#230 0x0040146b in recurse () at Task4.cpp:4
#231 0x0040146b in recurse () at Task4.cpp:4
#232 0x0040146b in recurse () at Task4.cpp:4
#233 0x0040146b in recurse () at Task4.cpp:4
#234 0x0040146b in recurse () at Task4.cpp:4
#235 0x0040146b in recurse () at Task4.cpp:4
#236 0x0040146b in recurse () at Task4.cpp:4
#237 0x0040146b in recurse () at Task4.cpp:4
#238 0x0040146b in recurse () at Task4.cpp:4
#239 0x0040146b in recurse () at Task4.cpp:4
#240 0x0040146b in recurse () at Task4.cpp:4
#241 0x0040146b in recurse () at Task4.cpp:4
#242 0x0040146b in recurse () at Task4.cpp:4
#243 0x0040146b in recurse () at Task4.cpp:4
#244 0x0040146b in recurse () at Task4.cpp:4
#245 0x0040146b in recurse () at Task4.cpp:4
#246 0x0040146b in recurse () at Task4.cpp:4
#247 0x0040146b in recurse () at Task4.cpp:4
#248 0x0040146b in recurse () at Task4.cpp:4
#249 0x0040146b in recurse () at Task4.cpp:4
#250 0x0040146b in recurse () at Task4.cpp:4
#251 0x0040146b in recurse () at Task4.cpp:4
#252 0x0040146b in recurse () at Task4.cpp:4
#253 0x0040146b in recurse () at Task4.cpp:4
#254 0x0040146b in recurse () at Task4.cpp:4
#255 0x0040146b in recurse () at Task4.cpp:4
#256 0x0040146b in recurse () at Task4.cpp:4
#257 0x0040146b in recurse () at Task4.cpp:4
#258 0x0040146b in recurse () at Task4.cpp:4
#259 0x0040146b in recurse () at Task4.cpp:4
#260 0x0040146b in recurse () at Task4.cpp:4
#261 0x0040146b in recurse () at Task4.cpp:4
#262 0x0040146b in recurse () at Task4.cpp:4
#263 0x0040146b in recurse () at Task4.cpp:4
#264 0x0040146b in recurse () at Task4.cpp:4
#265 0x0040146b in recurse () at Task4.cpp:4
#266 0x0040146b in recurse () at Task4.cpp:4
#267 0x0040146b in recurse () at Task4.cpp:4
#268 0x0040146b in recurse () at Task4.cpp:4
#269 0x0040146b in recurse () at Task4.cpp:4
#270 0x0040146b in recurse () at Task4.cpp:4
#271 0x0040146b in recurse () at Task4.cpp:4
#272 0x0040146b in recurse () at Task4.cpp:4
#273 0x0040146b in recurse () at Task4.cpp:4
#274 0x0040146b in recurse () at Task4.cpp:4
#275 0x0040146b in recurse () at Task4.cpp:4
#276 0x0040146b in recurse () at Task4.cpp:4
#277 0x0040146b in recurse () at Task4.cpp:4
#278 0x0040146b in recurse () at Task4.cpp:4
#279 0x0040146b in recurse () at Task4.cpp:4
#280 0x0040146b in recurse () at Task4.cpp:4
#281 0x0040146b in recurse () at Task4.cpp:4
#282 0x0040146b in recurse () at Task4.cpp:4
#283 0x0040146b in recurse () at Task4.cpp:4
#284 0x0040146b in recurse () at Task4.cpp:4
#285 0x0040146b in recurse () at Task4.cpp:4
#286 0x0040146b in recurse () at Task4.cpp:4
#287 0x0040146b in recurse () at Task4.cpp:4
#288 0x0040146b in recurse () at Task4.cpp:4
#289 0x0040146b in recurse () at Task4.cpp:4
#290 0x0040146b in recurse () at Task4.cpp:4
#291 0x0040146b in recurse () at Task4.cpp:4
#292 0x0040146b in recurse () at Task4.cpp:4
#293 0x0040146b in recurse () at Task4.cpp:4
#294 0x0040146b in recurse () at Task4.cpp:4
#295 0x0040146b in recurse () at Task4.cpp:4
#296 0x0040146b in recurse () at Task4.cpp:4
#297 0x0040146b in recurse () at Task4.cpp:4
#298 0x0040146b in recurse () at Task4.cpp:4
#299 0x0040146b in recurse () at Task4.cpp:4
#300 0x0040146b in recurse () at Task4.cpp:4
#301 0x0040146b in recurse () at Task4.cpp:4
#302 0x0040146b in recurse () at Task4.cpp:4
#303 0x0040146b in recurse () at Task4.cpp:4
#304 0x0040146b in recurse () at Task4.cpp:4
#305 0x0040146b in recurse () at Task4.cpp:4
#306 0x0040146b in recurse () at Task4.cpp:4
#307 0x0040146b in recurse () at Task4.cpp:4
Quit (expect signal SIGINT when the program is resumed)
*/