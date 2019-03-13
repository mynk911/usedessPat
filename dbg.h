#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef WIN32
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#else
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

#ifdef NDEBUG 
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "[DEBUG] (%s:%d) " M "\n", \
__FILENAME__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "NONE" : strerror(errno))

#define log_err(M, ...) fprintf(stderr,\
"[ERROR] (%s:%s:%d: errno: %s) " M "\n", __FILENAME__, __func__ , __LINE__,\
clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr,\
"[WARN] (%s:%s:%d: errno: %s) " M "\n", __FILENAME__, __func__, __LINE__,\
clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr,\
"[INFO] (%s:%s:%d) " M "\n", __FILENAME__, __func__, __LINE__, ##__VA_ARGS__)

#define check(A, M, ...) if(!(A)) {\
log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__);\
errno=0; goto error;}

#define check_mem(A) check(A, "Out of memory.")

#define check_debug(A, M, ...) if(!(A)) {\
debug(M, ##__VA_ARGS__); errno=0; goto error;}

#endif
