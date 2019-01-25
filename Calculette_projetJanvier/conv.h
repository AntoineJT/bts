#ifndef _H_CONV_
    #define _H_CONV_
    extern unsigned int conv_hms2sec(const unsigned int h,const unsigned int m,const unsigned int s);
    void conv_sec2hms(unsigned int *h,unsigned int *m,unsigned int *s);

    typedef enum {
        HMS2S=1,
        S2HMS=2
    } conv_enum;
    void conv(const conv_enum sel);
#endif
