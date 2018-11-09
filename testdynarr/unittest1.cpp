#include "stdafx.h"
#include "CppUnitTest.h"
#include "../source/DynArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testdynarr
{		
	TEST_CLASS(DynArra)
	{
	public:
		
		TEST_METHOD(konstr)
		{
			DynArray<int> a(1);
			Assert::IsTrue(a.get_capacity()==16);
			Assert::IsTrue(a.get_count() == 0);
			DynArray<int> b(34);
			Assert::IsTrue(b.get_capacity() == 34);

		}
		TEST_METHOD(make_arr)
		{
			DynArray<int> a;
			a.make_array(12);
			Assert::IsTrue(a.get_capacity() == 16);
			for (int i = 0; i < 32; i++)
			{
				a.append(i);
			}
			
			a.make_array(16);
			Assert::IsTrue(a.get_capacity() > 16);


		}
		TEST_METHOD(insert) 
		{
			DynArray<int> a;
			for (int i = 0; i < 20; i++)
			{
				a.append(i);
			}
			unsigned int  count;
			for(int i=0 ;i<20;i++)
			{
				count = a.get_count();
				a.insert(i, 3);
				Assert::IsTrue(a.get_count() == count+1);
			}
			try {
				a.insert(100, 1);

				Assert::IsTrue(false);
			}
			catch(out_of_range){
				Assert::IsTrue(true);
			}
			for (int i = 0; i < 20; i++)
			{
				a.insert(i, i+4);
				Assert::IsTrue(i+4==a[i]);
			}
		}

			TEST_METHOD(delet) 
			{

				DynArray<int> a;
				for (int i = 0; i < 20; i++)
				{
					a.append(i);
				}
				for (int i = 19; i >= 0; i--)
				{
					a.delet(i);
				}
				Assert::IsTrue(a.get_count() == 0);

				try {
					a.delet(100);
					Assert::IsTrue(false);
				}
				catch (out_of_range) {
					Assert::IsTrue(true);
				}


				for (int i = 0; i < 20; i++)
				{
					a.append(i);
				}
				int n = 5;

				a.delet(5);
				for (int i = 0; i < 19; i++)
				{
					Assert::IsFalse(a[i]==5);
				}

			}
			TEST_METHOD(get_item) 
			{
				DynArray<int> a;
				for (int i = 0; i < 20; i++)
				{
					a.append(i);
				}
				for (int i = 0; i < 20; i++)
				{
					Assert::IsTrue(a.get_item(i)==i);
					Assert::IsTrue(a[i]==i);
				}
				try {

					a[100];

					Assert::IsTrue(false);

				}
				catch (out_of_range) {

					Assert::IsTrue(true);

				}
				try {

					a.get_item(100);

					Assert::IsTrue(false);

				}
				catch (out_of_range) {

					Assert::IsTrue(true);

				}


			}



		

			


	};
}