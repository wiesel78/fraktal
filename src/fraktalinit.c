#include "fraktalinit.h"

/*
 * Initalization of Fraktal_Parameter_Struct
 * */ 
void fraktal_init(  struct f_param *frakt, 
                    int (*fraktal_profile)(double, double, double, int),
                    double cx,          double cy, 
                    double c_width,     double c_height,
                    int width,          int height, 
                    double quad_max,    int iter_max){
                        
    (*frakt).cx         = cx;
    (*frakt).cy         = cy;
    (*frakt).c_width    = c_width;
    (*frakt).c_height   = c_height;
    
    (*frakt).cx_min     = FRAKTAL_C_MIN(cx, c_width);
    (*frakt).cx_max     = FRAKTAL_C_MAX(cx, c_width);
    (*frakt).cy_min     = FRAKTAL_C_MIN(cy, c_height);
    (*frakt).cy_max     = FRAKTAL_C_MAX(cy, c_height);
    
    (*frakt).width      = width;
    (*frakt).height     = height;
    
    (*frakt).quad_max   = quad_max;
    (*frakt).iter_max   = iter_max;
    (*frakt).cx_res     = FRAKTAL_RESOLUTION(c_width, width);
    (*frakt).cy_res     = FRAKTAL_RESOLUTION(c_height, height);
    
    (*frakt).fraktal_profile = fraktal_profile;
}

void fraktal_init_with_default (struct f_param *frakt){
    fraktal_init(   frakt, 
                    FRAKTAL_PROFILE,
                    FRAKTAL_CX, FRAKTAL_CY, 
                    FRAKTAL_C_WIDTH, FRAKTAL_C_HEIGHT, 
                    FRAKTAL_WIDTH, FRAKTAL_HEIGHT, 
                    FRAKTAL_QUAD_MAX, FRAKTAL_ITER_MAX);
    
    (*frakt).values = NULL;
}

void fraktal_reinit ( struct f_param *frakt){
    fraktal_init(   frakt,
                    (*frakt).fraktal_profile,
                    (*frakt).cx, (*frakt).cy,
                    (*frakt).c_width, (*frakt).c_height,
                    (*frakt).width, (*frakt).height,
                    (*frakt).quad_max, (*frakt).iter_max);
}

/* Destroy the Values element of Fraktal_Param_Struct */
void fraktal_destroy(struct f_param *frakt){
    if((*frakt).values){
        free((*frakt).values);
    }
}
