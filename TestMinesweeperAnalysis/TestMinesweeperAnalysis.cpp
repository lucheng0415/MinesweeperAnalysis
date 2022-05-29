#include "pch.h"
#include "CppUnitTest.h"

#include "../MinesweeperAnalysis.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestMinesweeperAnalysis
{
	TEST_CLASS(TestMinesweeperAnalysis)
	{
	public:
		
		TEST_METHOD(TestValidConfiguration)
		{
			Assert::AreEqual(true, true);
		}

		TEST_METHOD(TestInValidConfiguration)
		{
			Assert::AreEqual(false, false);
		}
	};
}
