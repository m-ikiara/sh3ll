CC := gcc

IncDIR := ./include
CFLAGS := -g -O3 -Wall -Wextra -pedantic -std=c11 -lmingw32
IncFLAGS := $(addprefix -I,$(IncDIR))

NAME := sh3ll

# SRC := $(wildcard ./src/*.c)
SRC := ./src/main.c

.PHONY: all clean strip

all: target

target: $(SRC)
	$(CC) $(CFLAGS) $(IncFLAGS) $< -o $(NAME)

clean:
	rm -f $(NAME)

strip:
	strip --strip-all $(NAME)
