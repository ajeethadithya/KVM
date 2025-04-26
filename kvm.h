#ifndef KVM_H
#define KVM_H

#define PAGE_SIZE 4096
#define ARCH_X86 0

int kvm_api_version(int kvm_fd);
int kvm_create_vm(int kvm_fd);
int kvm_create_vcpu(int vm_fd);

#endif
