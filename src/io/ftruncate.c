// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	int ftrct = syscall(__NR_ftruncate, fd, length);
	if (ftrct < 0) {
		errno = -ftrct;
		return -1;
	}

	return ftrct;
}
