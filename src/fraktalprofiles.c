#include "fraktalprofiles.h"

int fraktal_profile_mandel( double cx, double cy, 
                            double quad_max, 
                            int iter_max){
    double betrag_quadrat = 0;
    int iter = 0;
    double x = 0;
    double y = 0;
    double xt;
    double yt;
    
    while(  betrag_quadrat <= quad_max && iter < iter_max ){
        xt = x * x - y * y + cx;
        yt = 2 * x * y + cy;
        x = xt;
        y = yt;
        iter++;
        betrag_quadrat = x * x + y * y;
    }
    
    return iter;
}
