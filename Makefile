all:
	@gcc main.c kvm.c -o main
	@echo "Successfully compiled!"
run:
	@./main
clean:
	@rm -f main
