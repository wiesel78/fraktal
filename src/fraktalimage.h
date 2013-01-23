#ifndef __FRAKTALIMAGE_H__
#define __FRAKTALIMAGE_H__

#include "fraktalinit.h"
#include "fraktalimageprofiles.h"


void fraktal_image_set_pixel( char *, char *, int );

void fraktal_image_set_rgb( struct f_param *, char *,
                            void (*)(char *, int, int) );
                                
#endif
