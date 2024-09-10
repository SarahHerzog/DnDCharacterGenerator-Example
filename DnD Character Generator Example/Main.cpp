#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */ 
#include <iostream>
#include <math.h> 
#include <map>


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

int CalculateAbilityBonus(int score)
{
	return floor(((float)(score - 10)) / 2);
}

void PrintAbilityScore(std::string name, int score)
{
	std::cout << name << ": " << score << " (" << CalculateAbilityBonus(score) << ")\n";
}

int main()
{
	srand(time(NULL));

	std::map<std::string, int> abilityScores;

	abilityScores["Strength"] = GenerateAbilityScore();
	abilityScores["Dexterity"] = GenerateAbilityScore();
	abilityScores["Constitution"] = GenerateAbilityScore();
	abilityScores["Intelligence"] = GenerateAbilityScore();
	abilityScores["Wisdom"] = GenerateAbilityScore();
	abilityScores["Charisma"] = GenerateAbilityScore();
	
	PrintAbilityScore("Strength", abilityScores["Strength"]);
	PrintAbilityScore("Dexterity", abilityScores["Dexterity"]);
	PrintAbilityScore("Constitution", abilityScores["Constitution"]);
	PrintAbilityScore("Intelligence", abilityScores["Intelligence"]);
	PrintAbilityScore("Wisdom", abilityScores["Wisdom"]);
	PrintAbilityScore("Charisma", abilityScores["Charisma"]);
}