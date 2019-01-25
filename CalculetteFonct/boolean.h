#ifndef _H_BOOLEAN_
	#define _H_BOOLEAN_
	typedef unsigned char boolean;
	#ifndef __cplusplus
		#undef true
		#undef false
		#define true    1
		#define false   0
	#endif
#endif
