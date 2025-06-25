#include <X11/X.h>
#include <X11/Xatom.h>
#include <X11/Xcms.h>
#include <X11/Xlib.h>
#include <X11/Xresource.h>
#include <X11/Xutil.h>
#include <X11/cursorfont.h>
#include <X11/keysym.h>
#include <X11/keysymdef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "util.h"

#define VERSION 0.1

#define MODKEY Mod1Mask
#define SUPER Mod4Mask

static Display *dpy;
static Window root;
static int scr;

void grabKey(char *key, unsigned int mod) {
	KeySym sym   = XStringToKeysym(key);
	KeyCode code = XKeysymToKeycode(dpy, sym);
	XGrabKey(dpy, code, mod, root, false, GrabModeAsync, GrabModeAsync);
	XSync(dpy, false);
}
static Window create_win(int x, int y, int width, int height, int border) {
	Window win;
	XSetWindowAttributes xwa;

	xwa.background_pixel = WhitePixel(dpy, scr);
	xwa.border_pixel     = BlackPixel(dpy, scr);
	xwa.event_mask       = ButtonPressMask;

	win = XCreateWindow(dpy, root, x, y, width, height, border, DefaultDepth(dpy, scr), InputOutput, DefaultVisual(dpy, scr), CWBackPixel | CWBorderPixel | CWEventMask, &xwa);
	return win;
}
int main(int argc, char *argv[]) {
	if (argc > 1 && (!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version"))) {
		die("sdwm VERSION 0.1:");
	}
	parse();
	Window win;
	dpy = XOpenDisplay(NULL);
	ptr_check(dpy);

	scr  = DefaultScreen(dpy);
	root = RootWindow(dpy, scr);

	XSelectInput(dpy, root, SubstructureRedirectMask | SubstructureNotifyMask);
	XSync(dpy, 0);

	XEvent ev;
	win = create_win(500, 500, 500, 500, 15);
	XMapWindow(dpy, win);

	bool run = true;
	while (XNextEvent(dpy, &ev) == 0 && run == true) {
		switch (ev.type) {
			case ButtonPress:
				run = false;
				break;
		}
		XSync(dpy, 0);
	}
	XUnmapWindow(dpy, win);
	XDestroyWindow(dpy, win);
	XCloseDisplay(dpy);
	return 0;
}
