// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	va_list args;
	va_start(args, flags);
	int next_arg = va_arg(args, int);
	va_end(args);

	int file;

	if (next_arg != 0)
		file = syscall(__NR_open, filename, flags, next_arg);
	else
		file = syscall(__NR_open, filename, flags);

	if (file < 0) {
		errno = -file;
		return -1;
	}

	return file;
}
