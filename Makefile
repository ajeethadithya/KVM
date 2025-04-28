EXEC = main
SRC = main.c kvm.c mem.c

all: clean
	@gcc $(SRC) -o $(EXEC)
	@sudo mv $(EXEC) /usr/local/bin/$(EXEC)

install: all

run:
	@if [ ! -f /usr/local/bin/$(EXEC) ]; then \
		echo "Program $(EXEC) is not installed. Please run 'make' or 'make install' first."; \
	else \
		/usr/local/bin/$(EXEC); \
	fi

clean:
	@sudo rm -f /usr/local/bin/$(EXEC)

uninstall: clean
