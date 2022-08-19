CFLAGS = -s
CC = gcc

deformat:deformat.c 
	$(CC) deformat.c $(CFLAGS) -o deformat

clean: deformat 
	rm deformat
