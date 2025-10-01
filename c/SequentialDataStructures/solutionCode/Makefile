# Makefile for Data Structures Programs

CC = gcc
CFLAGS = -Wall

# Vector target
VECTOR_TARGET = vectorTest.out
VECTOR_SRCS = NeuVector.c VectorMain.c

# Queue target
QUEUE_TARGET = queueTest.out
QUEUE_SRCS = NeuQueue.c QueueMain.c

# Singly Linked List target
SLL_TARGET = sllTest.out
SLL_SRCS = NeuSinglyLinkedList.c sllMain.c

all: vector sll queue

vector: $(VECTOR_TARGET)

$(VECTOR_TARGET): $(VECTOR_SRCS)
	$(CC) $(CFLAGS) -o $(VECTOR_TARGET) $(VECTOR_SRCS)

queue: $(QUEUE_TARGET)

$(QUEUE_TARGET): $(QUEUE_SRCS)
	$(CC) $(CFLAGS) -o $(QUEUE_TARGET) $(QUEUE_SRCS)

sll: $(SLL_TARGET)

$(SLL_TARGET): $(SLL_SRCS)
	$(CC) $(CFLAGS) -o $(SLL_TARGET) $(SLL_SRCS)

clean:
	rm -f $(VECTOR_TARGET) $(STACK_TARGET) $(QUEUE_TARGET)
