/**
 * Contains code specific to the Matrix Struct including built in implementations
 * 
 * 
 */
use std::fmt;

 #[derive(Debug)]
pub struct Matrix {
    rows: usize,
    cols: usize,
    data: Box<[f32]> // the Box is a fixed sized array, with a length tied to it
}

impl Matrix {
    pub fn new(rows: usize, cols: usize) -> Self {
        Matrix {
            data: vec![0.0; rows*cols].into_boxed_slice(),
            cols: cols,
            rows: rows
        }
    }

    pub fn from_data(data: Vec<f32>, rows: usize, cols: usize) -> Self {
        assert_eq!(data.len(), rows * cols);
        Matrix {rows: rows, 
                cols: cols, 
                data: data.into_boxed_slice()}
    }


    pub fn get(&self, row: usize, col: usize) -> f32 {
        self.data[self.index(row, col)]
    }

    pub fn set(&mut self, row: usize, col: usize, value: f32) {
        let idx = self.index(row, col);
        self.data[idx] = value;
    }

    pub fn add(&mut self, other: &Matrix) -> Result<(), String> {
        // Check dimensions match
        if self.rows != other.rows || self.cols != other.cols {
            return Err(format!(
                "Matrix dimensions don't match: {}x{} vs {}x{}", 
                self.rows, self.cols, other.rows, other.cols
            ));
        }
        
        // Add corresponding elements
        for i in 0..self.data.len() {
            self.data[i] += other.data[i];
        }
        
        Ok(())
    }

    pub fn transpose(&self) -> Matrix {
        let mut transposed = Matrix::new(self.cols, self.rows);  // Note: dimensions swapped
        
        for row in 0..self.rows {
            for col in 0..self.cols {
                let value = self.get(row, col);
                transposed.set(col, row, value);  // Note: col, row swapped
            }
        }
        transposed
    }

    #[inline]
    fn index(&self, row: usize, col: usize) -> usize {
        row * self.cols + col
    }


 
}


impl fmt::Display for Matrix {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        writeln!(f, "Matrix({}, {})", self.rows, self.cols)?;
        
        for row in 0..self.rows {
            write!(f, "[")?;
            for col in 0..self.cols {
                let index = self.index(row, col);
                if col == self.cols - 1 {
                    write!(f, "{}", self.data[index])?;  // Last column, no comma
                } else {
                    write!(f, "{}, ", self.data[index])?;
                }
            }
            writeln!(f, "]")?;
        }
        
        Ok(())
    }
}