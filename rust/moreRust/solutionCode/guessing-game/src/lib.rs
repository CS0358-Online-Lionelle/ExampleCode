//! # Guessing Game Library
//! 
//! A modular and well-tested implementation of the classic number guessing game.
//! This library provides clean separation between game logic and player behavior,
//! enabling flexible game development and easy testing.
//! 
//! ## Features
//! 
//! - **Modular Design**: Separate modules for game state and player management
//! - **Multiple Player Types**: Support for both human and computer players
//! - **Configurable Games**: Customizable number ranges and guess limits
//! - **Comprehensive Testing**: Full test suite with unit and integration tests
//! - **AI Support**: Computer players with strategic range tracking
//! - **Clean API**: Well-documented public interface with examples
//! 
//! ## Quick Start
//! 
//! Here's a simple example of creating and playing a game:
//! 
//! ```
//! use guessing_game::game_state::{GameState, GuessResult, GameStatus};
//! use guessing_game::player::Player;
//! 
//! // Create a game and player
//! let mut game = GameState::new_with_defaults();
//! let mut player = Player::new_human();
//! 
//! // Make a guess
//! let result = game.make_guess(50);
//! player.add_guess(50);
//! 
//! match result {
//!     GuessResult::TooLow => println!("Try a higher number!"),
//!     GuessResult::TooHigh => println!("Try a lower number!"),
//!     GuessResult::Correct => println!("You won!"),
//! }
//! 
//! // Check if the game is over
//! if *game.game_status() != GameStatus::InProgress {
//!     println!("Game ended! Final guess count: {}", game.guesses().len());
//! }
//! ```
//! 
//! ## Computer Player Example
//! 
//! The library supports computer players with AI strategy:
//! 
//! ```
//! use guessing_game::game_state::{GameState, GuessResult};
//! use guessing_game::player::Player;
//! 
//! let mut game = GameState::new_with_defaults();
//! let mut computer = Player::new_computer(1, 100);
//! 
//! // Computer makes a strategic guess
//! let guess = 50; // Middle of range
//! let result = game.make_guess(guess);
//! computer.add_guess(guess);
//! 
//! // Update computer's strategy based on result
//! match result {
//!     GuessResult::TooHigh => {
//!         if let Some((min, _)) = computer.get_computer_range() {
//!             computer.update_computer_range(min, guess - 1);
//!         }
//!     },
//!     GuessResult::TooLow => {
//!         if let Some((_, max)) = computer.get_computer_range() {
//!             computer.update_computer_range(guess + 1, max);
//!         }
//!     },
//!     GuessResult::Correct => println!("Computer won!"),
//! }
//! ```
//! 
//! ## Architecture
//! 
//! The library is organized into two main modules:
//! 
//! - [`game_state`]: Manages game logic, state, and guess validation
//! - [`player`]: Handles player types, guess history, and AI strategies
//! 
//! This separation allows for:
//! - Independent testing of game logic and player behavior
//! - Multiple players participating in the same game
//! - Single players participating in multiple games
//! - Easy extension with new player types or game variants
//! 
//! ## Custom Game Configuration
//! 
//! Create games with custom parameters:
//! 
//! ```
//! use guessing_game::game_state::GameState;
//! 
//! // Game with numbers 1-50, maximum 5 guesses
//! let game = GameState::new(1, 50, 5);
//! 
//! // Standard game (1-100, 10 guesses)
//! let game = GameState::new_with_defaults();
//! ```
//! 
//! ## Testing
//! 
//! Run the comprehensive test suite:
//! 
//! ```bash
//! cargo test                    # Run all tests
//! cargo test player_tests      # Run player module tests
//! cargo test game_state_tests  # Run game state tests
//! cargo test integration_tests # Run integration tests
//! ```
//! 
//! ## Documentation
//! 
//! Generate and view the full documentation:
//! 
//! ```bash
//! cargo doc --open
//! ```

pub mod game_state;
pub mod player;