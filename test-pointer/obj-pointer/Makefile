# make all 

CC = gcc
CFLAGS = -Wall

DEPS1 = # fbb-obj-pointer.h

OBJ1 = # fbb-obj-pointer.o
OBJ2 = #stack-noobj-pointer.o
OBJ3 = #stack-obj-pointer.o
OBJ4 = stack-obj-type-pointer.o


%.o: %.c $(DEPS1)
	$(CC) $(CFLAGS) -c -o $@ $<

fbb-obj-pointer: $(OBJ1)
	gcc $(CFLAGS) -o $@ $^

stack-noobj-pointer: $(OBJ2)
	gcc $(CFLAGS) -o $@ $^

stack-obj-pointer: $(OBJ3)
	gcc $(CFLAGS) -o $@ $^

stack-obj-type-pointer: $(OBJ4)
	gcc $(CFLAGS) -o $@ $^
	
	
all: stack-obj-type-pointer stack-obj-pointer stack-noobj-pointer fbb-obj-pointer
	touch *.c
		
