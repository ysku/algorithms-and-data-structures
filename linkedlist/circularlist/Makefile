CC=gcc
TARGET=circular_list
SOURCES=circular_list.c circular_list_test.c
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
