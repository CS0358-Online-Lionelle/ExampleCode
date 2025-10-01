//! # Player Module
//! 
//! This module contains player types and related functionality for the guessing game.
//! It provides abstractions for different types of players (human and computer) and
//! manages player-specific state such as guess history and AI strategy data.
//! 
//! ## Examples
//! 
//! Creating and using different player types:
//! 
//! ```
//! use guessing_game::player::{Player, PlayerType};
//! 
//! // Create a human player
//! let mut human = Player::new_human();
//! human.add_guess(42);
//! assert_eq!(*human.player_type(), PlayerType::Human);
//! 
//! // Create a computer player with AI strategy
//! let mut computer = Player::new_computer(1, 100);
//! computer.add_guess(50);
//! if let Some((min, max)) = computer.get_computer_range() {
//!     println!("Computer thinking in range: {} - {}", min, max);
//! }
//! ```

/// Represents the type of player in the guessing game.
/// 
/// This enum distinguishes between human players and computer players,
/// allowing the game to handle different player behaviors appropriately.
/// 
/// # Examples
/// 
/// ```
/// use guessing_game::player::PlayerType;
/// 
/// let player_type = PlayerType::Human;
/// assert_eq!(player_type, PlayerType::Human);
/// assert_ne!(player_type, PlayerType::Computer);
/// ```
#[derive(PartialEq, Debug, Copy, Clone)]
pub enum PlayerType {
    /// A human player making manual guesses
    Human,
    /// A computer player using algorithmic strategies
    Computer,
}

/// Represents a player in the guessing game with associated state and behavior.
/// 
/// A `Player` maintains its own guess history and, for computer players,
/// strategic information like the current guessing range. This allows
/// multiple players to participate in games while maintaining separate
/// state and strategies.
/// 
/// # Examples
/// 
/// ```
/// use guessing_game::player::Player;
/// 
/// let mut player = Player::new_human();
/// player.add_guess(42);
/// player.add_guess(75);
/// 
/// assert_eq!(player.guesses(), &vec![42, 75]);
/// ```
#[derive(Debug)]
pub struct Player {
    player_type: PlayerType,
    guesses: Vec<u32>,
    // Computer-specific state
    computer_state: Option<ComputerState>,
}

/// Internal state for computer players to manage AI strategy.
/// 
/// This struct maintains the current guessing range for computer players,
/// allowing them to implement strategies like binary search. Human players
/// do not have this state.
/// 
/// # Fields
/// 
/// * `current_min` - The minimum value in the current guessing range
/// * `current_max` - The maximum value in the current guessing range
#[derive(Debug)]
pub struct ComputerState {
    current_min: u32,
    current_max: u32,
}

impl Player {
    /// Creates a new human player.
    /// 
    /// Human players start with an empty guess history and no computer-specific
    /// strategy state. They rely on manual input for making guesses.
    /// 
    /// # Returns
    /// 
    /// A new `Player` instance configured as a human player.
    /// 
    /// # Examples
    /// 
    /// ```
    /// use guessing_game::player::{Player, PlayerType};
    /// 
    /// let human = Player::new_human();
    /// assert_eq!(*human.player_type(), PlayerType::Human);
    /// assert!(human.guesses().is_empty());
    /// assert!(human.get_computer_range().is_none());
    /// ```
    pub fn new_human() -> Self {
        Player {
            player_type: PlayerType::Human,
            guesses: Vec::new(),
            computer_state: None,
        }
    }
    
    /// Creates a new computer player with an initial guessing range.
    /// 
    /// Computer players are initialized with a strategic guessing range that
    /// they can use to implement algorithms like binary search. The range
    /// represents the current bounds within which the computer believes
    /// the secret number lies.
    /// 
    /// # Arguments
    /// 
    /// * `min` - The minimum value of the initial guessing range (inclusive)
    /// * `max` - The maximum value of the initial guessing range (inclusive)
    /// 
    /// # Returns
    /// 
    /// A new `Player` instance configured as a computer player with the
    /// specified initial guessing range.
    /// 
    /// # Examples
    /// 
    /// ```
    /// use guessing_game::player::{Player, PlayerType};
    /// 
    /// let computer = Player::new_computer(1, 100);
    /// assert_eq!(*computer.player_type(), PlayerType::Computer);
    /// assert_eq!(computer.get_computer_range(), Some((1, 100)));
    /// ```
    pub fn new_computer(min: u32, max: u32) -> Self {
        Player {
            player_type: PlayerType::Computer,
            guesses: Vec::new(),
            computer_state: Some(ComputerState {
                current_min: min,
                current_max: max,
            }),
        }
    }

    /// Returns a reference to the player's type.
    /// 
    /// This method allows callers to determine whether they're dealing with
    /// a human or computer player, enabling type-specific behavior.
    /// 
    /// # Returns
    /// 
    /// A reference to the `PlayerType` enum variant.
    /// 
    /// # Examples
    /// 
    /// ```
    /// use guessing_game::player::{Player, PlayerType};
    /// 
    /// let human = Player::new_human();
    /// let computer = Player::new_computer(1, 100);
    /// 
    /// assert_eq!(*human.player_type(), PlayerType::Human);
    /// assert_eq!(*computer.player_type(), PlayerType::Computer);
    /// ```
    pub fn player_type(&self) -> &PlayerType {
        &self.player_type
    }

    /// Returns a reference to the player's guess history.
    /// 
    /// The guess history is maintained in chronological order, with the
    /// first guess at index 0 and the most recent guess at the end.
    /// 
    /// # Returns
    /// 
    /// A reference to a vector containing all guesses made by this player.
    /// 
    /// # Examples
    /// 
    /// ```
    /// use guessing_game::player::Player;
    /// 
    /// let mut player = Player::new_human();
    /// assert!(player.guesses().is_empty());
    /// 
    /// player.add_guess(42);
    /// player.add_guess(75);
    /// assert_eq!(player.guesses(), &vec![42, 75]);
    /// ```
    pub fn guesses(&self) -> &Vec<u32> {
        &self.guesses
    }

    /// Adds a guess to the player's history.
    /// 
    /// This method records a guess made by the player, maintaining the
    /// chronological order of all guesses. It works for both human and
    /// computer players.
    /// 
    /// # Arguments
    /// 
    /// * `guess` - The numerical guess to add to the player's history
    /// 
    /// # Examples
    /// 
    /// ```
    /// use guessing_game::player::Player;
    /// 
    /// let mut player = Player::new_human();
    /// player.add_guess(42);
    /// player.add_guess(75);
    /// player.add_guess(13);
    /// 
    /// assert_eq!(player.guesses(), &vec![42, 75, 13]);
    /// ```
    pub fn add_guess(&mut self, guess: u32) {
        self.guesses.push(guess);
    }

    /// Updates the computer player's guessing range.
    /// 
    /// This method allows computer players to refine their strategic guessing
    /// range based on feedback from previous guesses. For example, after a
    /// "too high" result, the computer can lower the maximum bound.
    /// 
    /// **Note**: This method has no effect on human players, as they don't
    /// maintain strategic range information.
    /// 
    /// # Arguments
    /// 
    /// * `min` - The new minimum value for the guessing range (inclusive)
    /// * `max` - The new maximum value for the guessing range (inclusive)
    /// 
    /// # Examples
    /// 
    /// ```
    /// use guessing_game::player::Player;
    /// 
    /// let mut computer = Player::new_computer(1, 100);
    /// assert_eq!(computer.get_computer_range(), Some((1, 100)));
    /// 
    /// // After a "too high" result for guess 75
    /// computer.update_computer_range(1, 74);
    /// assert_eq!(computer.get_computer_range(), Some((1, 74)));
    /// 
    /// // Method has no effect on human players
    /// let mut human = Player::new_human();
    /// human.update_computer_range(1, 100);
    /// assert!(human.get_computer_range().is_none());
    /// ```
    pub fn update_computer_range(&mut self, min: u32, max: u32) {
        if let Some(ref mut state) = self.computer_state {
            state.current_min = min;
            state.current_max = max;
        }
    }

    /// Gets the computer player's current guessing range.
    /// 
    /// This method returns the current strategic range for computer players,
    /// which represents the bounds within which the computer believes the
    /// secret number lies. Human players always return `None` since they
    /// don't maintain this information.
    /// 
    /// # Returns
    /// 
    /// * `Some((min, max))` - For computer players, returns a tuple containing
    ///   the current minimum and maximum guessing bounds (both inclusive)
    /// * `None` - For human players or if no range has been set
    /// 
    /// # Examples
    /// 
    /// ```
    /// use guessing_game::player::Player;
    /// 
    /// let computer = Player::new_computer(1, 100);
    /// assert_eq!(computer.get_computer_range(), Some((1, 100)));
    /// 
    /// let human = Player::new_human();
    /// assert_eq!(human.get_computer_range(), None);
    /// ```
    pub fn get_computer_range(&self) -> Option<(u32, u32)> {
        self.computer_state.as_ref().map(|state| (state.current_min, state.current_max))
    }
}