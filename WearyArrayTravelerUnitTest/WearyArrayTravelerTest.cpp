#include "pch.h"
#include "wearyArrayTraveler.h"


/*Test purpose: Ensure zero length data (empty numbers vector) will lead to return false   */
TEST(wearyArrayTravelerTests, emptyInputResult)
{
	string path = "../TestInputFiles/emptyCSV.csv";
	bool emptyInputResult = runTraveler(path);
	EXPECT_TRUE(!emptyInputResult);
}

/*Test purpose: Ensure length of one data (songle  number vector) will lead to return true   */
TEST(wearyArrayTravelerTests, arrayOfSizeOneInputResult)
{
	string path = "../TestInputFiles/arraySizeOne.csv";
	bool arrayOfSizeOneInputResult = runTraveler(path);
	EXPECT_TRUE(arrayOfSizeOneInputResult);
}

/*Test purpose: Examine the happy path - Ensure true value is returned for an appropriate input */
TEST(wearyArrayTravelerTests, happyPathTrueReturnValueExpected)
{
	string path = "../TestInputFiles/validCSVTrueExpected.csv";
	bool trueResult = runTraveler(path);
	EXPECT_TRUE(trueResult);
}

/*Test purpose: Examine the happy path - Ensure false value is returned for an appropriate input */
TEST(wearyArrayTravelerTests, happyPathFlaseReturnValueExpected)
{
	string path = "../TestInputFiles/validCSVFalseExpected.csv";
	bool falseResult = runTraveler(path);
	EXPECT_TRUE(!falseResult);
}