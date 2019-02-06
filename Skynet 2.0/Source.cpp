#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void theChoice();

void main()
{
	srand(time(0));
	int searchGridHighNumber = 64; // This is the highest number on the grid
	int searchGridLowNumber = 1; // This is the lowest number on the grid
	int enemyLocation = rand() % 64; // This choses a random number between 1 and 64 for the enemy to be located in

	// Declaring the predictions that each program will make
	int binaryTargetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber; // The binary search calculates the middle most number and determines if the actual number is higher or lower than the guess
	int playerTargetLocationPredction;
	int linearTargetLocationPrediction = 0;
	int randomTargetLocationPrediction = rand() % 64;

	// Declaring bools if the location was found for each program, giving the program a way to exit each loop
	bool binaryEnemyLocationFound = false;
	bool linearEnemyLocationFound = false;
	bool randomEnemyLocationFound = false;
	bool playerEnemyLocationFound = false;

	//The number of predictions the program made before finding the enemy
	int binarySearchPredictionNumber = 0;
	int linearSeachPredictionNumber = 0;
	int randomSearchPredictionNumber = 0;
	int playerSearchPredictionNumber = 0;

	char playerChoice;

	cout << "Initializing Skynet HK Search Program" << endl;
	cout << "Generating random enemy location..." << endl;
	cout << "The enemy is located at grid number REDACTED" << endl;

	while (playerEnemyLocationFound == false) // While loop that loops until the player guesses the right number
	{
		cout << "Please enter your prediction of the enemy location" << endl;
		cin >> playerTargetLocationPredction; // Getting the player's guess

		if (playerTargetLocationPredction > enemyLocation) // If the player's guess is larger than the enemy location
		{
			cout << "The enemy location is lower than " << playerTargetLocationPredction << endl; 
			playerSearchPredictionNumber++;
		}
		else if (playerTargetLocationPredction < enemyLocation) // If the player's guess is lower than the enemy locaton
		{
			cout << "The enemy location is greater than " << playerTargetLocationPredction << endl;
			playerSearchPredictionNumber++;
		}
		else if (playerTargetLocationPredction == enemyLocation) // If the player's guess is spot on
		{
			cout << "Direct hit, ENEMY FOUND" << endl;
			playerSearchPredictionNumber++;
			cout << "The player took " << playerSearchPredictionNumber << " guesses to find the enemy\n";
			playerEnemyLocationFound = true;
			system("Pause");
		}
	}

	while (linearEnemyLocationFound == false) // While loop that loops until the linear program finds the enemy location
	{
		cout << "\n\nThe linear search guesses the location " << linearTargetLocationPrediction << endl;

		if (linearTargetLocationPrediction != enemyLocation) // If the linear guess is not the enemy location
		{
			cout << linearTargetLocationPrediction << " was not the correct location" << endl;
			linearSeachPredictionNumber++;
			linearTargetLocationPrediction++;
		}
		else if (linearTargetLocationPrediction == enemyLocation) // If the linear guess is spot on
		{
			cout << "The linear program has found the enemy! ENEMY FOUND" << endl;
			linearSeachPredictionNumber++;
			cout << "The linear program took " << linearSeachPredictionNumber << " tries to find the enemy\n";
			linearEnemyLocationFound = true;
			system("Pause");
		}
	}

	while (randomEnemyLocationFound == false) // While loop that loops until the random program finds the enemy location
	{
		cout << "\n\nBooting Up the Random Program" << endl;
		cout << "The Random Program guesses " << randomTargetLocationPrediction << endl;
		if (randomTargetLocationPrediction != enemyLocation) // if the random guess is not the enemy location
		{
			cout << "That is not the correct location" << endl;
			randomSearchPredictionNumber++;
			randomTargetLocationPrediction = rand() % 64;
		}
		else if (randomTargetLocationPrediction == enemyLocation) // if the random program is spot on
		{
			cout << "Direct hit! ENEMY FOUND" << endl;
			randomSearchPredictionNumber++;
			cout << "The Random Program took " << randomSearchPredictionNumber << " guesses to find the enemy" << endl;
			randomEnemyLocationFound = true;
			system("Pause");
		}
	}

	while (binaryEnemyLocationFound == false) // While loop that loops until the binary program guesses the enemy location
	{
		binaryTargetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		cout << "\n\nThe software has pinged grid location " << binaryTargetLocationPrediction << endl;
		cout << "This is the software's guess number " << binarySearchPredictionNumber << endl;

		if (binaryTargetLocationPrediction > enemyLocation) // if the binary guesses higher than the enemy location
		{
			cout << "The enemy's location is lower than the predicted location" << endl;
			searchGridHighNumber = binaryTargetLocationPrediction - 1;
			binarySearchPredictionNumber++;
		}
		else if (binaryTargetLocationPrediction < enemyLocation) // if the binary guesses lower than the enemy location
		{
			cout << "The enemy's location is higher than the predicted location" << endl;
			searchGridLowNumber = binaryTargetLocationPrediction + 1;
			binarySearchPredictionNumber++;
		}
		else if (binaryTargetLocationPrediction == enemyLocation) // if the binary is spot on
		{
			cout << "The prediction is spot on, ENEMY FOUND!" << endl;
			binarySearchPredictionNumber++;
			binaryEnemyLocationFound = true;
		}
	}
	// Displaying the coutcomes for the player
	cout << "\n\nSkynet Outcomes" << endl;
	cout << "The Player took " << playerSearchPredictionNumber << " guesses to find the enemy" << endl;
	cout << "The Linear Program took " << linearSeachPredictionNumber << " guesses to find the enemy" << endl;
	cout << "The Random Program took " << randomSearchPredictionNumber << " guesses to find the enemy" << endl;
	cout << "The Binary Program took " << binarySearchPredictionNumber << " guesses to find the enemy" << endl;
	system("Pause");
	theChoice();
}
void theChoice() // adding a function to redo the loop if the player chooses to play again
{
	char playerChoice; // variable to hold the choice

	cout << "Would you like to play again? Y or N" << endl;
	cin >> playerChoice;

	if (playerChoice == 'Y') // if the player inputs Y the loop will start over, thus playing the game again
	{
		main();
	}
	else if (playerChoice == 'N') // if the player inputs N the application will close
	{
		return;
	}
	else if (playerChoice) // If they put in something else it will close
	{
		cout << "Illegal input, closing application" << endl;
		system("Pause");
		return;
	}
}