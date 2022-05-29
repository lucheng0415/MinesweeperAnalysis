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

			/* A 4 x 4 board with 15 mines */
			ret = SolutionValidation(4, 4, 15);
			Assert::AreEqual(true, get<0>(ret));

			/* A 10 x 10 board with 80 mines */
			ret = SolutionValidation(10, 10, 80);
			Assert::AreEqual(true, get<0>(ret));

			/* A 2 x 2 board with 3 mines */
			ret = SolutionValidation(2, 2, 3);
			Assert::AreEqual(true, get<0>(ret));

			/* A 4 x 3 board with 6 mines */
			ret = SolutionValidation(4, 3, 6);
			Assert::AreEqual(true, get<0>(ret));

			/* A 12 x 14 board with 36 mines */
			ret = SolutionValidation(12, 14, 36);
			Assert::AreEqual(true, get<0>(ret));
		}

		TEST_METHOD(TestInValidBoardConfiguration)
		{
			tuple <bool, bool> ret;
			/* A 4 x 4 board with 14 mines */
			ret = SolutionValidation(4, 4, 14);
			Assert::AreEqual(false, get<0>(ret));

			/* A 2 x 4 board with 6 mines */
			ret = SolutionValidation(2, 4, 6);
			Assert::AreEqual(false, get<0>(ret));

			/* A 4 x 2 board with 6 mines */
			ret = SolutionValidation(4, 2, 6);
			Assert::AreEqual(false, get<0>(ret));

			/* A 10 x 10 board with 90 mines */
			ret = SolutionValidation(10, 10, 90);
			Assert::AreEqual(false, get<0>(ret));

			/* A 4 x 4 board with 7 mines */
			ret = SolutionValidation(4, 4, 7);
			Assert::AreEqual(false, get<0>(ret));
		}
	};
}
