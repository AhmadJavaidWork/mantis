CC = gcc
CFLAGS = -g
DEPS = lexer.h token.h
OBJ = main.o lexer.o token.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
	
mantis: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^