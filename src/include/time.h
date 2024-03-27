#ifndef	__TIME_H__
#define	__TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

struct timespec {
    long long tv_sec;
    long long tv_nsec;
};

unsigned int nanosleep(const struct timespec *buf, struct timespec *len);

#ifdef __cplusplus
}
#endif

#endif
