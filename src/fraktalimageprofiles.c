#include "fraktalimageprofiles.h"

/* Fraktal color profiles */
void fraktal_image_profile_std( char* farbe, 
                                int iterations_wert, 
                                int max_iteration){
    if (iterations_wert >= max_iteration)
    {
        farbe[0] = 0;
        farbe[1] = 0;
        farbe[2] = 0;
    }else
    {
        farbe[0] = 255*(max_iteration/iterations_wert);
        farbe[1] = 255*(max_iteration/iterations_wert);
        farbe[2] = 255*(max_iteration/iterations_wert);
    }
}

void fraktal_image_profile_triple( char* farbe, 
                                   int iterations_wert, 
                                   int max_iteration){
    if (iterations_wert >= max_iteration)
    {
        farbe[0] = 0;
        farbe[1] = 0;
        farbe[2] = 0;
    }else if(iterations_wert >= 30){
        farbe[0] = 21;
        farbe[1] = 38;
        farbe[2] = 6;
    }else if(iterations_wert >= 27){
        farbe[0] = 126;
        farbe[1] = 167;
        farbe[2] = 37;
    }else if(iterations_wert >= 23){
        farbe[0] = 214;
        farbe[1] = 226;
        farbe[2] = 88;
    }else if(iterations_wert >= 15){
        farbe[0] = 81;
        farbe[1] = 122;
        farbe[2] = 28;
    }else{
        farbe[0] = 0;
        farbe[1] = 0;
        farbe[2] = 0;
    }
}

