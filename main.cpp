#include <iostream>
#include <cstdlib> // for std::rand() and std::srand()
#include <time.h>
#include <stdlib.h>

using namespace std;

bool playAgain();
bool playGame(int , int );

int main()
{
    //std::random_device rd;
    //std::mt19937 mersenne(rd());    // Create a mersenne twister, seeded using the random device
    //std::uniform_int_distribution<> die(1, 100);    // generate random numbers btw 1 and 100
    std::srand(time(NULL)); // set initial seed value to 'time'
    const int guesses = 7;  // the player has this number of guesses

    do // while the user still want to play
    {
        system("CLS");
        //int number = die(mersenne); /// this number the player needs to guess
        int number = rand() % 100 + 1;
        std::cout << "Let's play a game.  I'm thinking of a number.  \nYou have " << guesses << " tries to guess what it is.\n";
        bool won = playGame(guesses, number);
        if (won)
        {
            std::cout << "Correct!  You win!\n";
        }
        else
        {
            std::cout << "Sorry, you lose.  The correct number was " << number << "\n";
        }

    } while (playAgain());

    cout << "Thank for your playing.\n";
    return 0;

}

bool playAgain()
{
    /// Keep asking the user if they want to play again until they pick y or n.
    char ch;
    do
    {
        cout << "Would you like to play again (y/n): ";
        cin >> ch;
    } while ((ch != 'y') && (ch != 'n'));

    /// True if ans = 'y'
    return (ch == 'y');
}

/// returns true if the user won, false if they lost
bool playGame(int guesses, int number)
{
    for (int count =0; count < guesses; ++count)
    {
        std::cout << "Guess #" << count << ": ";
        int i_guess;
        cin >> i_guess;

        if (i_guess > number)
		std::cout << "Your guess is too high.\n";
	else if (i_guess < number)
		std::cout << "Your guess is too low.\n";
	else /// guess == number
        	return true;
    }

    return false;

}
