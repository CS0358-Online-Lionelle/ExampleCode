/**
 * Solution file for FileIO Code Along
 *
 * @author: Albert Lionelle
 * @date: 2025.04.10
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char author[100];
    char title[256];
    int year;
  } Book;
  
  typedef struct {
    Book *books;
    int size;
    int current;
  } ReadingList;
  
  ReadingList *createReadingList(int size) {
    ReadingList *readingList = (ReadingList *)malloc(sizeof(ReadingList));
    readingList->books = (Book *)malloc(sizeof(Book) * size);
    readingList->size = size;
    readingList->current = 0;
    return readingList;
  }
  
  void freeReadingList(ReadingList *readingList) {
    free(readingList->books);
    free(readingList);
  }
  
  void printReadingList(ReadingList *readingList) {
    for (int i = 0; i < readingList->current; i++) {
      printf("Book %d: %s by %s (%d)\n", i + 1, readingList->books[i].title,
             readingList->books[i].author, readingList->books[i].year);
    }
  }
  
  void copyString(char *dest, const char *src, int size) {
    strncpy(dest, src, size - 1);
    dest[size - 1] = '\0';
  }
  
  void addBook(ReadingList *readingList, const char *author, const char *title,
               int year) {
    int index = readingList->current;
    Book *singleBook = &readingList->books[index];
    copyString(singleBook->author, author, sizeof(singleBook->author));
    copyString(singleBook->title, title, sizeof(singleBook->title));
    singleBook->year = year;
    readingList->current++;
  }
  
  void removeBook(ReadingList *readingList, int index) {
    if (index < 0 || index >= readingList->current) {
      printf("Invalid index\n");
      return;
    }
    for (int i = index; i < readingList->current - 1; i++) {
      readingList->books[i] = readingList->books[i + 1];
    }
    readingList->current--;
  }
  
  void loadBooksFromFile(const char* filename, ReadingList *readingList) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
      printf("Error opening file\n");
      return;
    }
    char line[256];
    int lineOne = 1;
    while (fgets(line, sizeof(line), file)) {
      if (lineOne) {
        lineOne = 0;
        continue;
      }
      char *author = strtok(line, ",");
      char *title = strtok(NULL, ",");
      int year = atoi(strtok(NULL, ","));
  
      addBook(readingList, author, title, year);
  
    }
  
    fclose(file);
  
  }
  
  int main() {
    ReadingList *myList = createReadingList(10);
  
    loadBooksFromFile("Books.csv", myList);
  
    // addBook(myList, "Brandon Sanderson", "Mistborn: The Final Empire", 2006);
    // addBook(myList, "Frank Herbert", "Dune", 1965);
    // addBook(myList, "J.R.R. Tolkien", "The Fellowship of the Ring", 1954);
  
    printReadingList(myList);
    printf("\n");
    removeBook(myList, 6);
    printReadingList(myList);
  
    freeReadingList(myList);
    return 0;
  }