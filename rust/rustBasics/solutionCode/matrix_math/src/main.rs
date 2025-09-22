mod matrix;
use matrix::{Matrix};

fn small_test() {
    let mut matrix = Matrix::new(3,3);

    println!("{}", matrix);

    println!("(0,0) =  {}", matrix.get(0,0));
    matrix.set(0, 0, 10.0);
    println!("(0,0) = {}", matrix.get(0,0));
}

fn add_test() {
    let mut one = Matrix::from_data(vec![1.0, 1.0, 1.0, 
                                         1.0, 1.0, 1.0, 
                                         1.0, 1.0, 1.0], 3, 3);

    let two = Matrix::from_data(vec![1.0, 1.0, 1.0, 
                                     1.0, 1.0, 1.0, 
                                     1.0, 1.0, 1.0], 3, 3);
    
    println!("Testing Add");
    println!("{}", one);

    let _ = one.add(&two);
 
    println!("Values after add should all be 2.0");
    println!("{}", one);

}


fn transpose_test() {
    println!("Testing Transpose");

    let matrix = Matrix::from_data(vec![1.0, 2.0, 3.0,
                                        4.0, 5.0, 6.0,
                                        7.0, 8.0, 9.0], 3, 3);
    println!("{}", matrix);

    let transposed = matrix.transpose();

    println!("{}", transposed);
}

fn main() {
    small_test();
    add_test();
    transpose_test();

}
