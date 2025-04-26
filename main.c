#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "kvm.h"

int main(void) {
	int kvm_fd;
	int api_version;
	int rc = EXIT_FAILURE;
	
	printf("Page size: %d\n", PAGE_SIZE_H);

	kvm_fd = open("/dev/kvm", O_RDWR);
	if(kvm_fd < 0) {
		perror("Failed to open /dev/kvm");
		goto out;
	}

	printf("kvm_fd: %d\n", kvm_fd);
	api_version = get_api_version(kvm_fd);
	if(api_version < 0) {
		goto out;
	}
	printf("API version: %d\n", api_version);


	printf("Success\n");
	rc = EXIT_SUCCESS;
out:
	(void)close(kvm_fd);
	return rc;
}
