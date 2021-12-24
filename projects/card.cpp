#include <iostream> 
#include <vector>
#include <random>


using namespace std;

void DEBUG_create_spacer(char c)
{
	for (int i = 0; i < 80; ++i)
	{
		cout << c;
	}
	cout << endl;
}

void DEBUG_print_vector(vector<int> vector, char c)
{
	DEBUG_create_spacer(c);
	for (int i = 0; i < vector.size(); ++i)	
	{
		cout << "Index: " << i << " | Value: " << vector.at(i) << endl;
	}	
	DEBUG_create_spacer(c);
}

vector<int> shuffle_deck(vector<int> deck)
{
	/*
	 *	This algorithm is inspired by the Fisher-Yates shuffle
	 *
	 *	(1) Write down the numbers from 1 through N
	 *	(2) Pick a random number k between one and the number of unstruck numbers
	 *	(3) Counting from the low end, strick out the kth number, and write it down
	 *	(4) Repeat step 2 until all numbers are struck out
	 */
	vector<int> result;
	while (deck.size() != 0)
	{
		// Generates the random number
		size_t random_number = rand() % deck.size();
		// Erase that element from the first list, and put it onto the second list.
		result.push_back(deck.at(random_number));
		deck.erase(deck.begin() + random_number);
	}
	return result;
}

/*
 *	TODO
 */

void binary_search(vector<int> v, int key)
{

}

/*
 *	TODO
 */
int calculate_score(vector<int> hand)
{
	return 0;
}

void insert_to_hand(int card, vector<int> hand)
{


}

class Player
{
	public:
		int score;
		int chips;
		vector<int> hand;

		Player()
		{
			score = 0;
			chips = 11;
		};

		void addCard(int card)
		{
			score = calculate_score(hand);
			insert_to_hand(card, hand);
			// hand.push_back(points);
		}
};

/*
 * 	Parameters:
 * 		deck_size - Number of cards in the deck from 3 to N.
 * 		cards_removed - Number of cards to be removed from the deck
 *	Returns:
 *	 	The starting deck for "No Thanks"
 */
vector<int> setup_deck(int deck_size, int cards_removed)
{
	vector<int> deck; 
	// Creates 3 to deck_size number of cards
	for (int i = 3; i < deck_size; ++i)
	{
		deck.push_back(i);
	}
	deck = shuffle_deck(deck);
	// Removes cards_removed # of cards from the deck
	for (int j = 0; j < cards_removed; ++j)
	{
		deck.pop_back();
	}
	return deck;
}
/*
 *	Initializes the number of players
 */
vector<Player> setup_players(int number_of_players)
{
	vector<Player> Players;
	for (int i = 0; i < number_of_players; ++i)
	{
		Player new_player = Player();	
		Players.push_back(new_player);
	}	
	return Players;
}

int PLAYER_SELECT_OPTION()
{
	DEBUG_create_spacer('-');
	cout << "(1) Keep the card\n(2) Pay a chip to pass\n";
	DEBUG_create_spacer('-');

	int player_input;
	cin >> player_input;
	return player_input;
}

/*
 *	This function checks if the player has enough chips to 'skip' the card in play
 *	
 *	Returns:
 *		True if check passes
 *		False if not enough chips
 */
bool CHECK_FOR_CHIPS(Player player)
{
	if (player.chips > 0)
	{
		return true;
	}
	return false;
}

/*
 *
 *
 */
int main(int argc, char** argv)
{
	int const DECK_SIZE = 35;
	int const CARDS_REMOVED = 9;
	// int const STARTING_CHIPS = 11;
	int const NUMBER_OF_PLAYERS = 1;
	
	cout << "{Introduction to 'No Thanks'}" << endl;

	cout << "Setting up the deck..." << endl;
	vector<int> Deck = setup_deck(DECK_SIZE, CARDS_REMOVED);
	cout << "Creating the number of players..." << endl;
	vector<Player> Players = setup_players(NUMBER_OF_PLAYERS);
	
	// Main game loop
	int current_card = Deck.at(0);
	Player current_player = Players.at(0);
	int choice = PLAYER_SELECT_OPTION();
	if (choice == 1) 
	{
		current_player.addCard(current_card);
	}
	else if (choice == 2)
	{
		bool CHIP_FLAG = CHECK_FOR_CHIPS(current_player);
		if (CHIP_FLAG == true)
		{
			current_player.chips -= 1;
			// Move the game engine to the next player. 
		}
		else
		{
			cout << "Not enough chips.\nYou must take the current card\n";
		}
	}

	return 0;
}
