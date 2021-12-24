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

int main(int argc, char** argv)
{
	vector<int> deck; 

	for (int i = 3; i < 36; ++i)
	{
		deck.push_back(i);
	}

	// DEBUG_print_vector(deck, '-');
	deck = shuffle_deck(deck);
	DEBUG_print_vector(deck, '=');
	return 0;
}
