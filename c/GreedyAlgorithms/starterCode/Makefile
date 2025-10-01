# Makefile for GreedyAlgo
CC = gcc
CFLAGS = -Wall

SHARED_SRCS = GraphReader.c debug.c

DIJKSTRA_TARGET = dijkstraTest.out
DIJKSTRA_SRCS = adjList.c dijkstra.c testDijkstra.c

all: dijkstra



dijkstra:
	$(CC) $(CFLAGS) -o $(DIJKSTRA_TARGET) $(DIJKSTRA_SRCS) $(SHARED_SRCS)



clean:
	rm -f *.out
