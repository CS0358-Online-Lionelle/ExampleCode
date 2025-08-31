///
/// Example program showing how to use program arguments
/// in rust.
///

fn main() {
    let args: Vec<String> = std::env::args().collect(); // Vec<String> is like a list of strings
    
    println!("Number of arguments: {}", args.len());

    for (i, arg) in args.iter().enumerate() {
        println!("Argument {}: {}", i, arg);
    }


    if args.len() > 1 {
        let first_arg = &args[0];
        println!("The first argument is: {}", first_arg);
        let second_arg = &args[1];
        println!("The second argument is: {}", second_arg);
    }
}
