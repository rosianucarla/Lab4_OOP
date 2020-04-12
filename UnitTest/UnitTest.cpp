#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab4_OOP/Drug.h"
#include "../Lab4_OOP/Repository.h"
#include "../Lab4_OOP/Controller.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
//Drug-Tests
namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(ConstructorTest)
		{
			auto drug1 = new Drug("Nurofen", 100, 10, 35);
			Assert::AreEqual(100.0, drug1->getConcentration());
		}
		TEST_METHOD(toStringTest)
		{
			auto drug1 = new Drug("Nurofen", 100, 10, 35);
			Assert::AreEqual(std::string("Nurofen 100.000 10 35.000"), drug1->toString());
		}

	};
}
