#ifndef __GTKFRAKTALDRAW_H__
#define __GTKFRAKTALDRAW_H__

#include <gtk/gtk.h>
#include <glib/gprintf.h>
#include "fraktal.h"
#include "gtkfraktalinit.h"

void fraktal_gtk_draw(GtkWidget *, CallbackObject *);

#endif
