#pragma once



template<class T>
DynArray<T>::DynArray() :capacity(static_cast< unsigned int>(16)), count(static_cast<unsigned int>(0)) {
	this->arr = new T[this->capacity];

}

template<class T>
DynArray<T>::DynArray(unsigned int size):capacity(static_cast<unsigned int>(size)),count(static_cast<unsigned int>(0)) {


	this->arr = new T[this->capacity];

}







template<class T>
void DynArray<T>::make_array(unsigned int new_capacity) {
	if ((this->count * 3 / 2 + 1) > new_capacity) {
		return;
	}
	T* arrcop = copiyarr(this->count);

	delete[] this->arr;
	this->arr = new T[new_capacity];

	for (unsigned int i = 0; i < this->count; i++)
	{
		this->arr[i] = arrcop[i];

	}
	this->capacity = new_capacity;
}

template<class T>
void DynArray<T>::append(T item) {


	this->arr[this->count] = item;
	

	if ((this->count * 2 / 3 + 1) > this->capacity) {
		this->make_array((this->count * 2 / 3 + 1) + 16);
	}
	
	this->count++;
	
}

template<class T>
void DynArray<T>::delet(unsigned int i)
{
	if(i+1 == this->count)
	{
		

		if (((this->count * 2 / 3 + 1) < this->capacity)&&(this->capacity>16)) {
			this->make_array((this->count * 2 / 3 + 1) + 16);
		}
	
		this->count--;
		return;
	}


	T * copyarr = this->copiyarr(i + 1, this->count);

	



	for (unsigned int n = i ; n < (this->count-1 ); n++) {
		this->arr[n] = copyarr[n  -i];
	}
	if (((this->count * 2 / 3 + 1) < this->capacity) && (this->capacity > 16)) {
		this->make_array((this->count * 2 / 3 + 1) + 16);
	}

	this->count--;
	return;

}





template<class T>
T& DynArray<T>::get_item(int i) {
	
	if(static_cast<unsigned int>(i)> this->count)
	{
		throw std::out_of_range("index abroad");
	}

	return this->arr[i];
}


template<class T>
T& DynArray<T>::operator [](int i) {

	if (static_cast<unsigned int>(i) > this->count)
	{
		throw std::out_of_range("index abroad");
	}

	return this->arr[i];
}


template<class T>
void  DynArray<T>::insert(unsigned int i, const T& item) 
{
	

	T * arcopy2 = copiyarr(i,this->count);
	this->arr[i] = item;
	for (unsigned int n = i + 1; n < (this->count + 1);n++) {
		this->arr[n] = arcopy2[n - 1 - i];
	}
	if ((this->count * 2 / 3 + 1) > this->capacity) {
		this->make_array((this->count * 2 / 3 + 1) + 16);
	}

	this->count++;

}






template<class T>
DynArray<T>::~DynArray() {



	delete [] this->arr;
}