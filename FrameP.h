/* $Id: FrameP.h,v 1.1 1998/10/12 01:33:20 falk Exp falk $
 *
 * FrameP.h - Private definitions for Frame widget
 * 
 */

#ifndef _FrameP_h
#define _FrameP_h

/***********************************************************************
 *
 * Frame Widget Private Data
 *
 ***********************************************************************/

#include <X11/IntrinsicP.h>
#include "Frame.h"

/* New fields for the Frame widget class record */
typedef struct {XtPointer extension;} FrameClassPart;

/* Full class record declaration */
typedef struct _FrameClassRec {
    CoreClassPart	core_class;
    CompositeClassPart  composite_class;
    FrameClassPart	frame_class;
} FrameClassRec;

extern FrameClassRec frameClassRec;



/****************************************************************
 *
 * instance record declaration
 *
 ****************************************************************/

/* New fields for the Frame widget record */
typedef struct {
    /* resources */
    XtShadowType type ;
    Dimension	shadowWidth ;
    Pixel	foreground ;
    Widget	title ;
    XtJustify	justify ;
    Dimension   marginHeight, marginWidth ;
    Boolean	allowResize ;
    Boolean	be_nice_to_cmap ;
    int		top_shadow_contrast ;
    int		bot_shadow_contrast ;

    /* private state */
    GC		foregroundGC ;		/* for solid borders */
    GC		topGC ;
    GC		botGC ;
    Boolean	needs_layout ;
    Position	tx,ty ;			/* title posn */
    Position	sy,sh ;			/* shadow position, height */
} FramePart;


typedef struct _FrameRec {
    CorePart		core;
    CompositePart	composite;
    FramePart		frame;
} FrameRec;



#endif /* _FrameP_h */
