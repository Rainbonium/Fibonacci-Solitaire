#include "Deck.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// Check if a number is a Fibonacci number.
bool isFibonacci(int n) {
	int a = 0, b = 1, c = 0;
	while (c < n) {
		c = a + b;
		a = b;
		b = c;
	}
	return c == n;
}

int main()
{
	Deck mainDeck;
	int option = 0;
	srand(std::time(0)); // Seed randomness.

	do {
		cout << "Welcome to Fibonacci Solitaire!\n1) Create New Deck\n2) Shuffle Deck\n3) Display Deck\n4) Play Fibo Solitaire\n5) Win Fibo Solitaire\n6) Exit\nEnter your choice: ";
		cin >> option;
		cout << "\n";

		switch (option) {
		case 1:
			cout << "Created new deck!\n\n";
			mainDeck.resetDeck();
			break;
		case 2:
			cout << "Deck shuffled!\n\n";
			mainDeck.shuffle();
			break;
		case 3:
			mainDeck.show();
			break;
		case 4:
		{
			cout << "Playing Fibonacci Solitaire Once!\n";
			int sum = 0;
			int fibCount = 0;
			vector<Card> pile;
			mainDeck.resetDeck();
			mainDeck.shuffle();

			while (!mainDeck.isEmpty()) {
				Card card = mainDeck.deal();
				pile.push_back(card);
				sum += card.getValue();

				// Check if the sum is a Fibonacci number.
				if (isFibonacci(sum)) {
					cout << "Fibonacci pile: ";
					for (const auto& card : pile) {
						card.show();
						cout << " ";
					}
					cout << " Fibo: " << sum << "\n";
					fibCount++;
					pile.clear();
					sum = 0;
				}
			}

			// Check if the last pile is a Fibonacci pile.
			if (isFibonacci(sum)) {
				cout << "Winner! There were " << fibCount + 1 << " Fibonacci piles.\n\n";
			}
			else {
				cout << "Loser!\n\n";
			}
			break;
		}
		case 5:
		{
			cout << "Playing Fibonacci Solitaire Until Win!\n";
			int games = 0;
			bool foundWinner = false;

			while (foundWinner == false) {
				int sum = 0;
				int fibCount = 0;
				vector<Card> pile;
				mainDeck.resetDeck();
				mainDeck.shuffle();

				cout << endl;

				while (!mainDeck.isEmpty()) {
					Card card = mainDeck.deal();
					pile.push_back(card);
					sum += card.getValue();

					// Check if the sum is a Fibonacci number.
					if (isFibonacci(sum)) {
						cout << "Fibonacci pile: ";
						for (const auto& card : pile) {
							card.show();
							cout << " ";
						}
						cout << " Fibo: " << sum << "\n";
						fibCount++;
						pile.clear();
						sum = 0;
					}
				}

				// Check if the last pile is a Fibonacci pile.
				games++;
				if (isFibonacci(sum)) {
					foundWinner = true;
					cout << "Winner! There were " << fibCount + 1 << " Fibonacci piles. Won in "<< games << " games!\n\n";
					break;
				}
				else {
					cout << "Loser!\n";
				}
			}
			break;
		}
		case 6:
			cout << "Thanks for playing fibo solitaire!\n\n";
		default:
			break;
		}
	} while (option != 6);

	return 0;
}