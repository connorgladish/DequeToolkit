CC = g++
CFLAGS = -std=c++17 -Wall -Wextra
TARGET = deque

all: $(TARGET)

$(TARGET): main.o deque.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o deque.o

main.o: main.cpp deque.h
	$(CC) $(CFLAGS) -c main.cpp

deque.o: deque.cpp deque.h
	$(CC) $(CFLAGS) -c deque.cpp

clean:
	rm -f *.o $(TARGET)
