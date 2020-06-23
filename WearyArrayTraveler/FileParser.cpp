#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "FileParser.h"

using json = nlohmann::json;
using namespace std;

FileParser::FileParser(string filePath)
{
	this->fileName = filePath;
	this->dataBeenProcessed = false;
}

vector<int> FileParser::getData(void)
{
	if (dataBeenProcessed)
	{
		return data;
	}
	else
	{
		this->data = parseData(fileName);
		this->dataBeenProcessed = true;
		return data;
	}
}

/*Extracts file path extension*/
string FileParser::extractFileExtension(string fileName)
{
	size_t i = fileName.rfind('.', fileName.length());
	if (string::npos != i)
	{
		return(fileName.substr(i + 1, fileName.length() - i));
	}
	return("");
}

/*ensure given string contains digits only*/
bool FileParser::digitsOnly(string number)
{
	for (int i = 0; i < number.length(); i++)
	{
		if (!isdigit(number[i]))
		{
			return false;
		}
	}
	return true;
}

/* Parses delimiter-separated values file and returns the data in vector of integers.*/
vector<int> FileParser::parseDSVData(ifstream &file, const char delimiter)
{
	vector<int> dataList;
	int currentNum = 0;
	string numStiring = "";

	// Iterate through file first line and split its content using delimeter (no tolerance for white spaces or new lines).
	// If there's more than one line, exception is thrown.
	while (getline(file, numStiring, delimiter))//while (!file.eof())
	{
		if (!digitsOnly(numStiring))
		{
			throw exception("invalid input - csv and tsv input files should contain only non-negative integers seperate by tabs and commas respectively");
		}
		currentNum = stoi(numStiring);
		dataList.push_back(currentNum);
	}
	return dataList;
}

/* Parses json file and returns the data in vector of integers.*/
vector<int> FileParser::parseJsonData(ifstream &file)
{
	json j;
	vector<int> dataList;
	try
	{
		j = json::parse(file);
	}
	catch (const json::parse_error& e)
	{
		throw exception("invalid input - json input file should contain only one array of non-negative integers");
	}
	
	for (unsigned int numIdx = 0; numIdx < j.size(); numIdx++)
	{
		dataList.push_back(j[numIdx]);
	}
	return dataList;
}

/*
* Parses through the file and returns the data in vector of integers.
*/
vector<int> FileParser::parseData(string fileName)
{
	ifstream file(fileName);
	string fileExtension = extractFileExtension(fileName);
	vector<int> dataList;

	if ("csv" == fileExtension)
	{
		dataList = parseDSVData(file, ',');
	}
	else if ("tsv" == fileExtension)
	{
		dataList = parseDSVData(file, '\t');
	}
	else if ("json" == fileExtension)
	{
		dataList = parseJsonData(file);
	}
	else
	{
		throw std::exception("invalid input - file extension must be csv, tsv, or json");
	}
	return dataList;
}