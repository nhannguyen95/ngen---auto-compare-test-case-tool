# ngen 1.0---auto-compare-test-case-tool
This tool is built based on the Shell code on Unix/Linux/Mac, thus it can only run on those platforms.

Compile ngen.cpp, we have ngen.out and it takes 4 arguments:
+ gen.out: the file to generate test case, you have to write it yourself
+ mine.out: your algorithm file
+ their.out: the right algorithm file
+ n: an integer, number of test cases you want the program to create

Note: use the gen.cpp's random platform in repository, don't use srand(time(0)) + rand() !

Usage: ./ngen.out ./gen.out ./mine.out ./their.out 9
![alt tag](http://i.imgur.com/oE45ncu.png)

Author: nhannguyen95.wordpress.com
