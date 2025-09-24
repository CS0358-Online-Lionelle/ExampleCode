//! ReadingList example
//! This example uses structs
//! and adds items to a reading list
//! I will be done in two parts, first the setup
//! then adding books by reading a file. 
//! 
//! **Author:** Albert Lionelle  
//! **Date:** 2025-09-23

mod book;
use book::{Book, ReadingList};

//"Brandon Sanderson", "Mistborn: The Final Empire", 2006
//"Frank Herbert", "Dune", 1965
//"J.R.R. Tolkien", "The Fellowship of the Ring", 1954

fn main() {
    let mut list = ReadingList::new();

    list.add_book(
        Book::new("Brandon Sanderson", "Mistborn: The Final Empire", 2006)
    );

    list += Book::new("Frank Herbert", "Dune", 1965);
    list += Book::new("J.R.R. Tolkien", "The Fellowship of the Ring", 1954);

    println!("{}", list);

}
