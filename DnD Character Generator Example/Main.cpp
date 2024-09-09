#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */ 
#include <iostream>


int RollD6()
{
	return rand() % ((6+1) - 1) + 1; // rand() % ((MAX+1) - MIN) + MIN) 
}

int GenerateAbilityScore()
{
	// Make an array full of 4 random dice rolls
	const int NUMDICE = 4;
	// Call the RollD6() function for each of our 4 rolls
	int dice[NUMDICE] = { RollD6(), RollD6(), RollD6(), RollD6() };

	// Find the lowest roll and store it and the index
	int lowest = 100;	// start with a high number above all rolls so one
						// will definitely be lower
	int lowestIndex = -1;	// start with an invalid index
	for (int i = 0; i < NUMDICE; ++i)
	{
		if (dice[i] < lowest)   // If the current array element is less than
								// the lowest stored value...
		{
			// ... then this element is the new lowest so far!
			lowest = dice[i]; // Store the lowest value
			lowestIndex = i; // Store the index
		}
	}

	// Add all elements together, but ignore the lowest!
	int total = 0;
	for (int i = 0; i < NUMDICE; ++i)
	{
		if (i != lowestIndex) // as long as this isn't the lowest score...
			total += dice[i]; // add it to the total
	}

	// return the total
	return total;
}

int main()
{
	srand(time(NULL));

	std::cout << GenerateAbilityScore() << "\n";
	std::cout << GenerateAbilityScore() << "\n";
	std::cout << GenerateAbilityScore() << "\n";
	std::cout << GenerateAbilityScore() << "\n";
	std::cout << GenerateAbilityScore() << "\n";
	std::cout << GenerateAbilityScore() << "\n";
	std::cout << GenerateAbilityScore() << "\n";

}