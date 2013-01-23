#include "gtkfraktaldraw.h"

void fraktal_gtk_draw(GtkWidget *zeichenflaeche, CallbackObject *obj){
    gint width, height;
    width   = (*obj->frakt).width;
    height  = (*obj->frakt).height;
    
    if( obj->pixbuf )
        g_object_unref ( obj->pixbuf );
    if( obj->rgb )
        g_free( obj->rgb );
    
    obj->rgb = (guchar *) g_malloc( 3*width*height*sizeof(guchar) );
    
    fraktal_image_set_rgb( obj->frakt, 
                      (char *) obj->rgb, 
                      fraktal_image_profile_std);
    
    obj->pixbuf = gdk_pixbuf_new_from_data(
                            obj->rgb,
                            GDK_COLORSPACE_RGB,
                            FALSE,
                            8,
                            width,
                            height,
                            width * 3,
                            NULL,
                            NULL );
}

