// 00009713

#include <iostream>
#include <time.h>
#include <vector>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int wordCount; // Input int
int librarySize = 20; // The size of words in the vector

void getWordsFromLibrary()
{
	std::vector<std::string> lib = { "Mistake", "Line", "Age", "Crab", "Wearable", "Caramel", "Chocolate", "Wood", "Tree", "Branch", "Lullaby", "Film", "Crown", "Chrome", "Moment", "Fog", "Invisible", 
	"Antelope", "Dove", "Blunder" }; // The vector of words

	std::cout << "The password is: ";

	if (wordCount > 0 && wordCount <= librarySize) // If wordcount is more than zero and less than the size of the library
	{
		srand(time(NULL)); // seeds the rand() function
		for (int i = 0; i < librarySize; i++) //shuffle the vector. loops untill i = librarySize while it add 1 to i each loop
		{
			int e = rand() % librarySize; // gives "e" a random number each loop
			std::string temp = lib[i]; //temp = i++ each loop
			lib[i] = lib[e]; // the i order is given the random number produced by e
			lib[e] = temp; // e = i++. This is important as not resetting e to i++ will lead to repeats

		}
		for (int i = 0; i < wordCount; i++) //print the output
		{
			std::cout <<lib[i];// prints the result of the pevious loop to the console
		}
		
	}

	else if (wordCount > librarySize) //if requested words is more than the library size
	{
		for (int i = 0; i < wordCount; i++) // loops untill i = wordCount while it add 1 to i each loop
		{
			std::cout <<lib[rand() % librarySize]; // chooses a random word in the library and prints them to the console
		}
	}

	else if (wordCount < 0) // if wordCount is a negative number
	{
		std::cout << "ERROR: not a positive number. Please type a positive number."; // Negative number error
	}

	else // if wordCount is not a number
	{
		std::cout << "ERROR: not a number. Please type a positive number."; // Not a number error
	}
}

int main()
{
	std::cout << "---------------------------------------\n"
				 "|          Pass Word Generator        |\n"
				 "---------------------------------------\n\n"; // Title

	std::cout << "Enter the ammount of words you would like to have in your password: "; // The text where the user inputs the number of words.
	std::cin >> wordCount; // How many words are in the password
	std::cout << "\n";
	if (wordCount >= 0) // If the request is less than 20 but more than zero
	{
			
		getWordsFromLibrary(); // output from function
		
	}
	_getch(); // makes sure that the console waits for an input from the user before closing
	std::cout << "\n\nThe app will now close";
	_getch();
}
