/* $Id$
 *
 * This widget manages one child widget, placing a decorative border
 * around it.  The frame may have an optional label, which will be placed
 * at the top, breaking the decoration.
 *
 * Border styles are as follow:
 *
 *	None		no border
 *	Solid		solid border in foreground color
 *	Raised		raised 3d look
 *	Lowered		pressed 3d look
 *	Ridge		raised ridge
 *	Groove		indented groove
 *	Trough		indented groove with flat bottom.
 */


#ifndef _Frame_h
#define _Frame_h

#include <X11/Xmu/Converters.h>


/***********************************************************************
 *
 * Frame Widget (subclass of CompositeClass)
 *
 ***********************************************************************/

/* Parameters:

 Name		     Class		RepType		Default Value
 ----		     -----		-------		-------------
 shadowStyle	     ShadowStyle	ShadowStyle	solid
 shadowWidth	     ShadowWidth	Dimension
 foreground	     Foreground		Pixel		XtDefaultForeground
 label		     Label		String		NULL
 font		     Font		XFontStruct*	XtDefaultFont
 justify	     Justify		XtJustify	left
 internalWidth	     Margin		Dimension	0
 internalHeight	     Margin		Dimension	0
 allowResize	     AllowResize	Boolean		True

 beNiceToColormap    BeNiceToColormap	Boolean		False
 topShadowContrast   TopShadowContrast	int		20
 bottomShadowContrast BottomShadowContrast int		40
 insensitiveContrast InsensitiveContrast int		33

 background	     Background		Pixel		XtDefaultBackground
 border		     BorderColor	Pixel		XtDefaultForeground
 borderWidth	     BorderWidth	Dimension	1

 destroyCallback     Callback		Pointer		NULL
 mappedWhenManaged   MappedWhenManaged	Boolean		True
 width		     Width		Dimension	0
 height		     Height		Dimension	0
 x		     Position		Position	0
 y		     Position		Position	0

 Notes:

 1 internalWidth, internalHeight specify the margins around the child widget
 2 allowResize specifies if child widget is allowed to resize itself.
 3 BeNiceToColormap causes the Frame widget to use fewer colors.
 4 InsensitiveContrast sets the contrast used for labels when insensitive

*/

/* New fields */

#ifndef	XtNshadowStyle
#define XtNshadowStyle "shadowStyle"
#define XtCShadowStyle "ShadowStyle"
#define XtRShadowStyle "ShadowStyle"
#endif

#ifndef	XtCAllowResize
#ifndef	XtNallowResize
#define XtNallowResize "allowResize"
#endif
#define XtCAllowResize "AllowResize"
#endif

#ifndef	XtNshadowWidth
#define XtNshadowWidth "shadowWidth"
#define XtCShadowWidth "ShadowWidth"
#define XtNtopShadowPixel "topShadowPixel"
#define XtCTopShadowPixel "TopShadowPixel"
#define XtNbottomShadowPixel "bottomShadowPixel"
#define XtCBottomShadowPixel "BottomShadowPixel"
#define XtNtopShadowContrast "topShadowContrast"
#define XtCTopShadowContrast "TopShadowContrast"
#define XtNbottomShadowContrast "bottomShadowContrast"
#define XtCBottomShadowContrast "BottomShadowContrast"
#endif

#ifndef	XtNinsensitiveContrast
#define	XtNinsensitiveContrast	"insensitiveContrast"
#define	XtCInsensitiveContrast	"InsensitiveContrast"
#endif

#ifndef	XtNtopShadowPixmap
#define	XtNtopShadowPixmap	"topShadowPixmap"
#define	XtCTopShadowPixmap	"TopShadowPixmap"
#define	XtNbottomShadowPixmap	"bottomShadowPixmap"
#define	XtCBottomShadowPixmap	"BottomShadowPixmap"
#endif

#ifndef	XtNbeNiceToColormap
#define XtNbeNiceToColormap "beNiceToColormap"
#define XtCBeNiceToColormap "BeNiceToColormap"
#define XtNbeNiceToColourmap "beNiceToColormap"
#define XtCBeNiceToColourmap "BeNiceToColormap"
#endif

typedef	enum {	Blank,		/* no border */
		Solid,		/* solid border in foreground color */
		Raised,		/* raised 3d look */
		Lowered,	/* pressed 3d look */
		Ridge,		/* raised ridge */
		Groove,		/* indented groove */
		Plateau,	/* raised ridge with flat top */
		Trough}		/* indented groove with flat bottom */
	      XtShadowStyle ;


/* Class record constants */

extern WidgetClass frameWidgetClass;

typedef struct _FrameClassRec	*FrameWidgetClass;
typedef struct _FrameRec	*FrameWidget;

#endif /* _Frame_h */
