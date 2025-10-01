use std::time::{Duration, Instant};

pub fn time_function<F>(func: F, size: usize, print: bool) -> std::time::Duration 
where
    F: FnOnce(usize, bool),
{
    let start = Instant::now();
    func(size, print);
    start.elapsed()
}

pub fn print_duration(duration: Duration) {
    let total_seconds = duration.as_secs();
    
    if total_seconds >= 60 {
        let minutes = total_seconds / 60;
        let seconds = total_seconds % 60;
        let millis = duration.subsec_millis();
        println!("Time taken: {} minutes and {}.{:03} seconds", minutes, seconds, millis);
    } else {
        let seconds = duration.as_secs_f64();
        println!("Time taken: {:.3} seconds", seconds);
    }
}
