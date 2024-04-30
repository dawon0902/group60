CC=g++

CFLAGS=-Wall -std=c++11

TARGET=game

all: $(TARGET)

$(TARGET): main.o roulette.o blackjack.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o roulette.o blackjack.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

roulette.o: roulette.cpp
	$(CC) $(CFLAGS) -c roulette.cpp

blackjack.o: blackjack.cpp
	$(CC) $(CFLAGS) -c blackjack.cpp

clean:
	rm -f *.o $(TARGET)
