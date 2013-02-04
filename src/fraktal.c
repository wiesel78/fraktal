#include "fraktal.h"


/** calculate row from x1 to x2 
 *      @param frakt : pointer of a f_param structure
 *      @param row : the number of row
 *      @param x1 : the number of the first pixel to calculate
 *      @param x2 : the number of the last pixel to calculate
 *      @return void
 * */
void fraktal_set_area_row ( 
        struct f_param *frakt, 
        int row, int x1, int x2 ){
    
    double cx, cy;
    int width, x;
    
    cy      = FRAKTAL_CPOSBYPIX( (*frakt).cy_min, (*frakt).cy_res, row);
    width   = (*frakt).width;
    
    for (x = MINIMUM(x1,x2) ; x < MAXIMUM(x1,x2) ; x++){
        cx = FRAKTAL_CPOSBYPIX( (*frakt).cx_min, (*frakt).cx_res, x );
        
        (*frakt).values[width*row+x] = (*(*frakt).fraktal_profile)(
                                            cx, 
                                            cy,
                                            (*frakt).quad_max,
                                            (*frakt).iter_max);
    }
}


/** calculate a area from x1,y1 to x2,y2
 *      @param frakt is pointer of a f_param structure
 *      @param x1 is the x of the top, left point from area
 *      @param y1 is the y of the top, left point from area
 *      @param x2 is the x of the bottom, right point from area
 *      @param y2 is the y of the bottom, right point from area
 *      @return void
 * */
void fraktal_set_area (
        struct f_param *frakt, 
        int x1, int y1, int x2, int y2){
    
    int row;
    
    for(row = MINIMUM(y1,y2) ; row < MAXIMUM(y1,y2) ; row++){
        fraktal_set_area_row ( frakt, row, x1, x2);
    }
}


/** calculate border area after a drag
 *      @param frakt is pointer of a f_param structure
 *      @param xdistance is the border margin of the x axis
 *      @param ydistance is the border margin of the y axis
 *      @return void
 * */
void fraktal_set_area_by_distance (
            struct f_param *frakt,
            int xdistance, int ydistance){
                
    if(ydistance > 0){
        fraktal_set_area(
                frakt, 
                0, 0, 
                (*frakt).width, ydistance );
        if(xdistance > 0){
            fraktal_set_area(
                    frakt, 
                    0, ydistance, 
                    xdistance, (*frakt).height );
        }else{
            fraktal_set_area(
                    frakt, 
                    (*frakt).width + xdistance, ydistance, 
                    (*frakt).width, (*frakt).height );
        }
    }else{
        fraktal_set_area(
                frakt, 
                0, (*frakt).height + ydistance, 
                (*frakt).width, (*frakt).height );
                
        if(xdistance > 0){
            fraktal_set_area(
                    frakt, 
                    0, 0, 
                    xdistance, (*frakt).height + ydistance );
        }else{
            fraktal_set_area(
                    frakt, 
                    (*frakt).width + xdistance, 0, 
                    (*frakt).width, (*frakt).height+ydistance);
        }
    }
}


/** calculate the full area
 *      @param frakt is pointer of a f_param structure
 *      @return void
 * */
void fraktal_set_area_full ( struct f_param *frakt ){
    
    fraktal_set_area( frakt, 0, 0, (*frakt).width, (*frakt).height );
}


/** reserved the required memory and calculate the full area
 *      @param frakt is pointer of a f_param structure
 *      @return void
 * */
int fraktal_set_values( struct f_param *frakt ){
                                            
    if( ((*frakt).values = (int *) malloc(  sizeof(int) * 
                                            (*frakt).width * 
                                            (*frakt).height )) == NULL){
        perror("nicht genuegen speicher");
        return -1;
    }
    
    fraktal_set_area_full( frakt );
    
    return 0;
}


/** Zoom in or out the point of the area by the new coordinate values
 *      @param frakt is pointer of a f_param structure
 *      @param x is the x value of the zoom-point
 *      @param y is the y value of the zoom-point
 *      @param c_width the width in coordinate units of the area
 *      @param c_height the height in coordinate units of the area
 *      @return void
 * */
void fraktal_zoom ( struct f_param *frakt, 
                    int x, int y, 
                    double c_width, double c_height){
    double cx_res, cy_res, cx, cy;
    int px_distance, py_distance;
    
    px_distance = ( x - ((*frakt).width / 2) );
    py_distance = ( y - ((*frakt).height / 2) );
    
    cx_res = FRAKTAL_RESOLUTION( c_width, (*frakt).width );
    cy_res = FRAKTAL_RESOLUTION( c_height, (*frakt).height );
    
    cx = FRAKTAL_CPOSBYPIX( (*frakt).cx_min, (*frakt).cx_res, x );
    cy = FRAKTAL_CPOSBYPIX( (*frakt).cy_min, (*frakt).cy_res, y );
    
    (*frakt).cx = cx - ( px_distance * cx_res );
    (*frakt).cy = cy - ( py_distance * cy_res );
    
    (*frakt).c_width    = c_width;
    (*frakt).c_height   = c_height;
    
    fraktal_reinit( frakt );
}


/** Zoom in the point of the area by a factor of zoom
 *      @param frakt is pointer of a f_param structure
 *      @param x is the x value of the zoom-point
 *      @param y is the y value of the zoom-point
 *      @param zoom is the factor of zoom
 *      @return void
 * */
void fraktal_zoom_in (struct f_param *frakt, int x, int y, double zoom){
    double c_width, c_height;
    
    c_width     = FRAKTAL_ZOOMIN( (*frakt).c_width, zoom );
    c_height    = FRAKTAL_ZOOMIN( (*frakt).c_height, zoom );
    
    fraktal_zoom(frakt, x, y, c_width, c_height);
}


/** Zoom out from a point of the area by a factor of zoom
 *      @param frakt is pointer of a f_param structure
 *      @param x is the x value of the zoom-point
 *      @param y is the y value of the zoom-point
 *      @param zoom is the factor of zoom
 *      @return void
 * */
void fraktal_zoom_out (struct f_param *frakt, int x, int y, double zoom){
    double c_width, c_height;
    
    c_width     = FRAKTAL_ZOOMOUT( (*frakt).c_width, zoom );
    c_height    = FRAKTAL_ZOOMOUT( (*frakt).c_height, zoom );
    
    fraktal_zoom(frakt, x, y, c_width, c_height);
}


/** move a value from frakt.values to a new position
 *      @param frakt is pointer of a f_param structure
 *      @param old is the old position
 *      @param new is the new position
 *      @return void
 * */
void fraktal_drag_value (struct f_param *frakt, int old, int new){
    (*frakt).values[old] = (*frakt).values[new];
}


/** drag the area point left or right and to a new row
 *      @param frakt is pointer of a f_param structure
 *      @param rowold is the row befor the drag
 *      @param rownew is the row to will be drag
 *      @param xdistance is the factor of drag
 *      @return void
 * */
void fraktal_drag_values_horizontal (
            struct f_param *frakt, 
            int rowold, int rownew, int xdistance ){
    
    int x, posnew, posold;
    posold = (*frakt).width*rowold;
    posnew = (*frakt).width*rownew;
    
    if (xdistance > 0){
        for(x = (*frakt).width - 1 ; x >= xdistance ; x--){
            fraktal_drag_value( frakt, posold+x, posnew+(x-xdistance));
        }
    }else{
        for(x = 0 ; x < (*frakt).width + xdistance ; x++){
            fraktal_drag_value( frakt, posold+x, posnew+(x-xdistance));
        }
    }
}


/** drag the area to a new position
 *      @param frakt is pointer of a f_param structure
 *      @param xdistance is the factor of drag (x-axis)
 *      @param ydistance is the factor of drag (y-axis)
 *      @return void
 * */
void fraktal_drag_values (
            struct f_param *frakt,
            int xdistance, int ydistance){
    
    int ro, rn;
    
    if(ydistance > 0){
        for(ro = (*frakt).height-1 ; ro >= ydistance ; ro--){
            rn = ro-ydistance;
            fraktal_drag_values_horizontal(frakt, ro, rn, xdistance);
        }
    }else{
        for(ro = 0 ; ro < (*frakt).height + ydistance ; ro++){
            rn = ro-ydistance;
            fraktal_drag_values_horizontal(frakt, ro, rn, xdistance);
        }
    }
}


/** drag the area to a new position and calculate the free area
 *      @param frakt is pointer of a f_param structure
 *      @param xa is the x value of the first point
 *      @param ya is the y value of the first point
 *      @param xb is the x value of the second point
 *      @param yb is the y value of the second point
 *      @return void
 * */
void fraktal_drag( struct f_param *frakt, 
                   int xa, int ya, int xb, int yb){
    
    int xdistance = xb - xa ;
    int ydistance = yb - ya ;
    
    (*frakt).cx += FRAKTAL_PTOU((*frakt).cx_res, xa - xb);
    (*frakt).cy += FRAKTAL_PTOU((*frakt).cy_res, ya - yb);
    
    fraktal_reinit( frakt );
    
    fraktal_drag_values(frakt, xdistance, ydistance);
    
    fraktal_set_area_by_distance(frakt, xdistance, ydistance);
}





