static	char	rcsid[] = "$Id$" ;

#include <stdio.h>

#include <X11/StringDefs.h>
#include <X11/Intrinsic.h>
#include <X11/Core.h>
#include <X11/Object.h>
#include <X11/Shell.h>

#include <X11/Xaw/Box.h>
#include <X11/Xaw/Form.h>
#include <X11/Xaw/Label.h>
#include <X11/Xaw/Command.h>
#include <X11/Xaw/AsciiText.h>

#include "Frame.h"

	/* X11 stuff */

static	Display	*dpy ;
static	Atom	wm_protocols ;
static	Atom	wm_delete_window ;

	/* Xt stuff */

static	XtAppContext	app_ctx ;

static	Widget	topLevel, yesFrame, noFrame, yesBut, noBut ;

static String fallback[] = {
	"*background:		gray",
	"*mainPanel.width:	500",
	"*mainPanel.height:	300",
	"*sampleBox.height:	100",
	"*sampleBox.border:	black",
	NULL
};

static	void	FrameDemo() ;

static	void	WMProtocols(Widget, XEvent *, String *, Cardinal *) ;

static	void	CommandCB(Widget cmd, XtPointer client, XtPointer data) ;


	/* define global actions table for the application.  This is done
	 * to catch messages.  This could also be done through the main
	 * event loop if we wrote one.  It would be nice if Xt had a way
	 * of regestering a callback proc for specific kinds of events.
	 */

XtActionsRec	fd_actions[] = {
    {"WMProtocols", WMProtocols},
} ;

main(int argc, char **argv)
{
	/* this could all be done with a single call to XtAppInitialize(),
	 * but I'm spelling it out for illustration purposes.
	 */

	XtToolkitInitialize() ;
	app_ctx = XtCreateApplicationContext() ;
	XtAppSetFallbackResources(app_ctx, fallback) ;
	dpy = XtOpenDisplay(app_ctx, NULL, "framedemo", "Framedemo",
		NULL, 0, &argc, argv) ;
	topLevel = XtVaAppCreateShell("framedemo", "Framedemo",
		applicationShellWidgetClass, dpy,
		0) ;

	XtAppAddActions(app_ctx, fd_actions, XtNumber(fd_actions));

	FrameDemo() ;

	XtRealizeWidget(topLevel) ;

	/* tell window system we're willing to handle window-delete messages */
	wm_protocols = XInternAtom(dpy, "WM_PROTOCOLS", False);
	wm_delete_window = XInternAtom(dpy, "WM_DELETE_WINDOW", False);
	(void) XSetWMProtocols(dpy, XtWindow(topLevel), &wm_delete_window,1);

	XtAppMainLoop(app_ctx) ;

	exit(0) ;
	/* NOTREACHED */
}



static	void
FrameDemo()
{
	Widget	marginFrame, mainFrame ;
	Widget	form ;
	Widget	fm, lbl ;

	marginFrame = XtVaCreateManagedWidget("marginframe", frameWidgetClass,
		topLevel, 0) ;

	mainFrame = XtVaCreateManagedWidget("mainframe", frameWidgetClass,
		marginFrame, 0) ;

	form = XtVaCreateManagedWidget("form", formWidgetClass,
		mainFrame, 0) ;

	fm = XtVaCreateManagedWidget("frame1", frameWidgetClass, form, 0) ;
	lbl = XtCreateManagedWidget("lbl", labelWidgetClass, fm, NULL, 0) ;

	fm = XtVaCreateManagedWidget("frame2", frameWidgetClass, form, 0) ;
	lbl = XtCreateManagedWidget("lbl", labelWidgetClass, fm, NULL, 0) ;

	fm = XtVaCreateManagedWidget("frame3", frameWidgetClass, form, 0) ;
	lbl = XtCreateManagedWidget("lbl", labelWidgetClass, fm, NULL, 0) ;

	fm = XtVaCreateManagedWidget("frame4", frameWidgetClass, form, 0) ;
	lbl = XtCreateManagedWidget("lbl", labelWidgetClass, fm, NULL, 0) ;

	fm = XtVaCreateManagedWidget("frame5", frameWidgetClass, form, 0) ;
	lbl = XtCreateManagedWidget("lbl", labelWidgetClass, fm, NULL, 0) ;

	fm = XtVaCreateManagedWidget("frame6", frameWidgetClass, form, 0) ;
	lbl = XtCreateManagedWidget("lbl", labelWidgetClass, fm, NULL, 0) ;

	fm = XtVaCreateManagedWidget("frame7", frameWidgetClass, form, 0) ;
	lbl = XtCreateManagedWidget("lbl", labelWidgetClass, fm, NULL, 0) ;

	fm = XtVaCreateManagedWidget("frame8", frameWidgetClass, form, 0) ;
	lbl = XtCreateManagedWidget("lbl", labelWidgetClass, fm, NULL, 0) ;

	fm = XtVaCreateManagedWidget("frame9", frameWidgetClass, form, 0) ;
	lbl = XtCreateManagedWidget("lbl", labelWidgetClass, fm, NULL, 0) ;

	fm = XtVaCreateManagedWidget("framen", frameWidgetClass, form, 0) ;
	fm = XtVaCreateManagedWidget("framen2", frameWidgetClass, fm, 0) ;
	fm = XtVaCreateManagedWidget("framen3", frameWidgetClass, fm, 0) ;
	lbl = XtCreateManagedWidget("lbl", labelWidgetClass, fm, NULL, 0) ;

	yesFrame =
	  XtVaCreateManagedWidget("frame10", frameWidgetClass, form, 0) ;
	yesBut =
	  XtCreateManagedWidget("Yes", commandWidgetClass, yesFrame, NULL, 0) ;
	XtAddCallback(yesBut, XtNcallback, CommandCB, NULL) ;

	noFrame =
	  XtVaCreateManagedWidget("frame11", frameWidgetClass, form, 0) ;
	noBut =
	  XtCreateManagedWidget("No", commandWidgetClass, noFrame, NULL, 0) ;
	XtAddCallback(noBut, XtNcallback, CommandCB, NULL) ;
}





/* ARGSUSED */
static	void
WMProtocols(w, ev, params, nparams)
	Widget	w ;
	XEvent	*ev ;
	String	*params ;
	Cardinal *nparams ;
{
	if( ev->type == ClientMessage  &&
	    ev->xclient.message_type == wm_protocols  &&
	    ev->xclient.data.l[0] == wm_delete_window )
	{
	  if( w == topLevel )
	    exit(0) ;
	}
}


static	void
CommandCB(Widget cmd, XtPointer client, XtPointer data)
{
	if( cmd == yesBut ) {
	  XtVaSetValues(yesFrame, XtNshadowStyle, Lowered, 0) ;
	  XtVaSetValues(noFrame, XtNshadowStyle, Blank, 0) ;
	}
	else {
	  XtVaSetValues(yesFrame, XtNshadowStyle, Blank, 0) ;
	  XtVaSetValues(noFrame, XtNshadowStyle, Lowered, 0) ;
	}
}
