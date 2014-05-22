#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../Src/Galt-Engine/PhyVec.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(PhyVecTest)
	{
	private:
		GaltE::PhyVec<int> vec1;
		GaltE::PhyVec<int> vec2;

		void setVectors()
		{
			vec1.setPos(0, 1);
			vec2.setPos(7, 6);
		}
	public:
		
		
		TEST_METHOD(CheckY)
		{
			setVectors();
			Assert::AreEqual(1, vec1.y, L"message", LINE_INFO());
		}

		TEST_METHOD(CheckX)
		{
			setVectors();
			Assert::AreEqual(0, vec1.x);
		}

		TEST_METHOD(CheckUpdatePos)
		{
			setVectors();
			vec1.updatePos(3, 4);
			Assert::AreEqual(3, vec1.x);
			Assert::AreEqual(5, vec1.y);
		}

		TEST_METHOD(CheckMagnitude)
		{
			vec1.updatePos(3, 4);
			Assert::AreEqual(5, vec1.magnitude());
		}

		TEST_METHOD(CheckDotProduct)
		{
			setVectors();
			Assert::AreEqual(6, vec1 * vec2);
		}

		TEST_METHOD(CheckAngleBetween)
		{
			setVectors();
			Assert::AreEqual(49, (int)(vec1.getAngleBetween(vec2) * 180 / 3.14));
		}
	};
}