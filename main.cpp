#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <winuser.h>
using namespace std;

struct {
	POINT options;
	POINT review;
	POINT blank;
} pos;

POINT get_rev();
POINT get_opt();
POINT get_blank();
void forever(int tabs);
void repeat(int tabs);
void click(POINT options, POINT review, POINT blank, int tabs);
void key(int tabs);
int duration = 500; 

int main(void) {
	int fl, tabs;
	cout << "(1) Forever Loop / (2) Repeat Loop: ";
	cin >> fl;
	cout << "How many tabs do you want to open each time. 1 tab/min = 4000pts: ";
	cin >> tabs;	

	if (fl == 1) {forever(tabs);}
	else if (fl == 2) {repeat(tabs);}
	else {return 1;} // SAFETY
}

void forever(int tabs) {
	pos.options.x = 784;
	pos.options.y = 415;

	pos.blank.x = 688;
	pos.blank.y = 414;

	pos.review.x = 815;
	pos.review.y = 453;

	POINT options = pos.options; /*get_opt()*/
	POINT review = pos.review; /*get_rev()*/
	POINT blank = pos.blank; /*get_blank()*/
	sleep(3);

	while (true) {
		click(options, review, blank, tabs);
		key(tabs);
	}
}


void repeat(int tabs) {
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
	sleep(3);

	for (int i = 0; i < repeats; i++) {
		click(options, review, blank, tabs);
		key(tabs);
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
	mouse_event(0x0002, 0, 0, 0, 0);
	Sleep(50);
	mouse_event(0x0003, 0, 0, 0, 0);
	Sleep(duration);
	
	// Click Options Button
	SetCursorPos(options.x, options.y);
	mouse_event(0x0002, 0, 0, 0, 0);
	Sleep(50);
	mouse_event(0x0003, 0, 0, 0, 0);
	Sleep(duration);
	

	// Middle-Click Review Button for(tabs)
	for (int i = 0; i < tabs; i++) {
		SetCursorPos(review.x, review.y);
		mouse_event(0x0020, 0, 0, 0, 0);
		Sleep(50);
		mouse_event(0x0040, 0, 0, 0, 0);
		Sleep(10);
	}
}

void key(int tabs) {
	INPUT inputCtrlDown, inputTab, inputTabUp, inputCtrlUp, inputWUp, inputWDown;

	for (int i = 0; i < tabs; i++) {
    	// CTRL-DOWN
    	inputCtrlDown.type = INPUT_KEYBOARD;
    	inputCtrlDown.ki.wVk = VK_CONTROL;
    	inputCtrlDown.ki.dwFlags = 0;
		SendInput(1, &inputCtrlDown, sizeof(INPUT));
    	Sleep(duration);

    	// TAB-DOWN
    	inputTab.type = INPUT_KEYBOARD;
    	inputTab.ki.wVk = VK_TAB;
    	inputTab.ki.dwFlags = 0;
    	SendInput(1, &inputTab, sizeof(INPUT));
    	Sleep(duration);

		// TAB-UP
    	inputTabUp.type = INPUT_KEYBOARD;
    	inputTabUp.ki.wVk = VK_TAB;
    	inputTabUp.ki.dwFlags = KEYEVENTF_KEYUP;
    	SendInput(1, &inputTabUp, sizeof(INPUT));
    	Sleep(duration);

    	// CTRL-UP
    	inputCtrlUp.type = INPUT_KEYBOARD;
    	inputCtrlUp.ki.wVk = VK_CONTROL;
   		inputCtrlUp.ki.dwFlags = KEYEVENTF_KEYUP;
    	SendInput(1, &inputCtrlUp, sizeof(INPUT));
    	Sleep(duration);
	}
	

	SendInput(1, &inputCtrlDown, sizeof(INPUT));
	
	for (int i = 0; i < tabs; i++) {
		// W-DOWN
		inputWDown.type = INPUT_KEYBOARD;
		inputWDown.ki.wVk = 'W';
		inputWDown.ki.dwFlags = 0;
		SendInput(1, &inputWDown, sizeof(INPUT));
    	Sleep(duration);
		// W-UP
		inputWUp.type = INPUT_KEYBOARD;
		inputWUp.ki.wVk = 'W';
		inputWUp.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &inputWUp, sizeof(INPUT));
    	Sleep(duration);
	}
}

