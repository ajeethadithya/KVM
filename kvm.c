#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "kvm.h"

int main(void) {
	
	int kvm_fd;
	int rc = EXIT_FAILURE;
	
	printf("Page size: %d\n", PAGE_SIZE);

	kvm_fd = open("/dev/kvm", O_RDWR);
	if(kvm_fd < 0) {
		perror("Failed to open /dev/kvm");
		goto out;
	}

	
	printf("Success\n");
	rc = EXIT_SUCCESS;
out:
	(void)close(kvm_fd);
	return rc;
}
