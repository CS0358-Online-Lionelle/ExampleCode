
mod game_state;
mod player;

use game_state::{GameState, GuessResult};
use player::Player;

fn main() {
    println!("Testing the modular guessing game!");
    
    // Test that both modules work independently
    test_player_module();
    test_game_state_module();
    test_integration();
}

fn test_player_module() {
    println!("\n=== Testing Player Module ===");
    let mut human_player = Player::new_human();
    let mut computer_player = Player::new_computer(1, 100);
    
    println!("Human player type: {:?}", human_player.player_type());
    println!("Computer player type: {:?}", computer_player.player_type());
    
    // Test player guessing history
    human_player.add_guess(50);
    human_player.add_guess(75);
    println!("Human guesses: {:?}", human_player.guesses());
    
    // Test computer range updates
    if let Some((min, max)) = computer_player.get_computer_range() {
        println!("Computer initial range: {} - {}", min, max);
    }
    
    computer_player.update_computer_range(26, 75);
    if let Some((min, max)) = computer_player.get_computer_range() {
        println!("Computer updated range: {} - {}", min, max);
    }
}

fn test_game_state_module() {
    println!("\n=== Testing GameState Module ===");
    let mut game = GameState::new_with_defaults();
    
    println!("Initial game status: {:?}", game.game_status());
    println!("Initial guesses: {:?}", game.guesses());
    
    let result1 = game.make_guess(50);
    println!("Guess 50 result: {:?}", result1);
    
    let result2 = game.make_guess(25);
    println!("Guess 25 result: {:?}", result2);
    
    println!("Final guesses: {:?}", game.guesses());
    println!("Final game status: {:?}", game.game_status());
}

fn test_integration() {
    println!("\n=== Testing Integration ===");
    // Test with separate player instances
    let mut human_player = Player::new_human();
    let mut computer_player = Player::new_computer(1, 100);
    
    // Test game state (now decoupled from players)
    let mut game = GameState::new_with_defaults();
    
    // Test making a guess - game tracks its own state
    let result = game.make_guess(50);
    println!("Made guess 50, result: {:?}", result);
    println!("Game's guesses: {:?}", game.guesses());
    
    // Players can maintain their own state independently
    human_player.add_guess(50);
    
    // Computer player can update its strategy based on game feedback
    match result {
        GuessResult::TooHigh => {
            if let Some((min, _)) = computer_player.get_computer_range() {
                computer_player.update_computer_range(min, 49);
            }
        }
        GuessResult::TooLow => {
            if let Some((_, max)) = computer_player.get_computer_range() {
                computer_player.update_computer_range(51, max);
            }
        }
        GuessResult::Correct => {
            println!("Computer would have won!");
        }
    }
    
    computer_player.add_guess(50);
    if let Some((min, max)) = computer_player.get_computer_range() {
        println!("Computer updated range after guess: {} - {}", min, max);
    }
    
    println!("Demonstration complete - modules work independently and together!");
}
