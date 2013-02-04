#ifndef __FRAKTAL_H__
#define __FRAKTAL_H__

#include <stdio.h>
#include <stdlib.h>
#include "fraktalinit.h"
#include "fraktalprofiles.h"
#include "fraktalimage.h"


void fraktal_set_area_row ( struct f_param *, int , int , int );
void fraktal_set_area ( struct f_param *, int, int, int, int );
void fraktal_set_area_by_distance ( struct f_param *, int , int );
void fraktal_set_area_full ( struct f_param * );

int fraktal_set_values( struct f_param * );

void fraktal_zoom ( struct f_param *, int, int, double, double );
void fraktal_zoom_in ( struct f_param *, int, int, double );
void fraktal_zoom_out ( struct f_param *, int, int, double );

void fraktal_drag_value (struct f_param *frakt, int , int );
void fraktal_drag_values_horizontal( struct f_param *, int , int, int );
void fraktal_drag_values ( struct f_param *, int , int );
void fraktal_drag( struct f_param *, int, int, int, int);

#endif
