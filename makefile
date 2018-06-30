CC     = clang++
CFLAGS = -Wall -Wextra -pedantic-errors -std=c++17
LFLAGS = -lstdc++fs
SRCDIR = ./src
BINDIR = ./bin
OBJS   = $(SRCDIR)/*.cpp
NAME   = my_tree

default: $(OBJS)
	$(CC) $^ $(CFLAGS) $(LFLAGS) -o $(BINDIR)/$(NAME)

