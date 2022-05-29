#include "pch.h"
#include "CppUnitTest.h"

#include "../MinesweeperAnalysis.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestMinesweeperAnalysis
{
	TEST_CLASS(TestMinesweeperAnalysis)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(true, Test());
		}
	};
}
