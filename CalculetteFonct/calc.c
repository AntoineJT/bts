#include "calc.h"

inline float calc_add(const float f1,const float f2){
    return f1+f2;
}

inline float calc_sub(const float f1,const float f2){
    return f1-f2;
}

inline float calc_abs(const float f1,const float f2){
	float res;
    if(f1>f2)
        res=f1-f2;
    else
        res=f2-f1;
	return res;
}

inline float calc_mult(const float f1,const float f2){
    return f1*f2;
}

inline float calc_div(const float f1,const float f2){
    return f1/f2;
}
