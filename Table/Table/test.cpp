#include "pch.h"

TEST(TableTester, TestName1) 
{
	Table testerTable;

	testerTable.place("TESTER1", "AB");
	ASSERT_EQ("TESTER1", testerTable.getStringByKey("AB"));
	ASSERT_EQ("", testerTable.getStringByKey("AD"));
	ASSERT_EQ(0.0015, testerTable.howFull());

	testerTable.clearByKey("AB");
	ASSERT_EQ("", testerTable.getStringByKey("AB"));
	ASSERT_EQ(0.000, testerTable.howFull());

	testerTable.place("TESTER2", "ZZ");
	ASSERT_EQ("TESTER2", testerTable.getStringByKey("ZZ"));
	ASSERT_EQ(675, testerTable.getAddressByKey("ZZ"));
	ASSERT_EQ(675, testerTable.getAddressByContent("TESTER2"));
	ASSERT_EQ("ZZ", testerTable.getKeyByContent("TESTER2"));

	testerTable.clearByKey("ZZ");
	ASSERT_EQ("", testerTable.getStringByKey("ZZ"));
	ASSERT_EQ(-1, testerTable.getAddressByContent("TESTER2"));
	ASSERT_EQ("Missing", testerTable.getKeyByContent("TESTER2"));
}