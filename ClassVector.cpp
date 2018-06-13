#include <iostream>

class Vector {
public:
	Vector(const int size = 10);
	~Vector();
	void push_back(int);
	void insert_at(int index, int elem);
	void showArray();
	int get_at(int index);
	Vector & operator= (const Vector & rhs);
	void copyContruct(const Vector & rhs);
	Vector (const Vector & rhs);
private:
	int m_size;
	int * m_arr;
	int res;
};


int main() {
	Vector * tmp = new Vector;
	Vector ptr;
	ptr.push_back(1);
	ptr.push_back(2);
	ptr.push_back(3);
	ptr.insert_at(1, 5);
	ptr.insert_at(0, 4);
	ptr.push_back(8);
	ptr.push_back(5);
	ptr.insert_at(6, 9);
	ptr.showArray();
	std::cout << std::endl;
	//std::cout<<tmp->get_at(0);
	Vector obj(ptr);
	obj.showArray();
	Vector result = obj;

	result.showArray();


	std::cout << std::endl;
	
}

Vector::Vector(const int size){
	this->m_size = size;
	this->m_arr = new int[this->m_size];
	this->res = -1;

}

Vector::Vector(const Vector & rhs) {
	Vector::copyContruct(rhs);
}

Vector & Vector::operator= (const Vector & rhs) {
	if (this == &rhs) {
		return *this;
	}
	delete[] this->m_arr;
	copyContruct(rhs);
	return *this;
}

void Vector::copyContruct(const Vector & rhs) {
	this->res = rhs.res;
	this->m_size = rhs.m_size;
	this->m_arr = new int[rhs.m_size];
	for (int i = 0; i < this->m_size; ++i) {
		this->m_arr[i] = rhs.m_arr[i];
	}
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
	if (this->res == this->m_size - 1) {
		int * newM_arr = new int[2 * this->m_size];
		for (int i = 0; i < this->m_size; ++i) {
			newM_arr[i] = this->m_arr[i];
		}
		delete[] this->m_arr;
		this->m_arr = newM_arr;
		this->m_size = this->m_size * 2;
	}
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

void Vector::showArray() {
	for (int i = 0; i < this->res+1; ++i) {
		std::cout <<"["<< this->m_arr[i] << "]";
	}
	std::cout << std::endl;
}

int Vector::get_at(int index) {
	return this->m_arr[index];

}


Vector::~Vector(){
	delete[] this->m_arr;
	this->m_arr = NULL;
}
