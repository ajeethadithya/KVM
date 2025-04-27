#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "kvm.h"
#include "mem.h"

int main(void) {
	int api_version;
	int kvm_fd, vm_fd, vcpu_fd;
	void *mem_addr;
	struct kvm_regs* regs = NULL;
	struct kvm_sregs* sregs = NULL;
	int rc = EXIT_FAILURE;
	
	printf("Page size: %d\n", PAGE_SIZE);

	kvm_fd = open("/dev/kvm", O_RDWR);
	if(kvm_fd < 0) {
		perror("Failed to open /dev/kvm");
		goto out;
	}

	/* Get the KVM API version */
	api_version = kvm_api_version(kvm_fd);
	if(api_version < 0) {
		perror("Failed to get the API version");
		goto out;
	}

	/* Create a VM */
	vm_fd = kvm_create_vm(kvm_fd);
	if(vm_fd < 0) {
		perror("Failed to create a VM");
		goto out;
	}

	/* Create a vCPU */
	vcpu_fd = kvm_create_vcpu(vm_fd);
	if(vcpu_fd < 0) {
		perror("Failed to create a vCPU");
		goto out;
	}	

	/* Allocate memory using mmap */
	mem_addr = mem_alloc();
	if(mem_addr == NULL) {
		perror("Failed to allocate memory");
		goto out;
	}

	/* Deallocate memory created by mmap */
	mem_dealloc(mem_addr);

	/* Get the generral purpose registers */
	regs = kvm_get_vcpu_regs(vcpu_fd);
	if(regs == NULL) {
		perror("Failed to get the vCPU registers");
		goto out;
	}
	/* Get the vCPU system registers */
        sregs = kvm_get_vcpu_sregs(vcpu_fd);
        if(sregs == NULL) {
                perror("Failed to get the vCPU registers");
                goto out;
        }

	/* Print the vCPU registers */
	kvm_print_vcpu_regs(regs, sregs);

	printf("kvm_fd: %d\n", kvm_fd);
	printf("API version: %d\n", api_version);
	printf("vm_fd: %d\n", vm_fd);
	printf("vcpu_fd: %d\n", vcpu_fd);
	printf("Success\n");
	rc = EXIT_SUCCESS;
out:
	(void)close(kvm_fd);
	(void)close(vm_fd);
	(void)close(vcpu_fd);
	free(regs);
	free(sregs);

	return rc;
}
