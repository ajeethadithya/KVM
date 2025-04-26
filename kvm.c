#include <stdio.h>
#include <sys/ioctl.h>
#include <linux/kvm.h>
#include "kvm.h"

int get_api_version(int kvm_fd) {
        int api_version;
        api_version = ioctl(kvm_fd, KVM_GET_API_VERSION, NULL);
        return api_version;
}

