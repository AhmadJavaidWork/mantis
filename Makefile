CC = gcc
CFLAGS = -g
DEPS = lexer.h
OBJ = main.o lexer.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
	
mantis: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^