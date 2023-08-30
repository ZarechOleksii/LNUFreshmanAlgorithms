#include "pch.h"

TEST(BitSetv2Tester, AddingValues)
{
	BitSet testerSet;
	testerSet+= '0';
	ASSERT_EQ("0, ", testerSet.toString());
	testerSet+= '1';
	ASSERT_EQ("0, 1, ", testerSet.toString());
	testerSet+= '4';
	ASSERT_EQ("0, 1, 4, ", testerSet.toString());
	testerSet+= 'L';
	ASSERT_EQ("0, 1, 4, L, ", testerSet.toString());
	testerSet+= 'L';
	ASSERT_EQ("0, 1, 4, L, ", testerSet.toString());
	testerSet+= 'A';
	testerSet+= 'B';
	testerSet+= 'C';
	testerSet+= 'D';
	testerSet+= 'X';
	testerSet+= 'Y';
	testerSet+= 'Z';
	ASSERT_EQ("0, 1, 4, A, B, C, D, L, X, Y, Z, ", testerSet.toString());
	testerSet+= 63;
	ASSERT_EQ("0, 1, 4, ?, A, B, C, D, L, X, Y, Z, ", testerSet.toString());
	testerSet+= '~';
	ASSERT_EQ("0, 1, 4, ?, A, B, C, D, L, X, Y, Z, ~, ", testerSet.toString());
	testerSet+= 254;
	ASSERT_EQ("0, 1, 4, ?, A, B, C, D, L, X, Y, Z, ~, þ, ", testerSet.toString());
	testerSet+= 255;
	ASSERT_EQ("0, 1, 4, ?, A, B, C, D, L, X, Y, Z, ~, þ, ÿ, ", testerSet.toString());
	testerSet+= 32;
	ASSERT_EQ(" , 0, 1, 4, ?, A, B, C, D, L, X, Y, Z, ~, þ, ÿ, ", testerSet.toString());
}
TEST(BitSetv2Tester, OtherOperations)
{
	BitSet testerSet1;
	BitSet testerSet2;

	testerSet1+= '7';
	testerSet1+= '2';
	testerSet1+= '4';
	ASSERT_EQ("2, 4, 7, ", testerSet1.toString());

	testerSet2+= '0';
	testerSet2+= '9';
	ASSERT_EQ("0, 9, ", testerSet2.toString());
	
	testerSet1 = testerSet1|= testerSet2;
	ASSERT_EQ("0, 2, 4, 7, 9, ", testerSet1.toString());
	ASSERT_EQ("0, 9, ", testerSet2.toString());
	
	testerSet1 = testerSet1&= testerSet2;
	ASSERT_EQ("0, 9, ", testerSet1.toString());
	
	testerSet1+= '3';
	testerSet1+= '6';
	ASSERT_EQ("0, 3, 6, 9, ", testerSet1.toString());
	ASSERT_EQ("0, 9, ", testerSet2.toString());

	testerSet1 = testerSet1-= testerSet2;
	ASSERT_EQ("3, 6, ", testerSet1.toString());

	testerSet1-= '6';
	ASSERT_EQ("3, ", testerSet1.toString());
	testerSet1-= '5';
	ASSERT_EQ("3, ", testerSet1.toString());

	ASSERT_TRUE(testerSet1.present('3'));
	ASSERT_FALSE(testerSet1.present('5'));

	ASSERT_EQ("3, ", testerSet1.toString());
	ASSERT_EQ("0, 9, ", testerSet2.toString());
	BitSet mnozhini[2] = { testerSet1, testerSet2 };
	int size = sizeof(mnozhini) / sizeof(mnozhini[0]);
	
	ASSERT_TRUE(testerSet1 == testerSet1.findInWhichSet(mnozhini, size, '3'));
	ASSERT_TRUE(testerSet2 == testerSet1.findInWhichSet(mnozhini, size, '9'));
	ASSERT_FALSE(testerSet2 == testerSet1.findInWhichSet(mnozhini, size, '7'));

	testerSet2+= '3';
	mnozhini[1] = testerSet2;
	ASSERT_EQ("3, ", testerSet1.toString());
	ASSERT_EQ("0, 3, 9, ", testerSet2.toString());
	ASSERT_FALSE(testerSet1 == testerSet1.findInWhichSet(mnozhini, size, '3'));//undefined behaviour
}