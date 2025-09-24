//! Book struct implementation
//! Contains both the basic
//! Book structure and the ReadList container
//! 
//! **Author:** Albert Lionelle  
//! **Date:** 2025-09-23
//! 

#[derive(Debug)]
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
    pub fn new(title: String, author: String, year: u16) -> Self {
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

    pub fn set_title(&mut self, title: String) {
        self.title = title;
    }

    pub fn set_author(&mut self, author: String) {
        self.author = author;
    }

    pub fn set_year(&mut self, year: u16) {
        self.year = year;
    }
}

