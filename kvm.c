#include <stdio.h>
#include <stdlib.h>
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

void kvm_print_vcpu_regs(struct kvm_regs* regs) {
	
	printf("---------------\n");
	printf("vCPU Registers:\n");
	printf("---------------\n");
	printf("rax: 0x%llx\n", regs->rax);
	printf("rbx: 0x%llx\n", regs->rbx);
	printf("rcx: 0x%llx\n", regs->rcx);
	printf("rdx: 0x%llx\n", regs->rdx);
	printf("rsi: 0x%llx\n", regs->rsi);
	printf("rdi: 0x%llx\n", regs->rdi);
	printf("rsp: 0x%llx\n", regs->rsp);
	printf("\n");
	printf("rip: 0x%llx\n", regs->rip);
	printf("rflags: 0x%llx\n", regs->rflags);
	// printf("cs: 0x%lx\n", regs->cs);
	// printf("ss: 0x%lx\n", regs->ss);
	printf("---------------\n");
}

struct kvm_regs* kvm_get_vcpu_regs(int vcpu_fd) {
	
	struct kvm_regs* regs;

	regs = malloc(sizeof(struct kvm_regs));
	if(regs == NULL) {
		return NULL;
	}
	else if (ioctl(vcpu_fd, KVM_GET_REGS, regs) < 0) {
		return NULL;
	}
	return regs;
}

/*
struct kvm_sregs kvm_get_vcpu_sregs(int vcpu_fd) {
	

}
*/



