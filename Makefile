all:
	@gcc main.c kvm.c mem.c -o main
	@echo "Successfully compiled!"
run:
	@./main
clean:
	@rm -f main
