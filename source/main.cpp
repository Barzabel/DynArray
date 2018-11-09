#include<iostream>
#include"DynArray.h"




using namespace std;




int main() {


	

	DynArray<int> a;
	for (int i = 0; i < 20; i++)
	{
		a.append(i);
	}
	for (int i = 19; i >= 0; i--)
	{
		a.delet(i);
	}
	cout << a.get_count();


	return 0;
}