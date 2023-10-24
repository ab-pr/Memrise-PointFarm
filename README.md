# Memrise Auto-Farm Bot Project

### A Macro to help you do your Memrise Homework.

This project is a Memrise auto-point-farmer to help you with your homework. This is just a macro and has no computer vision as that would be too draining on an end-users hardware. It's built in C++ and a DEPRICATED version is made with Python.

* You have to modify the code for it to work on your own machine
* The python version is slow
* All the code is there, you just have to remove and uncomment some lines
* You have to compile it yourself :)
* You would be better of doing Memrise manually
* Almost no secondary school students know C++
* The handful who do probably don't know it to this degree (its not that hard to interperet)
* Go away if you are lazy, which you most likely are, you fat piggy 🐷

# Instructions:

## Prerequisites:
* You must be on Windows NT device
* You must have a C++ compiler, eg GNU C/C++ Compiler
* You must be able to:
```c++
#include <iostream>
#include <windows.h>
```
* You must have a basic understanding of C++
* ⚠️💀 You must accept that im not responsible for any consequences of your actions and using the program to cheat in Memrise, or breaking your computer (just turn it on and off and don't have any unsaved or personal documents whilst using the program). 💀⚠️
* You must be willing to cheat and be bad person😲

## The guide (yay!)

**(1)** Clone the repo to a directory on you computer, eg 
```C:\Program Files (x86)\Microsoft\Temp```

**(2)** Extract the zip so you are left with:

```
Memrise-AutoFarm
    |__ .git
    |   |__ blah blah blah
    |
    |__ OLD
    |    |__ main.py
    |
    |__ main.cpp
    |
    |__ main.exe
    |
    |__ README.md
```
**(3)** Open main.cpp in a text editor and go to line *46 and 70*. Comment out / delete the stuff before that and remove the pos.option/review/blank and uncomment the commented stuff. eg:

```c++
void forever/repeat(int tabs, int delay) {
    /*
    junk;
    junk;

    junk;
    junk;
    
    junk;
    junk;
    */

	POINT options = get_opt();
	POINT review = get_rev();
	POINT blank = get_blank(); // removed the other stuff
}
```
**(4)** Now you can compile it. But how?

<details>
<summary>On Windows</summary>

4 [1] Get [MinGW](https://sourceforge.net/projects/mingw/).

4 [2] Install:

    [x] mingw-32-base
    [x] mingw-gcc-g++

4 [3] Add ```C:\MinGW\bin``` to **PATH** in ```System Environment Variables```

4 [4] Do g++ (input file) -o (output name)
</details>

**(5)** Now run the executable.
