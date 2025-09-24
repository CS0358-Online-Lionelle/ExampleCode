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

//"Mistborn: The Final Empire","Brandon Sanderson",  2006
//"Dune", "Frank Herbert", 1965
//"The Fellowship of the Ring","J.R.R. Tolkien", 1954

fn main() {
    let mut list = ReadingList::new();

    list.add_book(
        Book::new("Mistborn: The Final Empire", "Brandon Sanderson",  2006)
    );

    list += Book::new("Dune", "Frank Herbert", 1965);
    list += Book::new("The Fellowship of the Ring", "J.R.R. Tolkien", 1954);

    println!("{}", list);

    match list.remove_by_title("Dune") {
        Ok(book) => println!("Removed: {}\n", book),
        Err(e) => println!("Error: {}\n", e),
    }

    println!("{}", list);

}
