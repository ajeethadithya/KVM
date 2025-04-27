EXEC = main
SRC = main.c kvm.c mem.c

all:
	@gcc $(SRC) -o $(EXEC)
install: all
	@sudo mv $(EXEC) /usr/local/bin/$(EXEC)
run:
	@if [ ! -f /usr/local/bin/$(EXEC) ]; then \
		echo "Program $(EXEC) is not installed. Please run 'make install' first."; \
	else \
		/usr/local/bin/$(EXEC); \
	fi
clean:
	@sudo rm -f /usr/local/bin/$(EXEC)
uninstall: clean
