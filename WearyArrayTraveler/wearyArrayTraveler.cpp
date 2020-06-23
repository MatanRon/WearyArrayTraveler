#include <vector>
#include "FileParser.h"
using namespace std;

/*
* This function performs the recursive calls.
* in each recursive call the sourceIndex value is updated to the appropriate index value and a boolean value is returned according
* to the stop conditions.
* during this process, a boolean vector (visited) is constantly updated according to the indexes which had already visited 
* in order to avoid loops and unnecessary recalculations.

* Time complexity: O(N) (Where N is the number of elements in the array)
*/
bool wearyArrayTravelerRec(vector<int> numbers, std::vector<bool>& visited, int numbersLength, int sourceIndex, int targetIndex)
{
	if (0 == numbersLength) //The input vector is empty
	{
		return false;
	}
	if (1 == numbersLength)// The trivial solution - the first and last index are both 0.
	{
		return true;
	}
	if ( 0 > sourceIndex || sourceIndex >= numbersLength) // index out of vector range.
	{
		return false;
	}
	if (visited[sourceIndex]) // This path has already been visited so there's no need to check it again.
	{
		return false;
	}
	if (sourceIndex + numbers[sourceIndex] == targetIndex) // the target has been reached
	{
		return true;
	}

	// If none of the above stop conditions occurred, mark the current vertex as visited and make the recursive calls
	// with the corresponding vertices.
	visited[sourceIndex] = true;

	return wearyArrayTravelerRec(numbers, visited, numbersLength, sourceIndex + numbers[sourceIndex], targetIndex) ||
		wearyArrayTravelerRec(numbers, visited, numbersLength, sourceIndex - numbers[sourceIndex], targetIndex);
}

/*
* This function wraps the recursive function. 
* It receives the integers vector and initializes the resources needed for wearyArrayTravelerRec()
*/
bool wearyArrayTraveler(vector<int> numbers)
{
	int numberOfVertices = numbers.size();
	std::vector<bool> visited;
	visited.resize(numberOfVertices, false);
	bool result = wearyArrayTravelerRec(numbers, visited, numberOfVertices, 0, numberOfVertices - 1);
	return result;
}

/*
* receives a file path, Imports the information from it by creating FileReader instance
* and finally passes it on to the logic execution.
*/
bool runTraveler(string filePath)
{	
	FileParser file(filePath);
	vector<int> numbers = file.getData();

	return wearyArrayTraveler(numbers);
}
 