﻿#include <iostream>

class Vector {
public:
	Vector(const int size = 10);
	~Vector();
	void push_back(int);
	void insert_at(int index, int elem);
	void showArray(int m_size);
	int get_at(int index);
	//Vector & operator= (const Vector & rhs);
private:
	int m_size;
	int * m_arr;
	int res;
};


int main() {
	Vector * tmp = new Vector;
	tmp->push_back(1);
	tmp->push_back(2);
	tmp->push_back(3);
	tmp->insert_at(1, 5);
	tmp->insert_at(0, 4);
	tmp->push_back(8);
	tmp->push_back(10);
	tmp->insert_at(6, 9);
	tmp->showArray(7);
	std::cout << std::endl;
	std::cout<<tmp->get_at(7);


	std::cout << std::endl;
	
}

Vector::Vector(const int size){
	this->m_size = size;
	this->m_arr = new int[this->m_size];
	this->res = -1;

}

void Vector::push_back(int sum) {
	
	if (this->res == 30) {
		std::cout << "Stack overflow" << std::endl;
		return;
	}
	else if (this->res == this->m_size - 1) {
		int * newM_arr = new int[2 * this->m_size];
		for (int i = 0; i < this->m_size; ++i) {
			newM_arr[i] = this->m_arr[i];
		}
		delete[] this->m_arr;
		this->m_arr = newM_arr;
		this->m_size = this->m_size * 2;
	}
	this->m_arr[++this->res] = sum;
	//std::cout << "push items " << sum << std::endl;
}

void Vector::insert_at(int index, int elem) {
	int * insert = new int[this->m_size];
	int j = 0;
	for (int i = 0; i <= this->m_size; ++i) {
		if (i == index) {
			insert[index] = elem;
			++this->res;
		}
		else{
		insert[i] = this->m_arr[j];
		j++;
		}
	}
	for (int i = 0; i < this->m_size; ++i) {
		this->m_arr[i] = insert[i];
	}
	
}

void Vector::showArray(int m_size) {
	for (int i = 0; i < this->res+1; ++i) {
		std::cout <<"["<< this->m_arr[i] << "]" ;
	}
}

int Vector::get_at(int index) {
	return this->m_arr[index];
}


Vector::~Vector(){
	delete[] this->m_arr;
	this->m_arr = NULL;
}
