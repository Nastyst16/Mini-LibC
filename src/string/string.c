// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	for (size_t i = 0; i < strlen(source); i++)
		destination[i] = source[i];

	destination[strlen(source)] = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */

	for (size_t i = 0; i < len; i++)
		destination[i] = source[i];

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int initial_dest_len = strlen(destination);

	for (size_t i = 0; i < strlen(source); i++)
		destination[i + initial_dest_len] = source[i];

	destination[initial_dest_len + strlen(source)] = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	size_t initial_dest_len = strlen(destination);

	for (size_t i = 0; i < len; i++)
		destination[i + initial_dest_len] = source[i];

	destination[len + initial_dest_len] = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	size_t i;
	for (i = 0; i < strlen(str1) || i < strlen(str2); i++) {
		if (str1[i] < str2[i])
			return -1;
		else if (str1[i] == str2[i])
			continue;
		else if (str1[i] > str2[i])
			return 1;
	}

	if (i == strlen(str1) && i == strlen(str2))
		return 0;
	if (i == strlen(str1))
		return -1;
	else if (i == strlen(str2))
		return 1;

	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	for (size_t i = 0; i < len; i++) {
		if (str1[i] < str2[i])
			return -1;
		else if (str1[i] == str2[i])
			continue;
		else if (str1[i] > str2[i])
			return 1;
	}

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	size_t i = -1;
	while (++i < strlen(str))
		if ((int)str[i] == c)
			return (char *)&str[i];

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	size_t i = -1, index = -1;
	while (++i < strlen(str))
		if ((int)str[i] == c)
			index = i;

	if ((int)index != -1)
		return (char *)&str[index];

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	for (size_t i = 0; i < strlen(haystack); i++) {
		size_t j = 0;
		while (j < strlen(needle) && haystack[i + j] == needle[j])
			j++;

		if (j == strlen(needle))
			return (char *)&haystack[i];
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	size_t index = -1;

	for (size_t i = 0; i < strlen(haystack); i++) {
		size_t j = 0;
		while (j < strlen(needle) && haystack[i + j] == needle[j])
			j++;

		if (j == strlen(needle))
			index = i;
	}

	if ((int)index != -1)
		return (char *)&haystack[index];

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = (char *)destination;
    const char *src = (const char *)source;

    for (size_t i = 0; i < num; i++)
        dest[i] = src[i];

    return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *)destination;
    const char *src = (const char *)source;

    for (size_t i = 0; i < num; i++)
        dest[i] = src[i];

    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	size_t i;
	char *p1 = (char *)ptr1;
	char *p2 = (char *)ptr2;
	for (i = 0; i < num; i++)
		if (&p1[i] != &p2[2])
			return 0;

	if (p1[i] < p2[i])
		return -1;
	else
		return 1;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *src = (char *)source;

	for (size_t i = 0; i < num; i++)
		src[i] = value;

	return source;
}
