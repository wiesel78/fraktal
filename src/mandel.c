#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "fraktal.h"

#define PICPATH "./apfel.bmp"

int main(int argc, char **argv){
    struct f_param frakt;
    char *rgb;
    
    fraktal_init_with_default(&frakt);
    
    fraktal_set_values(&frakt, fraktal_profile_mandel);
    
    if((rgb = malloc(3*frakt.width*frakt.height*sizeof(char))) == NULL){
        perror("nicht genugend speicher");
        return EXIT_FAILURE;
    }
    
    fraktal_image_set_rgb(&frakt, rgb, fraktal_image_profile_std);
    write_bmp(PICPATH, frakt.width, frakt.height, rgb);
    
    fraktal_destroy(&frakt);
    
    return EXIT_SUCCESS;
}
