//! Example on optimizing rust code
//! Will be using samply
//! ```bash
//!  # Install
//! cargo install samply
//! 
//! # Generate flame graph
//! samply record  cargo run -- 100000
//!
//! # Opens an interactive HTML flame graph showing where time is spent
//! ```
//! While this file has the correct optimization
//! The original is in comments next to the corrected line. 
//! 


mod functionTimers;
use functionTimers::{time_function, print_duration};

use std::env;

fn is_prime(x: i32) -> bool {
    if x <= 1 { 
        return false;
    }
    
    let end = ((x as f64).sqrt() as i32)+1;
//    for i in 2..((x as f64).sqrt() as i32 + 1) {
    for i in 2..end {
        if x % i == 0 {
            return false;
        }
    }
    return true;
}


fn get_primes(size: usize) -> Vec<i32> {
    let mut arr = Vec::with_capacity(size);
    let mut i = 2;

    while arr.len() < size {
        if is_prime(i) {
            arr.push(i)
        }
        i += 1;
    }
    return arr;
}

fn run_test(size: usize, print: bool) {
    let arr = get_primes(size);
    if print {
        println!("{:?}", arr);
    }
}


fn main() {
       let args: Vec<String> = env::args().collect();
    
    if args.len() != 2 {
        eprintln!("Usage: {} <size>", args[0]);
        std::process::exit(1);
    }
    
    let size: usize = match args[1].parse() {
        Ok(n) if n > 0 => n,
        Ok(_) => {
            eprintln!("Size must be a positive integer.");
            std::process::exit(1);
        }
        Err(_) => {
            eprintln!("Invalid number: {}", args[1]);
            std::process::exit(1);
        }
    };
    
    let print = size <= 1000;
    
    if print {
        println!("Finding the first {} prime numbers:\n", size);
    }
    
    println!("Benchmarking prime generation for {} primes:\n", size);
    
    // Time the function 
    let time = time_function(run_test, size, print);
    print_duration(time);
    
    println!("\nNote: Run with 'cargo run --release <size>' for accurate performance measurements!");

}