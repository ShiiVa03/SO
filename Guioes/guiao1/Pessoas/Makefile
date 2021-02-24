CC = gcc
CFLAGS = -O2 -Wall
HEADERS = data.h
DEPS = main.o

.PHONY: all clean
all: data

data : $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f data *.o