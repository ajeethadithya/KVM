#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include "kvm.h"

/*
 * For example, if you open("/path/to/file/") and use mmap, you are telling the kernel:
 * 'Map the contents of this file into memory so I can access it like a pointer'
 * Hence, fd and offset are needed to tell mmap which file and which part to map
 *
 * MAP_ANONYMOUS: You want blank memory, not backed by a file
 * MAP_PRIVATE: Make the memory private to your process
 *
 * fd = -1 and offset = 0 since it is ANONYMOUS here
 * MAP_ANONYMOUS needs to be revisited since we want the memory to be backed by a file
 */

void* mem_alloc() {
	void *mem_addr;
	mem_addr = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if(mem_addr == MAP_FAILED) {
		perror("Memory map failed");
		return NULL;
	}	
	strcpy((char *)mem_addr, "hello from mmap!");
	printf("%s\n", (char *)mem_addr);
	return mem_addr;
}

void mem_dealloc(void *mem_addr) {	
	munmap(mem_addr, PAGE_SIZE);
	printf("Memory deallocated\n");
}



