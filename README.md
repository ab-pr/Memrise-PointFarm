# Memrise Point-Farming Bot Project

### A Macro to help you do your Memrise Homework.

This project is a Memrise auto-point-farmer to help you with your homework. This is just a macro and has no computer vision as that would be too draining on an end-users hardware. It's built in C++ and a DEPRICATED version is made with Python.

* You have to modify the code for it to work on your own machine
* The python version is slow
* All the code is there, you just have to remove and uncomment some lines
* You have to compile it yourself; if you use my version it probably won't work.
* You would be better of doing Memrise manually because it doesn't take care of long term memory.

## **If you want to automate LTM then click [here](https://github.com/CB61-A1/Memrise-LTM-Automator/tree/main)**

# Instructions:

## Prerequisites:
* You must be on Windows NT device
* You must have a C++ compiler, eg GNU C/C++ Compiler
* You must have ```windows``` headers:
```c++
#include <windows.h>
```
* You must have a basic understanding of C++
* You must accept that im not responsible for any consequences of your actions and using the program to cheat in Memrise, or breaking your computer (just turn it on and off and don't have any unsaved or personal documents whilst using the program).
* You must be willing to cheat and be bad person😲

## The guide:

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
    other_stuff;
	other_stuff;

    other_stuff;
    other_stuff;
    
    other_stuff;
    other_stuff;
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

    [🟩] mingw-32-base
    [🟩] mingw-gcc-g++

4 [3] Add ```C:\MinGW\bin``` to **PATH** in ```System Environment Variables```

4 [4] Do g++ (input file) -o (output name)
</details>

**(5)** Now run the executable.

***

## Usage:

You will be prompted in a window to choose to either use a forever loop or a finite loop:
```(1) Forever Loop / (2) Repeat Loop: ```. Then you will be prompted how many tabs you want to open each time, and the delay from opening those tabs to switching to them. I suggest that if you have a:

* Good Computer --> 15 with a delay of 5000ms
* OK Computer --> 7 with a delay of 3000ms
* Bad Computer --> 5 with a delay of 4000ms

### How to Set Up your Memrise
**(1)** Go to a level and click the **⚙️Ignore** button.

**(2)** Now select all to ignore then uncheck **one** word.

**(3)** Now click apply and you are done. Make sure to scroll the the top of the page.

### The Inputs

Now you will be prompted the coordinates of the **Options Button**, **Review Button** and a **Blank Space**. Use [this mouse location finding tool](https://sourceforge.net/projects/mpos/) to input the (x, y) locations. 

If you chose a finite loop then you will be prompted: ```Repeats: ```. Input how many times you want the program to run. I reccomend this option and test with the values. The forever loop will just run infinitely.

Now the bot should be running. If you want to quit, **```CTRL + TAB```** into the terminal window running the bot and press **```CTRL + C```**.

### Common Fixes

If the program is closing tabs too quickly and it misses one, add a ```Sleep(eg500)``` after each **```CTRL + W```**. eg:

Start at Line 136:
```c++
void key(int tabs) {
	for (int i = 0; i < tabs; i++) {
        keyhit(VK_CONTROL);

        keyhit(VK_TAB);
        keyrelease(VK_TAB);

        keyhit(0x56);
        keyrelease(0x56);

        keyrelease(VK_CONTROL);
	}

	for (int i = 0; i < tabs; i++) {

        keyhit(VK_CONTROL);
        Sleep(100); // ADDED

        keyhit(0x57);
        Sleep(100); // ADDED
        keyrelease(0x57);

        Sleep(100); // ADDED
        keyrelease(VK_CONTROL);

        // Change the time to whatever you want.

	}
}
```
