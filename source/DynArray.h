#pragma once
#ifndef _DENARRAY_
#define _DENARRAY_
#include <iostream>

using namespace std;

template<class T>
class DynArray {
public:
	DynArray();
	DynArray(unsigned int size);

	void make_array(unsigned int new_capacity);

	unsigned int get_count() {
		return this->count;
	}

	unsigned int get_capacity() {
		return this->capacity;
	}

	T& get_item(int i);

	T& operator [](int i);


	void  insert(unsigned int i,const T& item);

	void append(T item);


	void delet(unsigned int i);


	~DynArray();
private:
	unsigned int capacity;
	unsigned int count;
	T*arr;


	T* copiyarr(unsigned int i) {

		T* resarr = new T[i];
		for (unsigned int a = 0;( a < i)&&(a<this->count); a++) {
			resarr[a] = this->arr[a];
		}

		return resarr;
	}


	T* copiyarr(unsigned int run, unsigned int end) 
	{
		T* resarr = new T[end-run];
		for (unsigned int a = run; (a < end) && (a < this->count); a++) {
			resarr[a-run] = this->arr[a];
		}

		return resarr;
	}





};










#include"DynArray.ipp" 

#endif

