#include "gtkfraktal.h"


int main(int argc, char *argv[]){
    struct f_param frakt;
    fraktal_init_with_default( &frakt );
                    
    CallbackObject *callobj;
    GError *error = NULL;
    GtkWidget *window;
    
    gtk_init(&argc, &argv);
    
    callobj = g_malloc( sizeof(CallbackObject) );
    callobj->pixbuf             = NULL;
    callobj->rgb                = NULL;
    callobj->builder            = gtk_builder_new ();
    callobj->frakt              = &frakt;
    callobj->press              = FALSE;
    
    gtk_builder_add_from_file ( callobj->builder, PATHGUI, &error );
    gtk_builder_connect_signals ( callobj->builder, callobj );
    
    window = GTK_WIDGET( 
        gtk_builder_get_object( callobj->builder, MAINWINDOW ));
    
    callobj->zeichenflaeche = GTK_WIDGET( 
        gtk_builder_get_object(callobj->builder, DRAWAREA ));
    gtk_widget_add_events(  GTK_WIDGET(callobj->zeichenflaeche),
                            GDK_SCROLL_MASK | 
                            GDK_BUTTON_PRESS_MASK | 
                            GDK_BUTTON_RELEASE_MASK |
                            GDK_POINTER_MOTION_MASK);
    gtk_widget_set_size_request(    callobj->zeichenflaeche, 
                                    FRAKTAL_WIDTH, 
                                    FRAKTAL_HEIGHT );
    
    gtk_widget_show_all(window);
    gtk_main();
    
    return EXIT_SUCCESS;
}
