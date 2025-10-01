use guessing_game::game_state::{GameState, GameStatus, GuessResult};
use guessing_game::player::{Player, PlayerType};

#[cfg(test)]
mod integration_tests {
    use super::*;

    #[test]
    fn test_human_player_game_integration() {
        let mut player = Player::new_human();
        let mut game = GameState::new(42, 42, 10); // Secret number is 42
        
        // Player makes some guesses
        let guess1 = 25;
        let result1 = game.make_guess(guess1);
        player.add_guess(guess1);
        
        let guess2 = 60;
        let result2 = game.make_guess(guess2);
        player.add_guess(guess2);
        
        let guess3 = 42;
        let result3 = game.make_guess(guess3);
        player.add_guess(guess3);
        
        // Verify results
        assert_eq!(result1, GuessResult::TooLow);
        assert_eq!(result2, GuessResult::TooHigh);
        assert_eq!(result3, GuessResult::Correct);
        
        // Verify game state
        assert_eq!(*game.game_status(), GameStatus::Won);
        assert_eq!(game.guesses(), &vec![25, 60, 42]);
        
        // Verify player state
        assert_eq!(*player.player_type(), PlayerType::Human);
        assert_eq!(player.guesses(), &vec![25, 60, 42]);
        assert!(player.get_computer_range().is_none());
    }

    #[test]
    fn test_computer_player_strategy_updates() {
        let mut computer = Player::new_computer(1, 100);
        let mut game = GameState::new(75, 75, 10); // Secret number is 75
        
        // Computer's initial strategy
        assert_eq!(computer.get_computer_range(), Some((1, 100)));
        
        // First guess: middle of range
        let guess1 = 50;
        let result1 = game.make_guess(guess1);
        computer.add_guess(guess1);
        
        // Update computer's range based on result
        if result1 == GuessResult::TooLow {
            if let Some((_, max)) = computer.get_computer_range() {
                computer.update_computer_range(guess1 + 1, max);
            }
        }
        
        assert_eq!(result1, GuessResult::TooLow);
        assert_eq!(computer.get_computer_range(), Some((51, 100)));
        
        // Second guess: middle of new range
        let guess2 = 75;
        let result2 = game.make_guess(guess2);
        computer.add_guess(guess2);
        
        assert_eq!(result2, GuessResult::Correct);
        assert_eq!(*game.game_status(), GameStatus::Won);
        
        // Verify both game and computer tracked the guesses
        assert_eq!(game.guesses(), &vec![50, 75]);
        assert_eq!(computer.guesses(), &vec![50, 75]);
    }

    #[test]
    fn test_multiple_players_single_game() {
        let mut human = Player::new_human();
        let mut computer = Player::new_computer(1, 100);
        let mut game = GameState::new(60, 60, 10); // Secret number is 60
        
        // Human makes first guess
        let human_guess = 30;
        let result1 = game.make_guess(human_guess);
        human.add_guess(human_guess);
        
        assert_eq!(result1, GuessResult::TooLow);
        
        // Computer makes second guess (using game feedback)
        let computer_guess = 80;
        let result2 = game.make_guess(computer_guess);
        computer.add_guess(computer_guess);
        
        // Update computer range based on result
        if result2 == GuessResult::TooHigh {
            if let Some((min, _)) = computer.get_computer_range() {
                computer.update_computer_range(min, computer_guess - 1);
            }
        }
        
        assert_eq!(result2, GuessResult::TooHigh);
        assert_eq!(computer.get_computer_range(), Some((1, 79)));
        
        // Human makes winning guess
        let winning_guess = 60;
        let result3 = game.make_guess(winning_guess);
        human.add_guess(winning_guess);
        
        assert_eq!(result3, GuessResult::Correct);
        assert_eq!(*game.game_status(), GameStatus::Won);
        
        // Verify game state
        assert_eq!(game.guesses(), &vec![30, 80, 60]);
        
        // Verify players maintained separate state
        assert_eq!(human.guesses(), &vec![30, 60]);
        assert_eq!(computer.guesses(), &vec![80]);
        assert!(human.get_computer_range().is_none());
        assert!(computer.get_computer_range().is_some());
    }

    #[test]
    fn test_single_player_multiple_games() {
        let mut player = Player::new_human();
        
        // First game
        let mut game1 = GameState::new(25, 25, 5);
        let result1 = game1.make_guess(25);
        player.add_guess(25);
        
        assert_eq!(result1, GuessResult::Correct);
        assert_eq!(*game1.game_status(), GameStatus::Won);
        
        // Second game (different secret number)
        let mut game2 = GameState::new(75, 75, 5);
        let result2 = game2.make_guess(50);
        player.add_guess(50);
        
        let result3 = game2.make_guess(75);
        player.add_guess(75);
        
        assert_eq!(result2, GuessResult::TooLow);
        assert_eq!(result3, GuessResult::Correct);
        assert_eq!(*game2.game_status(), GameStatus::Won);
        
        // Player should have all guesses from both games
        assert_eq!(player.guesses(), &vec![25, 50, 75]);
        
        // Games should be independent
        assert_eq!(game1.guesses(), &vec![25]);
        assert_eq!(game2.guesses(), &vec![50, 75]);
    }

    #[test]
    fn test_computer_ai_binary_search_strategy() {
        let mut computer = Player::new_computer(1, 100);
        let mut game = GameState::new(42, 42, 10); // Secret number is 42
        
        // Simulate a binary search strategy
        let mut guesses = Vec::new();
        
        // First guess: middle of range (1-100)
        let guess1 = 50;
        let result1 = game.make_guess(guess1);
        computer.add_guess(guess1);
        guesses.push((guess1, result1));
        
        // Update range based on result
        match result1 {
            GuessResult::TooHigh => {
                if let Some((min, _)) = computer.get_computer_range() {
                    computer.update_computer_range(min, guess1 - 1);
                }
            }
            GuessResult::TooLow => {
                if let Some((_, max)) = computer.get_computer_range() {
                    computer.update_computer_range(guess1 + 1, max);
                }
            }
            GuessResult::Correct => {}
        }
        
        assert_eq!(result1, GuessResult::TooHigh);
        assert_eq!(computer.get_computer_range(), Some((1, 49)));
        
        // Second guess: middle of new range (1-49)
        let guess2 = 25;
        let result2 = game.make_guess(guess2);
        computer.add_guess(guess2);
        guesses.push((guess2, result2));
        
        // Update range again
        match result2 {
            GuessResult::TooLow => {
                if let Some((_, max)) = computer.get_computer_range() {
                    computer.update_computer_range(guess2 + 1, max);
                }
            }
            _ => {}
        }
        
        assert_eq!(result2, GuessResult::TooLow);
        assert_eq!(computer.get_computer_range(), Some((26, 49)));
        
        // Third guess: middle of new range (26-49)
        let guess3 = 37;
        let result3 = game.make_guess(guess3);
        computer.add_guess(guess3);
        guesses.push((guess3, result3));
        
        // Update range based on result
        match result3 {
            GuessResult::TooLow => {
                if let Some((_, max)) = computer.get_computer_range() {
                    computer.update_computer_range(guess3 + 1, max);
                }
            }
            _ => {}
        }
        
        assert_eq!(result3, GuessResult::TooLow);
        
        // The computer is getting closer to the answer using binary search
        assert_eq!(computer.guesses(), &vec![50, 25, 37]);
        assert!(computer.get_computer_range().unwrap().0 > 37);
    }

    #[test]
    fn test_game_independence() {
        let mut game1 = GameState::new_with_defaults();
        let mut game2 = GameState::new_with_defaults();
        
        // Make different guesses in each game
        game1.make_guess(25);
        game1.make_guess(50);
        
        game2.make_guess(75);
        
        // Games should be completely independent
        assert_eq!(game1.guesses(), &vec![25, 50]);
        assert_eq!(game2.guesses(), &vec![75]);
        
        // Game statuses can be different
        assert_eq!(*game1.game_status(), GameStatus::InProgress);
        assert_eq!(*game2.game_status(), GameStatus::InProgress);
    }

    #[test]
    fn test_player_independence() {
        let mut player1 = Player::new_computer(1, 50);
        let mut player2 = Player::new_computer(51, 100);
        
        // Make different guesses and updates
        player1.add_guess(25);
        player1.update_computer_range(26, 50);
        
        player2.add_guess(75);
        player2.update_computer_range(51, 74);
        
        // Players should be completely independent
        assert_eq!(player1.guesses(), &vec![25]);
        assert_eq!(player2.guesses(), &vec![75]);
        assert_eq!(player1.get_computer_range(), Some((26, 50)));
        assert_eq!(player2.get_computer_range(), Some((51, 74)));
    }
}