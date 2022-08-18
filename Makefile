CFLAGS = -s
CC = gcc

uglify:uglify.c 
	$(CC) uglify.c $(CFLAGS) -o uglify

clean: uglify
	rm uglify

run: uglify
	@./uglify
	@rm uglify
	@# I added the '@'s because then its easier to see what the code is doing, versus what 'make' is doing.
