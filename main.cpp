#include <iostream>
#include <windows.h>
using namespace std;

struct {
	POINT options;
	POINT review;
	POINT blank;
} pos;

POINT get_rev();
POINT get_opt();
POINT get_blank();
void forever(int tabs, int delay);
void repeat(int tabs, int delay);
void click(POINT options, POINT review, POINT blank, int tabs);
void clickfunc(DWORD dwFlag);
void key(int tabs);
void keyhit(WORD key);
void keyrelease(WORD key);

int main(void) {
	int in_definate, tabs, delay;
	cout << "(1) Forever Loop / (2) Repeat Loop: ";
	cin >> in_definate;
	cout << "How many tabs do you want to open each time. 1 tab/min = 4000pts: ";
	cin >> tabs;
	cout << "What is the delay for the loading tab (ms): ";
	cin >> delay;

	if (in_definate == 1) {forever(tabs, delay);}
	else if (in_definate == 2) {repeat(tabs, delay);}
	else {return 1;}
}

void forever(int tabs, int delay) {
	pos.options.x = 784;
	pos.options.y = 415;

	pos.blank.x = 688;
	pos.blank.y = 414;

	pos.review.x = 815;
	pos.review.y = 453;

	POINT options = pos.options; /*get_opt()*/
	POINT review = pos.review; /*get_rev()*/
	POINT blank = pos.blank; /*get_blank()*/
	Sleep(3000);

	while (true) {
		click(options, review, blank, tabs);
		Sleep(delay);
		key(tabs);
		Sleep(500);
	}
}


void repeat(int tabs, int delay) {
	pos.options.x = 784;
	pos.options.y = 415;

	pos.blank.x = 688;
	pos.blank.y = 414;

	pos.review.x = 815;
	pos.review.y = 453;

	POINT options = pos.options; /*get_opt()*/
	POINT review = pos.review; /*get_rev()*/
	POINT blank = pos.blank; /*get_blank()*/
	
	int repeats;
	cout << "Repeats: ";
	cin >> repeats;
	Sleep(3000);

	for (int i = 0; i < repeats; i++) {
		click(options, review, blank, tabs);
		Sleep(delay);
		key(tabs);
		Sleep(500);
	}
}

POINT get_opt() {
	cout << "Input Options Button's Location eg:16 34: ";
	cin >> pos.options.x >> pos.options.y;
	
	return pos.options;
}

POINT get_rev() {
	cout << "Input Review Button's Location eg:16 34: ";
    cin >> pos.review.x >> pos.review.y;

    return pos.review;
}

POINT get_blank() {
	cout << "Input a Blank Space Location eg:16 34: ";
	cin >> pos.blank.x >> pos.blank.y;

	return pos.blank;
}

void click(POINT options, POINT review, POINT blank, int tabs) {
    // Click Blank Space
    SetCursorPos(blank.x, blank.y);
	clickfunc(MOUSEEVENTF_LEFTDOWN);
	clickfunc(MOUSEEVENTF_LEFTUP);
    
	// Click Options Button
    SetCursorPos(options.x, options.y);
	clickfunc(MOUSEEVENTF_LEFTDOWN);
	clickfunc(MOUSEEVENTF_LEFTUP);

    // Middle-Click Review Button for (tabs)
    for (int i = 0; i < tabs; i++) {
        SetCursorPos(review.x, review.y);
		clickfunc(MOUSEEVENTF_MIDDLEDOWN);
		clickfunc(MOUSEEVENTF_MIDDLEUP);
    }
}

void clickfunc(DWORD dwFlag) {
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = dwFlag;

    SendInput(1, &input, sizeof(INPUT));
	Sleep(10);
}

void key(int tabs) {
	for (int i = 0; i < tabs; i++) {
        // keep Ctrl held
        keyhit(VK_CONTROL);
        
        // hit and release Tab
        keyhit(VK_TAB);
        keyrelease(VK_TAB);

        // hit and release V
        keyhit(0x56);
        keyrelease(0x56);

        // release Ctrl
        keyrelease(VK_CONTROL);
	}

	for (int i = 0; i < tabs; i++) {
        // keep Ctrl held
        keyhit(VK_CONTROL);

        // hit and release W
        keyhit(0x57);
        keyrelease(0x57);

        // release Ctrl
        keyrelease(VK_CONTROL);
	}
}

void keyhit(WORD key) {
    keybd_event(key, 0, 0, 0);
    Sleep(10);
}

void keyrelease(WORD key) {
    keybd_event(key, 0, KEYEVENTF_KEYUP, 0);
    Sleep(10);
}