
ifeq ($(CROSS_COMPILE),)
CC = gcc
else
CC = $(CROSS_COMPILE)gcc
endif

CFLAGS = -Wall -pedantic
.PHONY: clean

writer: writer.o
	$(CC) $(CFLAGS) writer.o -o writer

writer.o: writer.c

clean:
	-rm writer.o writer
