#ifndef _H_CALC_
	#define _H_CALC_
	extern float calc_add(const float f1,const float f2);
	extern float calc_sub(const float f1,const float f2);
	extern float calc_mult(const float f1,const float f2);
	float calc_div(const float f1,const float f2);
	float calc_abs(const float f1,const float f2);

	typedef enum { // le enum est impl�ment� pour pouvoir �ventuellement utiliser �a autrepart / augmenter maintenabilit� [l'assignation de valeurs est aussi l� pour augmenter lisibilit�]
        ADD=1,
        SUB=2,
        MULT=3,
        DIV=4
    } calc_enum;
    void calc(const calc_enum sel);
#endif
