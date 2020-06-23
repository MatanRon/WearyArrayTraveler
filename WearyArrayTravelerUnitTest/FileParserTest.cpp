#include "pch.h"
#include "FileParser.h"


/*Test purpose: ensure the file extension is extracted properly*/
TEST(FileParserTests, extractFileExtension) 
{
	string path = "a.b_c\4.json";
	string expectedResult = "json";
	FileParser parser(path);
	string extension = parser.extractFileExtension(path);
	EXPECT_TRUE(expectedResult == extension);
	cout << "expectedResult: " << expectedResult << "	actual result: " << extension << endl << endl;
}

/*Test purpose: If a file path with an unsupported extension is received, an exception should be thrown*/
TEST(FileParserTests, parseInvalidFilePath)
{
	string path = "a.b_c\4.txt";
	FileParser parser(path);

	EXPECT_ANY_THROW(parser.getData());
}

/*Test purpose: If a json file with an unsupported format content is received, an exception should be thrown*/
TEST(FileParserTests, parseInvalidJson)
{
	string path = "../TestInputFiles/invalidJson.json";
	FileParser parser(path);

	EXPECT_ANY_THROW(parser.getData());
}

/*Test purpose: Ensure data (numbers vector) is extracted properly given json file path*/
TEST(FileParserTests, parseValidJson)
{
	string path = "../TestInputFiles/validJsonTrueExpected.json";
	FileParser parser(path);
	vector<int> expectedResult = { 4, 4, 1, 1, 2, 2, 1000, 1 };
	vector<int> result = parser.getData();

	EXPECT_TRUE(expectedResult == result);
}

/*Test purpose: If TSV file with an unsupported format content is received, an exception should be thrown*/
TEST(FileParserTests, parseInvalidTSV)
{
	string path = "../TestInputFiles/invalidTSV.tsv";
	FileParser parser(path);

	EXPECT_ANY_THROW(parser.getData());
}

/*Test purpose: Ensure data (numbers vector) is extracted properly given TSV file path*/
TEST(FileParserTests, parseValidTSV)
{
	string path = "../TestInputFiles/validTSVTrueExpected.tsv";
	FileParser parser(path);
	vector<int> expectedResult = { 4, 4, 1, 1, 2, 2, 1000, 1 };
	vector<int> result = parser.getData();

	EXPECT_TRUE(expectedResult == result);
}

/* Test purpose: Ensure data (numbers vector) is extracted properly given CSV file path*/
TEST(FileParserTests, parseValidCSV)
{
	string path = "../TestInputFiles/validCSVTrueExpected.csv";
	FileParser parser(path);
	vector<int> expectedResult = { 4, 4, 1, 1, 2, 2, 1000, 1 };
	vector<int> result = parser.getData();

	EXPECT_TRUE(expectedResult == result);
}
