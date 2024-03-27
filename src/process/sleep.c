// SPDX-License-Identifier: BSD-3-Clause

#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec ts = {seconds, 0};
    struct timespec rem = {0, 0};
    int ret = nanosleep(&ts, &rem);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}
