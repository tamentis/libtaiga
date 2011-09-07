CC=gcc
OBJECTS=response.o test.o
PROGRAM=test
CFLAGS=-g -Wall

all: $(PROGRAM)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAM): taiga.h $(OBJECTS)
	gcc -static $(OBJECTS) -o $(PROGRAM)

clean:
	rm -f *.o $(PROGRAM)
