#ifndef _H_INPUT_
    #define _H_INPUT_
    void input_uint_mv(const char* str_lbl,unsigned int *val,const unsigned int valmax,const char* str_err);
    void input_choice(unsigned int *choice,const unsigned int nb_elem);
    void input_float(const char* label,float *nb);
#endif
