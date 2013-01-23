#include "fraktalimage.h"


/* Fraktal setpix by color */
void fraktal_image_set_pixel( char* rgb, 
                              char* farbe, 
                              int pix){
    rgb[3*pix]   = farbe[0];
    rgb[3*pix+1] = farbe[1];
    rgb[3*pix+2] = farbe[2];
}

/* Draw a fraktal picture by Values */
void fraktal_image_set_rgb( struct f_param *frakt, 
                            char *rgb,
                            void (*fraktal_image_profile)(
                                        char *, int, int)){
    char farbe[3];
    int i;
    
    for(i = 0 ; i < (*frakt).width * (*frakt).height ; i++){
        (*fraktal_image_profile)( farbe, 
                                  (*frakt).values[i], 
                                  (*frakt).iter_max);
                            
        fraktal_image_set_pixel(rgb, farbe, i);
    }
}
