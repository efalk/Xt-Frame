/* $Id: FrameP.h,v 1.1 1998/10/09 17:11:12 falk Exp falk $
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
    XtShadowStyle style ;
    Dimension	shadowWidth ;
    Pixel	foreground ;
    String	label ;
    XFontStruct	*font ;
    XtJustify	justify ;
    Dimension   internalHeight, internalWidth ;
    Boolean	allowResize ;
    Boolean	be_nice_to_cmap ;
    int		top_shadow_contrast ;
    int		bot_shadow_contrast ;
    int		insensitive_contrast ;

    /* private state */
    GC		foregroundGC ;
    GC		backgroundGC ;
    GC		greyGC ;
    GC		topGC ;
    GC		botGC ;
    Pixmap	grey50 ;		/* TODO: cache this elsewhere */
    Boolean	needs_layout ;
    Position	lx,ly ;			/* label posn */
    Position	sy,sh ;			/* shadow position, height */
    XRectangle	lblBg ;			/* region behind label to clear */
} FramePart;


typedef struct _FrameRec {
    CorePart		core;
    CompositePart	composite;
    FramePart		frame;
} FrameRec;



#endif /* _FrameP_h */
