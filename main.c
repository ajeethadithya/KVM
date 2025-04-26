#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "kvm.h"

int main(void) {
	int kvm_fd, vm_fd, vcpu_fd;
	int api_version;
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

	vcpu_fd = kvm_create_vcpu(vm_fd);
	if(vcpu_fd < 0) {
		perror("Failed to create a VCPU");
		goto out;
	}	


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
	return rc;
}
