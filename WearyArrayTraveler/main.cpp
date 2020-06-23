#include "wearyArrayTraveler.h"
#include <iostream>

int main()
{
	string filePath;

	bool result = false;
	cout << "*** Weary Array Traveler ***" << endl;
	cout << "Please enter a path to one of the following:" << endl;
	cout << "1) .csv file - contains only one row of positive integers (separated by commas)." << endl;
	cout << "2) .tsv file - contains only one row of positive integers (separated by tabs)." << endl;
	cout << "3) .json file - contains only one row with one array of positive integers." << endl;
	
	while (true)
	{
		getline(cin, filePath);

		try
		{
			result = runTraveler(filePath);
		}
		catch (const exception& e)
		{
			cout << e.what() << endl;
		}

		if (result)
		{
			cout << "there is a path between first index and last index :)" << endl << endl;
		}
		else
		{
			cout << "there is no path between first index and last index :(" << endl << endl;
		}
		cout << "Please insert new file path" << endl << endl;
	}
	return 0;
}