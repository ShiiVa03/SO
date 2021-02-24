CC=gcc
CFLAGS= -O2 -Wall
DEPS = guiao0funcs.h
OBJ = guiao0.o guiao0funcs.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	-rm -f *.o
