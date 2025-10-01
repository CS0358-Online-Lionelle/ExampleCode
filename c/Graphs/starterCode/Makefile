# Makefile for Graphs
CC = gcc
CFLAGS = -Wall

SHARED_SRCS = GraphReader.c debug.c

ADJ_MATRIX_TARGET = matrixTest.out
ADJ_MATRIX_SRCS = adjMatrix.c testAdjMatrix.c

ADJ_LIST_TARGET = listTest.out
ADJ_LIST_SRCS = adjList.c testAdjList.c

TRAVERSAL_TARGET = traversalTest.out
TRAVERSAL_SRCS = adjList.c traversal.c testTraversal.c

all: amatrix alist traversal

amatrix: $(ADJ_MATRIX_TARGET)

$(ADJ_MATRIX_TARGET): $(ADJ_MATRIX_SRCS)
	$(CC) $(CFLAGS) -o $(ADJ_MATRIX_TARGET) $(ADJ_MATRIX_SRCS) $(SHARED_SRCS)



traversal:
	$(CC) $(CFLAGS) -o $(TRAVERSAL_TARGET) $(TRAVERSAL_SRCS) $(SHARED_SRCS)


alist: $(ADJ_LIST_TARGET)

$(ADJ_LIST_TARGET): $(ADJ_LIST_SRCS)
	$(CC) $(CFLAGS) -o $(ADJ_LIST_TARGET) $(ADJ_LIST_SRCS) $(SHARED_SRCS)


clean:
	rm -f *.out
