CC = gcc
CFLAGS = -Wall -Wextra -Iincludes -Iutils -Inode -Isentinel -Ilist

SRC_DIRS = utils node sentinel list
SRCS = main.c $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))
OBJS = $(SRCS:.c=.o)

TARGET = main

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
