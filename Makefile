SRCS=$(wildcard *.c)

PROGS=$(addprefix bin/, $(patsubst %.c,%,$(SRCS)))

all: $(PROGS)

bin/%: %.c
	gcc -o $@ $< -lpanel -lcurses

