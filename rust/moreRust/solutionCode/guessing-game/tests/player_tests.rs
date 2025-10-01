use guessing_game::player::{Player, PlayerType};

#[cfg(test)]
mod player_tests {
    use super::*;

    #[test]
    fn test_create_human_player() {
        let player = Player::new_human();
        
        assert_eq!(*player.player_type(), PlayerType::Human);
        assert_eq!(player.guesses().len(), 0);
        assert!(player.get_computer_range().is_none());
    }

    #[test]
    fn test_create_computer_player() {
        let min = 1;
        let max = 100;
        let player = Player::new_computer(min, max);
        
        assert_eq!(*player.player_type(), PlayerType::Computer);
        assert_eq!(player.guesses().len(), 0);
        assert_eq!(player.get_computer_range(), Some((min, max)));
    }

    #[test]
    fn test_add_guess_to_player() {
        let mut player = Player::new_human();
        
        player.add_guess(42);
        player.add_guess(75);
        player.add_guess(13);
        
        assert_eq!(player.guesses(), &vec![42, 75, 13]);
    }

    #[test]
    fn test_computer_range_updates() {
        let mut player = Player::new_computer(1, 100);
        
        // Initial range
        assert_eq!(player.get_computer_range(), Some((1, 100)));
        
        // Update range
        player.update_computer_range(26, 75);
        assert_eq!(player.get_computer_range(), Some((26, 75)));
        
        // Update again
        player.update_computer_range(51, 75);
        assert_eq!(player.get_computer_range(), Some((51, 75)));
    }

    #[test]
    fn test_human_player_range_update_has_no_effect() {
        let mut player = Player::new_human();
        
        // Should be None before
        assert!(player.get_computer_range().is_none());
        
        // Try to update range (should have no effect)
        player.update_computer_range(1, 100);
        
        // Should still be None
        assert!(player.get_computer_range().is_none());
    }

    #[test]
    fn test_player_type_equality() {
        assert_eq!(PlayerType::Human, PlayerType::Human);
        assert_eq!(PlayerType::Computer, PlayerType::Computer);
        assert_ne!(PlayerType::Human, PlayerType::Computer);
    }

    #[test]
    fn test_multiple_guesses_preserve_order() {
        let mut player = Player::new_computer(1, 50);
        
        let guesses = vec![25, 37, 31, 34, 32];
        for guess in &guesses {
            player.add_guess(*guess);
        }
        
        assert_eq!(player.guesses(), &guesses);
    }

    #[test]
    fn test_computer_range_edge_cases() {
        let mut player = Player::new_computer(50, 50);
        
        // Same min and max
        assert_eq!(player.get_computer_range(), Some((50, 50)));
        
        // Update to single number
        player.update_computer_range(42, 42);
        assert_eq!(player.get_computer_range(), Some((42, 42)));
    }

    #[test]
    fn test_empty_guesses_initially() {
        let human = Player::new_human();
        let computer = Player::new_computer(1, 100);
        
        assert!(human.guesses().is_empty());
        assert!(computer.guesses().is_empty());
    }

    #[test]
    fn test_computer_state_independence() {
        let mut player1 = Player::new_computer(1, 100);
        let mut player2 = Player::new_computer(50, 150);
        
        player1.update_computer_range(25, 75);
        player2.update_computer_range(100, 125);
        
        // Changes to one player shouldn't affect the other
        assert_eq!(player1.get_computer_range(), Some((25, 75)));
        assert_eq!(player2.get_computer_range(), Some((100, 125)));
    }
}