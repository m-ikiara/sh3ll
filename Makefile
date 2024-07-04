CC := gcc

IncDIR := ./include
ObjDIR := ./obj
CFLAGS := -g -O3 -Wall -Wextra -pedantic -std=c11 -lmingw32
IncFLAGS := $(addprefix -I,$(IncDIR))

NAME := sh3ll

SRC := $(wildcard ./src/*.c)
OBJ := $(addprefix $(ObjDIR)/, $(notdir $(SRC:.c=.o)))

.PHONY: all clean strip

all: target

target: $(OBJ)
	$(CC) $(CFLAGS) $(IncFLAGS) $< -o $(NAME)

$(ObjDIR)/%.o: $(SRC)
	mkdir -p $(ObjDIR)
	$(CC) $(CFLAGS) $(IncFLAGS) -c $< -o $@

clean:
	rm -f $(NAME)
	rm -f $(OBJ)

strip:
	strip --strip-unneeded $(NAME) -o $(NAME)
