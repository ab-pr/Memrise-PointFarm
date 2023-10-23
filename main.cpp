#include <iostream>
#include <windows.h>
using namespace std;

struct {
	POINT options;
	POINT review;
} pos;

POINT get_rev();
POINT get_opt();
void click(options, review);
void keys();

void main() {
	int fl;
	cout << "(1) Forever Loop / (2) Repeat Loop: ";
	cin >> fl;
	
	if (fl == 1) {forever(fl);}
	else if (fl == 2) {repeat(fl);}
}

void forever(fl) {
	POINT options = get_opt();
	POINT review = get_rev();

	while (True) {
		click(options, review);
	}
}

/*
void repeat(fl) {
	
}
*/

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

void click(options, review) {
	// Option button --> miss
	SetCursorPos(options + 100);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);

	// Option Button --> click
	SetCursorPos(options);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);

	// Review Button --> click;
	SetCursorPos(review);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
}

















