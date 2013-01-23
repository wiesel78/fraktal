#ifndef __GTKFRAKTALSIGNALS_H__
#define __GTKFRAKTALSIGNALS_H__

#include <gtk/gtk.h>
#include <glib/gprintf.h>
#include "fraktal.h"
#include "gtkfraktalinit.h"
#include "gtkfraktaldraw.h"


gboolean on_draw (  GtkWidget *, 
                    cairo_t *, 
                    CallbackObject * );
                    
gboolean on_configure ( GtkWidget *, 
                        GdkEventConfigure *, 
                        CallbackObject * );
                        
gboolean on_scroll ( GtkWidget *, 
                     GdkEventScroll *, 
                     CallbackObject * );
                     
gboolean on_button_press ( GtkWidget *, 
                           GdkEventButton *, 
                           CallbackObject * );
                           
gboolean on_button_release ( GtkWidget *, 
                             GdkEventButton *, 
                             CallbackObject * );


#endif
