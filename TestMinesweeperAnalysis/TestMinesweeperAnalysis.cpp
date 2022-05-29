#include "pch.h"
#include "CppUnitTest.h"

#include "../MinesweeperAnalysis.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestMinesweeperAnalysis
{
	TEST_CLASS(TestMinesweeperAnalysis)
	{
	public:
		
		TEST_METHOD(TestValidBoardConfiguration)
		{
			tuple <bool, bool> ret;
			/* A 4 x 2 board with 4 mines */
			ret = SolutionValidation(4, 2, 4);
			Assert::AreEqual(true, get<0>(ret));
		}

		TEST_METHOD(TestInValidBoardConfiguration)
		{
			tuple <bool, bool> ret;
			/* A 4 x 4 board with 14 mines */
			ret = SolutionValidation(4, 4, 14);
			Assert::AreEqual(false, get<0>(ret));
		}
	};
}
