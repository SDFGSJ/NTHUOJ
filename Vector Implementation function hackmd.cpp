#include"function.h"
#include<cstdint>
using namespace oj;

Vector::~Vector(){
	clear();
	delete [] arr_;
}

Vector::Vector():size_(0),cap_(0),arr_(nullptr){}

Vector::Vector(const Vector &rhs):size_(0),arr_(nullptr){
	*this = rhs;
}

Vector& Vector::operator = (const Vector &rhs){
    clear();
	delete [] arr_;
	
    size_ = rhs.size_;
	cap_ = rhs.cap_;
	arr_ = new value_type* [cap_];
    for(int i=0;i<size_;i++){
    	arr_[i] = new value_type(rhs.arr_[i][0]);
	}
    return *this;
}
reference Vector::front(){
	return arr_[0][0];
}

reference Vector::back(){
	return arr_[size_-1][0];
}

reference Vector::operator[](size_type pos){
	return arr_[pos][0];
}

const_reference Vector::operator[](size_type pos) const{
	return arr_[pos][0];
}

size_type Vector::capacity() const{
	return cap_;
}

size_type Vector::size() const{
	return size_;
}

void Vector::clear(){ 
    for(int i=0;i<size_;i++)
		delete arr_[i];
    size_=0; 
}
bool Vector::empty() const{
	return size_==0;
}

void Vector::erase(size_type pos){
    delete arr_[pos];
	size_--;
    for(int i=pos;i<size_;i++)	//從pos把資料往前搬
		arr_[i] = arr_[i+1];
}
void Vector::insert(size_type pos, size_type cnt, const_reference val){
    //size_type c = (cap_==0 ? 1 : cap_);
    size_type c;
    if(cap_==0){
    	c=1;
	}else{
		c=cap_;
	}
    while(c < size_ + cnt)	//看看還需要多大的空間
		c*=2;
    reserve(c);
	size_ += cnt;
    for(int i=size_-1;i>=pos+cnt;i--)	//把資料往後搬
		arr_[i] = arr_[i-cnt];
    for(int i=0;i<cnt;i++)	//再插入新的值
		arr_[pos+i] = new value_type(val);
}
void Vector::pop_back(){
	erase(size_-1);
}

void Vector::pop_front(){
	erase(0);
}

void Vector::push_back(const_reference val){
	insert(size_,1,val);
}

void Vector::push_front(const_reference val){
	insert(0,1,val);
}

void Vector::reserve(size_type new_capacity){
    if(cap_ >= new_capacity)	//如果新的capacity比較小就return
		return;
	cap_ = new_capacity;
    value_type** tmp = new value_type* [new_capacity];
    for(int i=0;i<size_;i++)	//抄資料
		tmp[i] = arr_[i];
    delete [] arr_;
	arr_ = tmp;
}
void Vector::shrink_to_fit(){
	cap_ = 0;
	reserve(size_);
}
