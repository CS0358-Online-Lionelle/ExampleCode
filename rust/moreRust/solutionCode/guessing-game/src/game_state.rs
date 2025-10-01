//! # Game State Module
//! 
//! This module contains structures and enums that manage the core state and logic
//! of the guessing game. It provides a clean separation between game mechanics
//! and player behavior, allowing for flexible game management.
//! 
//! The module handles:
//! - Game state tracking (in progress, won, lost)
//! - Guess validation and feedback
//! - Win/loss condition detection
//! - Random secret number generation
//! 
//! ## Examples
//! 
//! Basic game usage:
//! 
//! ```
//! use guessing_game::game_state::{GameState, GuessResult, GameStatus};
//! 
//! let mut game = GameState::new_with_defaults();
//! 
//! match game.make_guess(50) {
//!     GuessResult::TooLow => println!("Guess higher!"),
//!     GuessResult::TooHigh => println!("Guess lower!"),
//!     GuessResult::Correct => println!("You won!"),
//! }
//! 
//! if *game.game_status() == GameStatus::Won {
//!     println!("Congratulations!");
//! }
//! ```
//! 
//! Creating a custom game:
//! 
//! ```
//! use guessing_game::game_state::GameState;
//! 
//! // Game with numbers 1-50, max 5 guesses
//! let mut game = GameState::new(1, 50, 5);
//! ```
#[allow(dead_code)]


const MAX_GUESSES: usize = 10;
const MIN_NUMBER: u32 = 1;
const MAX_NUMBER: u32 = 100;

/// Represents the current status of a guessing game.
/// 
/// This enum tracks the overall state of the game, allowing callers to
/// determine whether the game is still playable or has reached a terminal
/// state (won or lost).
/// 
/// # Examples
/// 
/// ```
/// use guessing_game::game_state::{GameState, GameStatus};
/// 
/// let game = GameState::new_with_defaults();
/// assert_eq!(*game.game_status(), GameStatus::InProgress);
/// ```
#[derive(PartialEq, Debug, Copy, Clone)]
pub enum GameStatus {
    /// The game is still active and accepting guesses
    InProgress,
    /// The player has successfully guessed the secret number
    Won,
    /// The player has exceeded the maximum number of allowed guesses
    Lost,
}

/// Represents the result of a single guess in the guessing game.
/// 
/// This enum provides feedback to the player about their guess relative
/// to the secret number, enabling them to adjust their strategy for
/// subsequent guesses.
/// 
/// # Examples
/// 
/// ```
/// use guessing_game::game_state::{GameState, GuessResult};
/// 
/// let mut game = GameState::new(42, 42, 10); // Secret number is 42
/// 
/// assert_eq!(game.make_guess(25), GuessResult::TooLow);
/// assert_eq!(game.make_guess(60), GuessResult::TooHigh);
/// assert_eq!(game.make_guess(42), GuessResult::Correct);
/// ```
#[derive(PartialEq, Debug, Copy, Clone)]
pub enum GuessResult {
    /// The guess is lower than the secret number
    TooLow,
    /// The guess is higher than the secret number
    TooHigh,
    /// The guess matches the secret number exactly
    Correct,
}

/// Represents the complete state of a guessing game session.
/// 
/// `GameState` encapsulates all the information needed to manage a single
/// game instance, including the secret number, guess history, game status,
/// and configuration parameters. It provides methods to make guesses and
/// query the current state.
/// 
/// The game state is completely independent of player implementations,
/// allowing multiple players to interact with the same game or a single
/// player to participate in multiple games simultaneously.
/// 
/// # Examples
/// 
/// ```
/// use guessing_game::game_state::{GameState, GameStatus, GuessResult};
/// 
/// let mut game = GameState::new_with_defaults();
/// 
/// // Make some guesses
/// let result1 = game.make_guess(50);
/// let result2 = game.make_guess(25);
/// 
/// // Check game state
/// println!("Guesses made: {:?}", game.guesses());
/// println!("Game status: {:?}", game.game_status());
/// 
/// // Continue until game ends
/// while *game.game_status() == GameStatus::InProgress {
///     // ... make more guesses
///     break; // For documentation example
/// }
/// ```
#[derive(Debug)]
pub struct GameState {
    guesses: Vec<u32>,
    secret_number: u32,
    max_guesses: usize,
    game_status: GameStatus,
    min: u32,
    max: u32,
}


impl GameState {
    /// Creates a new game state with a random secret number within the specified range.
    /// 
    /// This constructor initializes a new game with a randomly generated secret number
    /// between the given bounds (inclusive) and sets up the game for the specified
    /// maximum number of guesses.
    /// 
    /// # Arguments
    /// 
    /// * `min` - The minimum possible value for the secret number (inclusive)
    /// * `max` - The maximum possible value for the secret number (inclusive)
    /// * `max_attempts` - The maximum number of guesses allowed before the game is lost
    /// 
    /// # Returns
    /// 
    /// A new `GameState` instance ready to accept guesses.
    /// 
    /// # Panics
    /// 
    /// This function will panic if `min` is greater than `max`, as this would create
    /// an invalid range for random number generation.
    /// 
    /// # Examples
    /// 
    /// ```
    /// use guessing_game::game_state::{GameState, GameStatus};
    /// 
    /// // Create a game with secret number between 1-100, max 10 guesses
    /// let game = GameState::new(1, 100, 10);
    /// assert_eq!(*game.game_status(), GameStatus::InProgress);
    /// assert!(game.guesses().is_empty());
    /// 
    /// // Create a game with a smaller range
    /// let game = GameState::new(1, 10, 5);
    /// let secret = game.correct_answer();
    /// assert!(secret >= 1 && secret <= 10);
    /// ```
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

    /// Creates a new game state with sensible default values.
    /// 
    /// This convenience constructor creates a game with:
    /// - Secret number range: 1 to 100 (inclusive)
    /// - Maximum guesses: 10
    /// 
    /// This is the recommended way to create a standard guessing game.
    /// 
    /// # Returns
    /// 
    /// A new `GameState` instance with default configuration.
    /// 
    /// # Examples
    /// 
    /// ```
    /// use guessing_game::game_state::{GameState, GameStatus};
    /// 
    /// let game = GameState::new_with_defaults();
    /// assert_eq!(*game.game_status(), GameStatus::InProgress);
    /// 
    /// // Secret number will be between 1 and 100
    /// let secret = game.correct_answer();
    /// assert!(secret >= 1 && secret <= 100);
    /// ```
    pub fn new_with_defaults() -> Self {
        Self::new(MIN_NUMBER, MAX_NUMBER, MAX_GUESSES)
    }

    /// Returns a reference to the current game status.
    /// 
    /// The game status indicates whether the game is still in progress,
    /// has been won, or has been lost due to exceeding the maximum
    /// number of guesses.
    /// 
    /// # Returns
    /// 
    /// A reference to the current `GameStatus`.
    /// 
    /// # Examples
    /// 
    /// ```
    /// use guessing_game::game_state::{GameState, GameStatus};
    /// 
    /// let mut game = GameState::new(42, 42, 10); // Secret is always 42
    /// assert_eq!(*game.game_status(), GameStatus::InProgress);
    /// 
    /// game.make_guess(42); // Correct guess
    /// assert_eq!(*game.game_status(), GameStatus::Won);
    /// ```
    pub fn game_status(&self) -> &GameStatus {
        &self.game_status
    }

    /// Returns a reference to the vector of all guesses made in this game.
    /// 
    /// The guesses are stored in chronological order, with the first guess
    /// at index 0 and the most recent guess at the end of the vector.
    /// 
    /// # Returns
    /// 
    /// A reference to a vector containing all guesses made in this game session.
    /// 
    /// # Examples
    /// 
    /// ```
    /// use guessing_game::game_state::GameState;
    /// 
    /// let mut game = GameState::new_with_defaults();
    /// assert!(game.guesses().is_empty());
    /// 
    /// game.make_guess(50);
    /// game.make_guess(25);
    /// game.make_guess(75);
    /// 
    /// assert_eq!(game.guesses(), &vec![50, 25, 75]);
    /// ```
    pub fn guesses(&self) -> &Vec<u32> {
        &self.guesses
    }

    /// Returns the secret number for this game.
    /// 
    /// This method reveals the secret number that players are trying to guess.
    /// It's primarily useful for testing, debugging, or displaying the answer
    /// after a game has ended.
    /// 
    /// # Returns
    /// 
    /// The secret number as a `u32`.
    /// 
    /// # Examples
    /// 
    /// ```
    /// use guessing_game::game_state::GameState;
    /// 
    /// let game = GameState::new(42, 42, 10); // Secret is always 42
    /// assert_eq!(game.correct_answer(), 42);
    /// 
    /// let game = GameState::new(1, 10, 5);
    /// let secret = game.correct_answer();
    /// assert!(secret >= 1 && secret <= 10);
    /// ```
    /// 
    /// # Note
    /// 
    /// In a real game implementation, you might want to restrict access to this
    /// method to prevent cheating.
    pub fn correct_answer(&self) -> u32 {
        self.secret_number
    }

    /// Makes a guess and updates the game state accordingly.
    /// 
    /// This is the core method for game interaction. It processes a guess,
    /// updates the game's internal state, and returns feedback about whether
    /// the guess was too low, too high, or correct. The method automatically
    /// handles win/loss detection and prevents further guesses once the game
    /// has ended.
    /// 
    /// # Arguments
    /// 
    /// * `guess` - The player's numerical guess
    /// 
    /// # Returns
    /// 
    /// A `GuessResult` indicating whether the guess was too low, too high, or correct.
    /// 
    /// # Panics
    /// 
    /// This method will panic if called when the game is already over (status is
    /// `Won` or `Lost`). Check the game status before making a guess to avoid this.
    /// 
    /// # Examples
    /// 
    /// ```
    /// use guessing_game::game_state::{GameState, GuessResult, GameStatus};
    /// 
    /// let mut game = GameState::new(50, 50, 10); // Secret is always 50
    /// 
    /// // Make various guesses
    /// assert_eq!(game.make_guess(25), GuessResult::TooLow);
    /// assert_eq!(*game.game_status(), GameStatus::InProgress);
    /// 
    /// assert_eq!(game.make_guess(75), GuessResult::TooHigh);
    /// assert_eq!(*game.game_status(), GameStatus::InProgress);
    /// 
    /// assert_eq!(game.make_guess(50), GuessResult::Correct);
    /// assert_eq!(*game.game_status(), GameStatus::Won);
    /// 
    /// // All guesses are recorded
    /// assert_eq!(game.guesses(), &vec![25, 75, 50]);
    /// ```
    /// 
    /// Example of losing a game:
    /// 
    /// ```
    /// use guessing_game::game_state::{GameState, GuessResult, GameStatus};
    /// 
    /// let mut game = GameState::new(50, 50, 2); // Only 2 guesses allowed
    /// 
    /// game.make_guess(25); // First wrong guess
    /// assert_eq!(*game.game_status(), GameStatus::InProgress);
    /// 
    /// let result = game.make_guess(75); // Second wrong guess - game lost
    /// assert_eq!(result, GuessResult::TooHigh);
    /// assert_eq!(*game.game_status(), GameStatus::Lost);
    /// ```
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

    /// Checks whether the game has reached a terminal state.
    /// 
    /// This is a convenience method that returns `true` if the game status
    /// is either `Won` or `Lost`, indicating that no more guesses should
    /// be accepted.
    /// 
    /// # Returns
    /// 
    /// `true` if the game is over (won or lost), `false` if still in progress.
    /// 
    /// # Examples
    /// 
    /// ```
    /// use guessing_game::game_state::GameState;
    /// 
    /// let mut game = GameState::new(42, 42, 10);
    /// assert!(!game.is_game_over()); // Game just started
    /// 
    /// game.make_guess(42); // Correct guess
    /// assert!(game.is_game_over()); // Game is now won
    /// ```
    /// 
    /// ```
    /// use guessing_game::game_state::GameState;
    /// 
    /// let mut game = GameState::new(42, 42, 1); // Only 1 guess allowed
    /// assert!(!game.is_game_over());
    /// 
    /// game.make_guess(99); // Wrong guess, no more attempts
    /// assert!(game.is_game_over()); // Game is now lost
    /// ```
    pub fn is_game_over(&self) -> bool {
        matches!(self.game_status, GameStatus::Won | GameStatus::Lost)
    }
}