#include<iostream>
#include"DynArray.h"




using namespace std;




int main() {


	DynArray<int> a(3);
	a.make_array(100);

	a.append(3);

	a.append(4);
	a.delet(0);
	a.append(5);
	a.insert(0, 13);
	
	a.append(5);
	a.append(5);
	for (int i = 0; i < a.get_count(); i++) {
		cout << a[i]<<endl;
	}








	return 0;
}