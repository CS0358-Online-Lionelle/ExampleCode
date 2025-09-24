#![allow(dead_code)]
//! Book struct implementation
//! Contains both the basic
//! Book structure and the ReadList container
//! 
//! **Author:** Albert Lionelle  
//! **Date:** 2025-09-23
//! 
use std::fmt;
use std::ops::AddAssign;

#[derive(Debug, Clone)]
/// Book struct containing a 
/// the title, author, and year of a book. 
/// 
/// Allows updating of all fields
/// through accessors and mutators
pub struct Book {
    title: String,
    author: String,
    year: u16,
}

impl Book {

    /// Creates a new book
    pub fn new(title: &str, author: &str, year: u16) -> Self {
        Book {
            title: String::from(title), 
            author: String::from(author),
            year: year,
        }
    }

    pub fn title(&self) -> String {
        self.title.clone()
    }

    pub fn author(&self) -> String {
        self.author.clone()
    }

    pub fn year(&self) -> u16 {
        self.year
    }

    pub fn set_title(&mut self, title: &str) {
        self.title = String::from(title);
    }

    pub fn set_author(&mut self, author: &str) {
        self.author = String::from(author);
    }

    pub fn set_year(&mut self, year: u16) {
        self.year = year;
    }
}

impl fmt::Display for Book {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{} by {} ({})", self.title, self.author, self.year)
    }
}

pub struct ReadingList {
    books: Vec<Book>,
}

impl ReadingList {
    pub fn new() -> Self {
        ReadingList {
            books: Vec::new()
        }
    }

    pub fn size(&self) -> usize {
        self.books.len()
    }

    pub fn is_empty(&self) -> bool {
        self.books.is_empty()
    }

    pub fn add_book(&mut self, book: Book) {
        self.books.push(book);
    }

    
}

// Then implement Display for ReadingList
impl fmt::Display for ReadingList {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        writeln!(f, "Reading List ({} books):", self.size())?;
        
        if self.is_empty() {
            writeln!(f, "  (No books in list)")?;
        } else {
            for (index, book) in self.books.iter().enumerate() {
                writeln!(f, "  {}. {}", index + 1, book)?; // Uses Book's Display
            }
        }
        
        Ok(())
    }
}

impl AddAssign<Book> for ReadingList {
    fn add_assign(&mut self, book: Book) {
        self.books.push(book);
    }
}

impl AddAssign<Vec<Book>> for ReadingList {
    fn add_assign(&mut self, books: Vec<Book>) {
        self.books.extend(books);
    }
}