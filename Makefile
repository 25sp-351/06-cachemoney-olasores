CC = gcc
CFLAGS = -Wall -Wextra -g
SOURCES = main.c numeric.c memoize.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = money_converter

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

test_memo: test_memoize.o memoize.o numeric.o
	$(CC) test_memoize.o memoize.o numeric.o -o test_memo

test: test_memo
	./test_memo

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) test_memo test_memoize.o