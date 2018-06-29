CC     = clang++
CFLAGS = -Wall -pedantic -std =c++17
LFLAGS =
SRCDIR = ./src
BINDIR = ./bin
OBJS   = $(SRCDIR)/*.cpp
Name   = my_tree

default: $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $(BINDIR)/$(NAME)

