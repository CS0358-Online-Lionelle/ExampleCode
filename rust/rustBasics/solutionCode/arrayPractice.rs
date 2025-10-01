///
/// Code along focusing on practice with Arrays


/// This function calculates the sum of all elements in an array.
/// 
/// `param arr`: A slice of integers
/// `return`: The sum of the elements in the array
fn get_sum(arr: &[i32]) -> i32 {
    let mut sum = 0;
    for &num in arr {
        sum += num;
    }
    sum
}

fn array_loop_practice() {
    let arr = [1, 2, 3, 4, 5];
    for &num in &arr {
        println!("The current number is: {}", num);
    }

    // now print with index
    for (i, &num) in arr.iter().enumerate() { // we have to iterate with index
        println!("The current number at index {} is: {}", i, num);
    }

    // now strings
    let str_arr = ["hello", "world", "this", "is", "rust"];
    for &s in &str_arr {
        println!("The current string is: {}", s);
    }

    // now lets add all evens from 1 to 100 indices  into an array
    let mut even_arr = [0; 50]; // creates an array of 50 zeros, needs to be mutable
    let mut index = 0;
    for i in 1..=100 { // is this inclusive or exclusive
        if i % 2 == 0 {
            even_arr[index] = i;
            index += 1;
        }
    }
    // now lets print even_arr
    for &num in &even_arr {
        println!("The current even number is: {}", num);
    }

    // now lets double the size of the values in even_arr
    for num in &mut even_arr {
        *num *= 2;  // what are we doing here? We are saying modify the value at this memory location
    }

    // now lets print the doubled values
    for &num in &even_arr {
        println!("The current doubled even number is: {}", num);
    }
}

fn main() {
    let arr = [1, 2, 3, 4, 5];
    let sum = get_sum(&arr);
    println!("The sum of the array is: {}", sum);

    // we can also do it with a slice of the array
    let sum = get_sum(&arr[1..3]); // This gets the sum of the elements at index 1 and 2
    println!("The sum of the slice is: {}", sum);

    array_loop_practice();
}
