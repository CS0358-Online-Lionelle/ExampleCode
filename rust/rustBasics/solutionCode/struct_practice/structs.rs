use std::fmt;

#[derive(Debug)]
pub struct Person {
    pub name: String,
    pub age: u32,
}

impl Person {
    pub fn display(&self) {
        println!("Name: {}, Age: {}", self.name, self.age);
    }
}

#[derive(Debug)]
pub struct Book {
    title: String,
    author: String,
    year: u16, // no need to have a larger value
}
impl Book {
    pub fn new(title: String, author: String, year: u16) -> Self {
        Book { title, author, year }
    }

    pub fn update_book_title(&mut self, new_title: String) {
        self.title = new_title;
    }
}

impl fmt::Display for Book {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{} by {} ({})", self.title, self.author, self.year)
    }
}


/// Macro to check a person's age
#[macro_export]
macro_rules! check_age {
    ($person:expr, $age:expr) => {
        if $person.age >= $age {
            println!("{} is at least {} years old.", $person.name, $age);
            true
        } else {
            println!("{} is younger than {} years old.", $person.name, $age);
            false
        }
    };
    ($person:expr) => {
        check_age!($person, LEGAL_DRINKING_AGE)
    };
}