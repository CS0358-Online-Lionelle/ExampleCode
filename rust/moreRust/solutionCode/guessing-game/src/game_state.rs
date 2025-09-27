//! 
//! Game State - Contains Structs the help
//! manage the state of the guessing game
//! 
#[allow(dead_code)]


const MAX_GUESSES: usize = 10;
const MIN_NUMBER: u32 = 1;
const MAX_NUMBER: u32 = 100;

#[derive(PartialEq)]
pub enum PlayerType {
    Human,
    Computer,
}

#[derive(PartialEq)]
pub enum GameStatus {
    InProgress,
    Won,
    Lost,
}

#[derive(PartialEq)]
pub enum GuessResult {
    TooLow,
    TooHigh,
    Correct,
}

/// Represents the state of the game
/// Contains the secret number, the player's guesses,
/// and the game status
/// Also includes methods to make a guess and check the game status
/// The game state is initialized with a random secret number
/// within a specified range
/// and a maximum number of allowed guesses.
pub struct GameState {
    guesses: Vec<u32>,
    secret_number: u32,
    max_guesses: usize,
    game_status: GameStatus,
    min: u32,
    max: u32,
}


impl GameState {
    /// Creates a new game state with a random secret number
    /// within the specified range and a maximum number of allowed guesses
    /// # Arguments
    /// * `min` - The minimum value of the secret number (inclusive)
    /// * `max` - The maximum value of the secret number (inclusive)
    /// * `max_attempts` - The maximum number of allowed guesses
    /// # Returns
    /// * `GameState` - The initialized game state
    /// # Panics
    /// * Panics if `min` is greater than or equal to `max`
    pub fn new(min: u32, max: u32, max_attempts: usize) -> Self {
        use rand::Rng;        
        let secret_number = rand::thread_rng().gen_range(min..=max); // = makes the range inclusive
        GameState {
            guesses: Vec::new(),
            secret_number,
            max_guesses: max_attempts,
            game_status: GameStatus::InProgress,
            min,
            max,
        }
    }

    /// Creates a new game state with default values
    /// # Returns
    /// * `GameState` - The initialized game state with default values
    pub fn new_with_defaults() -> Self {
        Self::new(MIN_NUMBER, MAX_NUMBER, MAX_GUESSES)
    }

    /// Returns the current game status
    /// # Returns
    /// * `&GameStatus` - The current game status
    pub fn game_state(&self) -> &GameStatus {
        &self.game_status
    }

    /// Returns the player's guesses
    /// # Returns
    /// * `&Vec<u32>` - The player's guesses
    pub fn guesses(&self) -> &Vec<u32> {
        &self.guesses
    }

    /// Returns the secret number
    /// # Returns
    /// * `u32` - The secret number
    /// 
    pub fn correct_answer(&self) -> u32 {
        self.secret_number
    }

    

    /// Makes a guess and updates the game state
    /// # Arguments
    /// * `guess` - The player's guess
    /// # Returns
    /// * `GuessResult` - The result of the guess (TooLow, TooHigh, Correct)
    /// # Panics
    /// * Panics if the game is already over
    /// 
    pub fn make_guess(&mut self, guess: u32) -> GuessResult {
        if self.game_status != GameStatus::InProgress {
            panic!("Game is already over");
        }

        self.guesses.push(guess);

        if guess < self.secret_number {
            if self.guesses.len() >= self.max_guesses {
                self.game_status = GameStatus::Lost;
            }
            GuessResult::TooLow
        } else if guess > self.secret_number {
            if self.guesses.len() >= self.max_guesses {
                self.game_status = GameStatus::Lost;
            }
            GuessResult::TooHigh
        } else {
            self.game_status = GameStatus::Won;
            GuessResult::Correct
        }
    }

    pub fn is_game_over(&self) -> bool {
        matches!(self.game_status, GameStatus::Won | GameStatus::Lost)
    }
}