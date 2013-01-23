#ifndef __GTKFRAKTALINIT_H__
#define __GTKFRAKTALINIT_H__

#include <gtk/gtk.h>

#define PATHGUI "gui/gui.xml"

#define MAINWINDOW "main-window"
#define DRAWAREA "zeichenflaeche"


typedef struct _CallbackObject
{
    GtkBuilder *builder;
    GtkWidget *zeichenflaeche;
    guchar *rgb;
    GdkPixbuf *pixbuf;
    struct f_param *frakt;
    gint x, y;
    gboolean press;
} CallbackObject;

#endif 
