/// Practice using Structs 
/// 

mod structs;
use structs::{Book, Person};

const LEGAL_DRINKING_AGE: u32 = 21;


fn update_person_age(person: &mut Person, new_age: u32) {
    person.age = new_age;
}

fn update_book_title(book: &mut Book, new_title: String) {
    book.title = new_title;
}

fn check_drinking_age(person: &Person) -> bool {
    if person.age >= LEGAL_DRINKING_AGE {
        println!("{} is of legal drinking age.", person.name);
        true
    } else {
        println!("{} is not of legal drinking age.", person.name);
        false
    }
}



fn main() {
    let mut alice = Person {
        name: String::from("Alice"),
        age: 20,
    };

    alice.display();
    println!("{:?}", alice);

    let bob = Person {
        name: String::from("Bob"),
        age: 22,
    };

    bob.display();



 /*    let mut book = Book {
        title: String::from("The Rust Programming Language"),
        author: String::from("Steve Klabnik and Carol Nichols"),
        year: 2018,
    };
*/
    let mut book = Book::new(
        String::from("The Rust Programming Language"),
        String::from("Steve Klabnik and Carol Nichols"),
        2018,
    );

    let book2 = Book::new(
        String::from("Programming Rust"),
        String::from("Jim Blandy and Jason Orendorff"),
        2017,
    );

    check_age!(alice);
    check_age!(bob);
    check_age!(alice, 18);

    check_drinking_age(&alice);

    update_person_age(&mut alice, 21);
    check_drinking_age(&alice);


    update_book_title(&mut book, String::from("The Rust Programming Language, 2nd Edition"));
    println!("{}", book);
    println!("{}", book2);
}