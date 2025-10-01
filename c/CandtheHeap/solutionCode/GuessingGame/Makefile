CC = gcc # This is my compiler
CFLAGS = -Wall
CFILES = GuessingGamePart3.c 

all: myprogram 

myprogram: 
	$(CC) $(CFLAGS) $(CFILES) GuessingGameDriver.c -o game.out 

test:
	$(CC) $(CFLAGS) $(CFILES) TestDriver.c -o tests.out

clean:
	rm *.out