use guessing_game::game_state::{GameState, GameStatus, GuessResult};

#[cfg(test)]
mod game_state_tests {
    use super::*;

    #[test]
    fn test_new_game_state() {
        let game = GameState::new(1, 100, 10);
        
        assert_eq!(*game.game_status(), GameStatus::InProgress);
        assert_eq!(game.guesses().len(), 0);
        assert!(game.guesses().is_empty());
    }

    #[test]
    fn test_new_with_defaults() {
        let game = GameState::new_with_defaults();
        
        assert_eq!(*game.game_status(), GameStatus::InProgress);
        assert_eq!(game.guesses().len(), 0);
    }

    #[test]
    fn test_make_guess_too_low() {
        let mut game = GameState::new(50, 50, 10); // Secret number is always 50
        
        let result = game.make_guess(25);
        
        assert_eq!(result, GuessResult::TooLow);
        assert_eq!(*game.game_status(), GameStatus::InProgress);
        assert_eq!(game.guesses(), &vec![25]);
    }

    #[test]
    fn test_make_guess_too_high() {
        let mut game = GameState::new(50, 50, 10); // Secret number is always 50
        
        let result = game.make_guess(75);
        
        assert_eq!(result, GuessResult::TooHigh);
        assert_eq!(*game.game_status(), GameStatus::InProgress);
        assert_eq!(game.guesses(), &vec![75]);
    }

    #[test]
    fn test_make_guess_correct() {
        let mut game = GameState::new(50, 50, 10); // Secret number is always 50
        
        let result = game.make_guess(50);
        
        assert_eq!(result, GuessResult::Correct);
        assert_eq!(*game.game_status(), GameStatus::Won);
        assert_eq!(game.guesses(), &vec![50]);
    }

    #[test]
    fn test_multiple_guesses() {
        let mut game = GameState::new(50, 50, 10); // Secret number is always 50
        
        let result1 = game.make_guess(25);
        let result2 = game.make_guess(75);
        let result3 = game.make_guess(40);
        
        assert_eq!(result1, GuessResult::TooLow);
        assert_eq!(result2, GuessResult::TooHigh);
        assert_eq!(result3, GuessResult::TooLow);
        assert_eq!(*game.game_status(), GameStatus::InProgress);
        assert_eq!(game.guesses(), &vec![25, 75, 40]);
    }

    #[test]
    fn test_lose_game_max_guesses() {
        let mut game = GameState::new(50, 50, 3); // Secret number is 50, max 3 guesses
        
        game.make_guess(25); // Too low
        game.make_guess(75); // Too high
        let result = game.make_guess(30); // Too low, 3rd guess
        
        assert_eq!(result, GuessResult::TooLow);
        assert_eq!(*game.game_status(), GameStatus::Lost);
        assert_eq!(game.guesses().len(), 3);
    }

    #[test]
    fn test_win_before_max_guesses() {
        let mut game = GameState::new(50, 50, 10); // Secret number is 50, max 10 guesses
        
        game.make_guess(25); // Too low
        let result = game.make_guess(50); // Correct
        
        assert_eq!(result, GuessResult::Correct);
        assert_eq!(*game.game_status(), GameStatus::Won);
        assert_eq!(game.guesses().len(), 2);
    }

    #[test]
    #[should_panic(expected = "Game is already over")]
    fn test_panic_on_guess_after_win() {
        let mut game = GameState::new(50, 50, 10);
        
        game.make_guess(50); // Win the game
        game.make_guess(25); // Should panic
    }

    #[test]
    #[should_panic(expected = "Game is already over")]
    fn test_panic_on_guess_after_loss() {
        let mut game = GameState::new(50, 50, 1); // Only 1 guess allowed
        
        game.make_guess(25); // Lose the game
        game.make_guess(50); // Should panic
    }

    #[test]
    fn test_game_status_equality() {
        assert_eq!(GameStatus::InProgress, GameStatus::InProgress);
        assert_eq!(GameStatus::Won, GameStatus::Won);
        assert_eq!(GameStatus::Lost, GameStatus::Lost);
        assert_ne!(GameStatus::InProgress, GameStatus::Won);
        assert_ne!(GameStatus::Won, GameStatus::Lost);
    }

    #[test]
    fn test_guess_result_equality() {
        assert_eq!(GuessResult::TooLow, GuessResult::TooLow);
        assert_eq!(GuessResult::TooHigh, GuessResult::TooHigh);
        assert_eq!(GuessResult::Correct, GuessResult::Correct);
        assert_ne!(GuessResult::TooLow, GuessResult::TooHigh);
        assert_ne!(GuessResult::TooHigh, GuessResult::Correct);
    }

    #[test]
    fn test_correct_answer_method() {
        let game = GameState::new(42, 42, 10); // Secret number is always 42
        assert_eq!(game.correct_answer(), 42);
    }

    #[test]
    fn test_is_game_over_method() {
        let mut game = GameState::new(50, 50, 10);
        
        // Game should not be over initially
        assert!(!game.is_game_over());
        
        // Game should not be over after wrong guess
        game.make_guess(25);
        assert!(!game.is_game_over());
        
        // Game should be over after correct guess
        game.make_guess(50);
        assert!(game.is_game_over());
    }

    #[test]
    fn test_is_game_over_on_loss() {
        let mut game = GameState::new(50, 50, 1); // Only 1 guess allowed
        
        assert!(!game.is_game_over());
        
        game.make_guess(25); // Wrong guess, should lose
        assert!(game.is_game_over());
    }

    #[test]
    fn test_empty_guesses_initially() {
        let game = GameState::new_with_defaults();
        assert!(game.guesses().is_empty());
    }

    #[test]
    fn test_random_secret_number_in_range() {
        // Test multiple games to ensure secret number is in range
        for _ in 0..10 {
            let game = GameState::new(10, 20, 5);
            let secret = game.correct_answer();
            assert!(secret >= 10 && secret <= 20);
        }
    }

    #[test]
    fn test_different_secret_numbers() {
        // Test that different games have potentially different secret numbers
        let mut secrets = std::collections::HashSet::new();
        for _ in 0..50 {
            let game = GameState::new(1, 100, 10);
            secrets.insert(game.correct_answer());
        }
        // With a range of 1-100 and 50 games, we should get multiple different numbers
        assert!(secrets.len() > 1, "Expected multiple different secret numbers");
    }
}