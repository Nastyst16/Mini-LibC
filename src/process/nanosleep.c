// SPDX-License-Identifier: BSD-3-Clause

#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>
#include <time.h>

unsigned int nanosleep(const struct timespec *buf, struct timespec *len)
{
	int ret = syscall(__NR_nanosleep, buf, len);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}


