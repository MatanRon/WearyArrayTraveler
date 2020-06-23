#pragma once
#include <string>
#include <vector>
#include <gtest/gtest_prod.h>

using namespace std;

/*
 * A class to read and parse data from a file.
 */
class FileParser
{
public:
	FileParser(string filename);
	vector<int> getData(void);
private:
	FRIEND_TEST(FileParserTests, extractFileExtension);
	
	string fileName;
	string fileExtension;
	vector<int> data;
	bool dataBeenProcessed;

	static bool digitsOnly(string number);
	static vector<int> parseData(string fileName);
	static string extractFileExtension(string fileName);
	static vector<int> parseDSVData(ifstream &file, const char delimiter);
	static vector<int> parseJsonData(ifstream &file);
};