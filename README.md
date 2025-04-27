Interacting with the Linux KVM kernel module to create virtual machines.

Work in progress. 

Notes:
Review if 'extern struct kvm_userspace_memory_region region' is necessary

Current setup:
- Blank VM creation
- Create vCPUs
- Get the vCPU registers
- Allocation/deallocation of main memory
- Register the main memory to the VMs address space

To-do:
- Load a simple program
- Run on program the vCPU
- Get a light-weight linux distro
- Load the distro
- Boot initramfs?
- Make program more dynamic and replace hardcoded values.
- Try to boot the linux image
