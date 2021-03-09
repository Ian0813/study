


CC=gcc
CFLAGS=-Wall -pthread
SRC_FILES=$(wildcard *.c)
COBJECT=$(patsubst %.c, %.o, $(SRC_FILES))
EXEFILE=$(patsubst %.c, %, $(SRC_FILES))





all:$(COBJECT)
	@for f in $(EXEFILE) ; \
	do \
		$(CC) $(CFLAGS) $$f.c -o $$f ; \
	done
	
clean:
	@rm $(EXEFILE) 

