#ifndef __FRAKTALINIT_H__
#define __FRAKTALINIT_H__

#include <stdio.h>
#include <stdlib.h>
#include "fraktalprofiles.h"

#define FRAKTAL_WIDTH 640
#define FRAKTAL_HEIGHT 580

#define FRAKTAL_CX -0.6
#define FRAKTAL_CY 0.0
#define FRAKTAL_C_WIDTH 3.2
#define FRAKTAL_C_HEIGHT 2.8

#define FRAKTAL_QUAD_MAX 4.0
#define FRAKTAL_ITER_MAX 1000
#define FRAKTAL_ZOOM 20.0

#define FRAKTAL_PROFILE fraktal_profile_mandel

#define BETRAG(min,max) ((min) < (max)) ? ((max)-(min)) : ((min)-(max))
#define PROZENT(m,p) ( ((m)*(p)) / (100.0) )
#define MINIMUM(a,b) ( ((a) < (b)) ? (a) : (b))
#define MAXIMUM(a,b) ( ((a) > (b)) ? (a) : (b))

#define FRAKTAL_RESOLUTION(c,x) ((c)/(x))
#define FRAKTAL_C_MIN(c,m) ((c) - ((m)/2.0))
#define FRAKTAL_C_MAX(c,m) ((c) + ((m)/2.0))
#define FRAKTAL_PTOU(p,cres) ((cres) * (p))
#define FRAKTAL_CPOSBYPIX(cmin, cres, p) ((cmin) + ( (cres) * (p) ))
#define FRAKTAL_ZOOMIN(max,zoom) ((max) - (PROZENT((max),(zoom))))
#define FRAKTAL_ZOOMOUT(max,zoom) ((max) + (PROZENT((max),(zoom))))


/*
 * Fraktal Parameter struct
 * */
struct f_param {
    double cx, cy, c_width, c_height;
    double cx_min, cx_max;
    double cy_min, cy_max;
    double cx_res, cy_res;
    double resolution;
    double quad_max;
    int width, height;
    int iter_max;
    int *values;
    int (*fraktal_profile)(double, double, double, int);
};

void fraktal_init( struct f_param *, 
                   int (*)(double, double, double, int),
                   double, double, double, double, 
                   int, int, double, int );
                   
void fraktal_init_with_default( struct f_param * );
void fraktal_reinit( struct f_param * );
void fraktal_destroy( struct f_param * );

#endif
