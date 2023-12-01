CC = gcc
OBJS = main.c kuznechik.c
NAME = main

all:
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -rf $(NAME) *.o