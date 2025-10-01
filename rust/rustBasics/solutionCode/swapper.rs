/// Sample program that swaps values in memory
/// 
/// 


/// This function swaps the values of two mutable references to i32.
fn swapper(a: &mut i32, b: &mut i32) {
    let temp = *a;
    *a = *b;
    *b = temp;
}

fn main() {
    let mut x = 5;
    let mut y = 10;

    println!("Before swap: x = {}, y = {}", x, y);
    swapper(&mut x, &mut y);
    println!("After swap: x = {}, y = {}", x, y);

    // Alternatively, we can use tuple destructuring to swap values
    // This is the more common way in Rust
    // However, this creates new immutable variables
    let (x, y) = (y, x);
    println!("After tuple swap: x = {}, y = {}", x, y);
}
