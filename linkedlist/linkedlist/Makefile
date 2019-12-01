CC=gcc
TARGET=linked_list
SOURCES=linked_list.c linked_list_test.c
CFLAGS=-O3
LFLAGS=-lm

OBJSC=$(SOURCES:.c=.o)
OBJS=$(OBJSC:.cpp=.o)

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

purge: clean
	rm -f $(TARGET)

clean:
	rm -f *.o
