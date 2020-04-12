#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab4_OOP/Drug.h"
#include "../Lab4_OOP/Repository.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

//Repository-Tests

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(add_drug)
		{
			Repository r = Repository();
			Drug d1((std::string)"Nurofen", 100, 10, 35.9);
			r.add_drug(d1);
			Assert::AreEqual(r.getDrug_byIndex(0).getQuantity(), 10);

		}
		TEST_METHOD(edit_drug)
		{
			Repository r = Repository();
			Drug d1((std::string)"Nurofen", 100, 10, 35.9);
			Drug d2((std::string)"NoSpa", 200, 10, 20.0);
			r.add_drug(d1);
			r.edit_drug(d1, d2);
			Assert::AreEqual(r.getDrug_byIndex(0).getPrice(), 20.0);
		}
	};
}
