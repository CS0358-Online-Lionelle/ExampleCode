# Makefile for Sorted Structures and Trees
CC = gcc
CFLAGS = -Wall

# Priority Queue with Sorted Array target
SORTED_QUEUE_TARGET = sortedTest.out
SORTED_QUEUE_SRCS = NeuPriorityQueue.c PriorityMain.c

# Tree target
TREE_TARGET = treeTest.out
TREE_SRCS = NeuTree.c TreeMain.c

# Heap
HEAP_TARGET = heapTest.out
HEAP_SRCS = NeuHeap.c HeapMain.c

all: pqueue tree heap

pqueue: $(SORTED_QUEUE_TARGET)

$(SORTED_QUEUE_TARGET): $(SORTED_QUEUE_SRCS)
	$(CC) $(CFLAGS) -o $(SORTED_QUEUE_TARGET) $(SORTED_QUEUE_SRCS)

tree: $(TREE_TARGET)

$(TREE_TARGET): $(TREE_SRCS)
	$(CC) $(CFLAGS) -o $(TREE_TARGET) $(TREE_SRCS)

heap: $(HEAP_TARGET)

$(HEAP_TARGET): $(HEAP_SRCS)
	$(CC) $(CFLAGS) -o $(HEAP_TARGET) $(HEAP_SRCS)

clean:
	rm -f *.out
