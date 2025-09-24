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

use std::env;
use std::fs; // for reading files

//"Mistborn: The Final Empire","Brandon Sanderson",  2006
//"Dune", "Frank Herbert", 1965
//"The Fellowship of the Ring","J.R.R. Tolkien", 1954


fn basic_add(list: &mut ReadingList) {
    list.add_book(
        Book::new("Mistborn: The Final Empire", "Brandon Sanderson",  2006)
    );

    *list += Book::new("Dune", "Frank Herbert", 1965);
    *list += Book::new("The Fellowship of the Ring", "J.R.R. Tolkien", 1954);

    println!("{}", list);

    match list.remove_by_title("Dune") {
        Ok(book) => println!("Removed: {}\n", book),
        Err(e) => println!("Error: {}\n", e),
    }

    println!("{}", list);

}

fn add_csv_test(list: &mut ReadingList) {

    let line = "Stranger in a Strange Land,Robert A. Heinlein,1961";

    match Book::from_csv_line(line) {
        Ok(book) => list.add_book(book),
        Err(e) => {
            eprintln!("Error parsing line {}, error {}", line, e);
        }
    }

    println!("{}", list);

}

fn load_reading_list(filename: &String) -> ReadingList {
    let mut list = ReadingList::new();
     let contents = match fs::read_to_string(filename) {
        Ok(content) => content,
        Err(e) => { 
            eprintln!("Failed to read file {}: {}", filename, e);
            return list;
        }
    };
    let mut lines = contents.lines();

    let _ = lines.next(); // skip header 

     for line in lines {
        // Skip empty lines
        if line.trim().is_empty() {
            continue;
        }
        match Book::from_csv_line(line) {
            Ok(book) => list.add_book(book),
            Err(e) => {
              eprintln!("Error parsing line {}, error {}", line, e);
          }
        }
    }

    return list;
}


fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        let mut list = ReadingList::new();
        basic_add(&mut list);
        add_csv_test(&mut list);
    }else {

        println!("Loading list with file: \"{}\"", args[1]);
        let list = load_reading_list(&args[1]);
        println!("{}", list);
    }

}
