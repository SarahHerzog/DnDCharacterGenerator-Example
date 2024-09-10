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
	return floor((score - 10) / 2.0f);
}

void PrintAbilityScore(std::string name, int score)
{
	std::cout << name << ": " << score << " (" << CalculateAbilityBonus(score) << ")\n";
}

bool QualifiesForWizard(std::map<std::string, int> scores)
{
	return scores["Intelligence"] >= 13;
}

bool QualifiesForBard(std::map<std::string, int> scores)
{
	return scores["Charisma"] >= 13;
}

bool QualifiesForRogue(std::map<std::string, int> scores)
{
	return scores["Dexterity"] >= 13;
}

bool QualifiesForFighter(std::map<std::string, int> scores)
{
	return scores["Strength"] >= 13;
}

void PrintAbilityScores(std::map<std::string, int> scores)
{
	PrintAbilityScore("Strength", scores["Strength"]);
	PrintAbilityScore("Dexterity", scores["Dexterity"]);
	PrintAbilityScore("Constitution", scores["Constitution"]);
	PrintAbilityScore("Intelligence", scores["Intelligence"]);
	PrintAbilityScore("Wisdom", scores["Wisdom"]);
	PrintAbilityScore("Charisma", scores["Charisma"]);
}

int main()
{
	srand(time(NULL));

	bool rollNewCharacter = true;

	while (rollNewCharacter)
	{
		std::map<std::string, int> abilityScores;

		abilityScores["Strength"] = GenerateAbilityScore();
		abilityScores["Dexterity"] = GenerateAbilityScore();
		abilityScores["Constitution"] = GenerateAbilityScore();
		abilityScores["Intelligence"] = GenerateAbilityScore();
		abilityScores["Wisdom"] = GenerateAbilityScore();
		abilityScores["Charisma"] = GenerateAbilityScore();

		PrintAbilityScores(abilityScores);

		bool qualifiesForAnyClass = QualifiesForWizard(abilityScores) || QualifiesForBard(abilityScores) || QualifiesForFighter(abilityScores) || QualifiesForRogue(abilityScores);

		if (qualifiesForAnyClass)
		{
			std::cout << "This character qualifies to be:\n";
			if (QualifiesForWizard(abilityScores))
				std::cout << "   - Wizard\n";
			if (QualifiesForBard(abilityScores))
				std::cout << "   - Bard\n";
			if (QualifiesForRogue(abilityScores))
				std::cout << "   - Rogue\n";
			if (QualifiesForFighter(abilityScores))
				std::cout << "   - Fighter\n";
		}
		else
		{
			std::cout << "This character does not qualify for any classes.\n";
		}

		std::cout << "Would you like to reroll your stats? (Y/N)\n";
		std::string answer;
		std::cin >> answer;

		if (answer == "N" || answer == "n")
		{
			rollNewCharacter = false;
		}
	}

}