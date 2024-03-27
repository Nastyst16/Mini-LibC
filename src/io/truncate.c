// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */
	int trct = syscall(__NR_truncate, path, length);
	if (trct < 0) {
		errno = -trct;
		return -1;
	}

	return trct;
}
