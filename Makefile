CC=gcc
OBJECTS=request.o response.o test.o
PROGRAM=test
CFLAGS=-g -Wall -I/usr/local/include
# LIBS=-L/usr/local/lib -lpcre

all: $(PROGRAM)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAM): taiga.h $(OBJECTS)
	gcc -static $(OBJECTS) -o $(PROGRAM) /usr/local/lib/libpcre.a

clean:
	rm -f *.o $(PROGRAM)
