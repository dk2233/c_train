$CC =gcc

INC_FOLDER=arrays

CFLAGS = -Iarrays

#VPATH = arrays

vpath %.c ./ arrays/
obj= main.o array_func.o

test: $(obj)
	cc $(CFLAGS) -o test $(obj) 

#array_func.o: array_func.c
