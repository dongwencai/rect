CC :=gcc -g -Wall
SRC :=$(wildcard *.c)
OBJ :=$(SRC:%.c=%.o)

main:$(OBJ)
	$(CC) -o $@ $^
$(OBJ):%.o:%.c
	$(CC) -c $^ -o $@

clean:
	rm -rf *.o main
