# example http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
CC=gcc
CFLAGS=-I.
DEPS = common.h
OBJ = main.o
LIBS = -ldl -lm


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

stl2gcode: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm *.o stl2gcode
