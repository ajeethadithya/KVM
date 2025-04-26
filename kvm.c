#include <stdio.h>
#include <sys/ioctl.h>
#include <linux/kvm.h>
#include "kvm.h"

int kvm_api_version(int kvm_fd) {
        int api_version;
        api_version = ioctl(kvm_fd, KVM_GET_API_VERSION, NULL);
        return api_version;
}

int kvm_create_vm(int kvm_fd) {
	int vm_fd;
	vm_fd = ioctl(kvm_fd, KVM_CREATE_VM, ARCH_X86);
	return vm_fd;
}

int kvm_create_vcpu(int vm_fd) {
	int vcpu_fd;
	vcpu_fd = ioctl(vm_fd, KVM_CREATE_VCPU, 0);
	return vcpu_fd;
}



