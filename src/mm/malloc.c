// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *allocate_memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (allocate_memory == MAP_FAILED) {
		return NULL;
	}
	mem_list_add(allocate_memory, size);
	return allocate_memory;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *allocate_memory = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	char *ptr = allocate_memory;
	for (size_t i = 0; i < nmemb * size; i++)
		ptr[i] = 0;

	mem_list_add(allocate_memory, nmemb * size);
	return allocate_memory;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	struct mem_list *mem = mem_list_find(ptr);
	munmap(ptr, mem->len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	// searching for the memory block
	struct mem_list *mem = mem_list_find(ptr);
	// if the size is smaller than the current size, we don't need to do anything
	if (mem->len >= size)
		return ptr;
	// if the size is bigger than the current size, we need to allocate a new memory block
	void *allocate_memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	// if the allocation failed, we return NULL
	if (allocate_memory == MAP_FAILED) {
		return NULL;
	}
	// copy the data from the old memory block to the new one
	memcpy(allocate_memory, ptr, mem->len);
	// unmap the old memory block
	mem_list_del(ptr);
	mem_list_add(allocate_memory, size);
	return allocate_memory;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	return mremap(ptr, 0, nmemb * size, 0);
}
