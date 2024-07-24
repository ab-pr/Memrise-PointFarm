#include <stdio.h>
#include <unistd.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <X11/keysym.h>

#define optionsDef pos.options
#define reviewDef  pos.review
#define blankDef   pos.blank
#define flush      XFlush(display)


typedef struct {
	int x;
	int y;
} POINT;

typedef struct {
	POINT options;
	POINT review;
	POINT blank;
} POS;

POS pos;


POINT GetReview();
POINT GetOptions();
POINT GetBlank();
int Forever(int tabs, float delay);
int Repeated(int tabs, float delay);
void Click(POINT options, POINT review, POINT blank, int tabs, Display *display, Window root);
void Key(int tabs, Display *display);


int
main() {
	int option, tabs, delay;
 
	printf("Forever / Finite Loop ( 1 / 2 ): ");
	scanf("%d", &option);

	printf("Tabs opened each time: ");
	scanf("%d", &tabs);

	printf("Tab loading delay: ");
	scanf("%d", &delay);

	switch (option) {
	case 1:
		Forever(tabs, delay);
		break;
	case 2:
		Repeated(tabs, delay);
		break;
	default:
		return 1;
	}

	return 0;
}

POINT
GetReview() {
	printf("Enter the X & Y Position of the Review button:    ");
	scanf("%d %d", &pos.review.x, &pos.review.y);
	return pos.review;
}

POINT
GetOptions() {
	printf("Enter the X & Y Position of the Options button:   ");
	scanf("%d %d", &pos.options.x, &pos.options.y);
	return pos.options;
}

POINT
GetBlank() {
	printf("Enter the X & Y Position of a blank space:        ");
	scanf("%d %d", &pos.blank.x, &pos.blank.y);
	return pos.blank;
}

int
Forever(int tabs, float delay) {
	GetOptions();
	GetReview();
	GetBlank();

	sleep(2);

	Display *display = XOpenDisplay(NULL);
	if (display == NULL) {
		fprintf(stderr, "Unable to open display\n");
		return 1;
	}   Window root = DefaultRootWindow(display);

	while ( 1 ) {
		Click(optionsDef, reviewDef, blankDef, tabs, display, root); usleep(delay * 1000000);
		Key(tabs, display); usleep(10 * 10000);
	}
	XCloseDisplay(display);
	return 0;
}

int
Repeated(int tabs, float delay) {
	/*
	GetOptions();
	GetReview();
	GetBlank();
	*/

	blankDef.x = 734;
	blankDef.y = 436;

	optionsDef.x = 793;
	optionsDef.y = 445;

	reviewDef.x = 795;
	reviewDef.y = 486;

	int reps;
	printf("Repetitions: ");
	scanf("%d", &reps);

	sleep(2);

	Display *display = XOpenDisplay(NULL);
	if (display == NULL) {
		fprintf(stderr, "Unable to open display\n");
		return 1;
	}   Window root = DefaultRootWindow(display);

	for (int i = 0; i < reps; ++i) {
		Click(optionsDef, reviewDef, blankDef, tabs, display, root); usleep(delay * 10000);
		Key(tabs, display); usleep(10000);
	}
	XCloseDisplay(display);
	return 0;
} 

void
Click(POINT options, POINT review, POINT blank, int tabs, Display *display, Window root) {

}

void
Key(int tabs, Display *display) {

}
