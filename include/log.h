#ifndef _LOG_H_
#define _LOG_H_

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define INFO(...)                                                               \
    do {                                                                     \
        fprintf(stderr,"%s:%s:%d: ", __FILE__, __func__, __LINE__);         \
        fprintf(stderr,__VA_ARGS__);                                         \
        fprintf(stderr,"\n");                                                \
    } while (0);

#define DEBUG(...)                                                       \
do {                                                                     \
    fprintf(stderr,"%s:%s:%d: ", __FILE__, __func__, __LINE__);         \
    fprintf(stderr,__VA_ARGS__);                                         \
    fprintf(stderr,"\n");                                                \
} while (0);

#endif