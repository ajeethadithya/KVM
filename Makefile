all:
	@gcc -o kvm kvm.c
	@echo "Successfully compiled!"
run:
	@./kvm
clean:
	@rm -f kvm
