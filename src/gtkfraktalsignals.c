#include "gtkfraktalsignals.h"

gboolean on_draw (  GtkWidget *zeichenflaeche, 
                    cairo_t *cr, 
                    CallbackObject *obj){
    gdk_cairo_set_source_pixbuf (cr, obj->pixbuf, 0, 0);
    cairo_paint(cr);
    
    return TRUE;
}

gboolean on_configure ( GtkWidget *zeichenflaeche,
                        GdkEventConfigure *ereignis,
                        CallbackObject *obj){
    
    (*obj->frakt).width     = ereignis->width;
    (*obj->frakt).height    = ereignis->height;
    
    fraktal_reinit( obj->frakt );
    
    fraktal_destroy( obj->frakt );
    fraktal_set_values( obj->frakt );
                  
    fraktal_gtk_draw(zeichenflaeche, obj);
                            
    return FALSE;
}

gboolean on_scroll ( GtkWidget *zeichenflaeche,
                     GdkEventScroll *ereignis,
                     CallbackObject *obj){
    gint x,y;
    x = ereignis->x;
    y = ereignis->y;
    
    if(ereignis->direction == GDK_SCROLL_UP){
        fraktal_zoomin(obj->frakt, x, y, FRAKTAL_ZOOM);
    }
    
    if(ereignis->direction == GDK_SCROLL_DOWN){
        fraktal_zoomout(obj->frakt, x, y, FRAKTAL_ZOOM);
    }
    
    fraktal_set_area_full( obj->frakt );
    
    fraktal_gtk_draw(zeichenflaeche, obj);
    
    gtk_widget_queue_draw(zeichenflaeche);
    
    return FALSE;
}

gboolean on_button_press ( GtkWidget *zeichenflaeche, 
                           GdkEventButton *event,
                           CallbackObject *obj ){
    if(event->state & GDK_MOD2_MASK){
        obj->x = (int) event->x;
        obj->y = (int) event->y;
        obj->press = TRUE;
    }
    
    return TRUE;
}

gboolean on_button_release ( GtkWidget *zeichenflaeche, 
                             GdkEventButton *event,
                             CallbackObject *obj ){
    if(event->state & GDK_MOD2_MASK){
        obj->press = FALSE;
    }
    
    return TRUE;
}

gboolean on_mouse_move ( GtkWidget *zeichenflaeche,
                         GdkEventMotion *event,
                         CallbackObject *obj ){
    if(obj->press){
        fraktal_drag( obj->frakt, 
                      obj->x, obj->y,
                      (int) event->x, (int) event->y );
        
        fraktal_gtk_draw(zeichenflaeche, obj);
    
        gtk_widget_queue_draw(zeichenflaeche);
        
        obj->x = (int) event->x;
        obj->y = (int) event->y;
    }
    
    
    return FALSE;
}
