#ifndef KVM_H
#define KVM_H

#include <linux/kvm.h>

#define PAGE_SIZE 4096
#define ARCH_X86 0

extern struct kvm_userspace_memory_region region;

int kvm_api_version(int kvm_fd);
int kvm_create_vm(int kvm_fd);
int kvm_create_vcpu(int vm_fd);
int kvm_initialize_region(int vm_fd, void* guest_addr);
struct kvm_regs* kvm_get_vcpu_regs(int vcpu_fd);
struct kvm_sregs* kvm_get_vcpu_sregs(int vcpu_fd);
void kvm_print_vcpu_regs(struct kvm_regs* regs, struct kvm_sregs* sregs);

#endif
