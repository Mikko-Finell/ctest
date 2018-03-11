############## prelude

CC=cc
EXE=test
CFLAGS=-g -Wall -Wextra -ansi -pedantic
#CFLAGS=-std=c99 -O3

############## targets

all: lib install test

lib: libctest.so

# may need to run ldconfig, or change to /usr/lib/
SODIR=/usr/local/lib/
IDIR=/usr/local/include/
install: lib
	cp libctest.so $(SODIR)
	cp ctest.h $(IDIR)

############## test

test: test.o libctest.so
	$(CC) test.o -o $(EXE) -lctest
test.o: test.c
	$(CC) -c test.c $(CFLAGS)

libctest.so: ctest.o
	$(CC) -shared ctest.o -o libctest.so
ctest.o: ctest.c
	$(CC) -c -fpic ctest.c $(CFLAGS)
	
############## misc

clean:
	@rm -rf $(EXE) $(wildcard *.o) $(wildcard *.so)
