#include "VectorADT.h"
#include <iostream>
#include <cstddef>
#include <algorithm>
using namespace std;

VectorADT::VectorADT(){
	size=0;
	capacity=10;
    array = new double[10];
    for(int i=0;i<10;i++)
    	array[i]=0.0;
}

VectorADT::VectorADT(int s,int c){
	size=s;
	capacity=c;
    array = new double[c];
    for(int i=0;i<c;i++)
    	array[i]=0;
}

VectorADT::VectorADT(const VectorADT& c){
	size = c.size;
	capacity = c.capacity;
	array = new double[capacity];
	for(int i=0;i<size;i++){
		array[i]=c.array[i];
	}
}

VectorADT& VectorADT::operator =(const VectorADT& rhs){
	size = rhs.size;
	capacity = rhs.capacity;
	array = new double[capacity];
	for(int i=0;i<size;i++){
		array[i]=rhs.array[i];
	}
	return (*this);
}

void VectorADT::push_back(double val ){
    if(size==capacity){
    	resize(size+1);
    }
    array[size]=val;
    size++;
    return;
}

void VectorADT::pop_back(){
    size--;
}

void VectorADT::resize(int newSize){

    if(newSize<size){
    	size=newSize;
    }
    else if(newSize>size && newSize<capacity){
    	for(int i=size;i<newSize;i++){
    		array[i]=0;
    	}
    }
    else if(newSize>capacity){

    	VectorADT temp (size,2*newSize);
    	//cout<<endl<<temp.size<<endl;
    	for(int i=0;i<size;i++){
    		temp.array[i]=array[i];
    		//cout<<array[i];
    	}
    	(*this)=temp;
    	return;
    }
}

double VectorADT::operator[](int i) const{
	return array[i];
}

VectorADT VectorADT::operator +(const VectorADT& rhs){
	int m = min(size,rhs.size);
	VectorADT v;
	int i;
	for(i=0;i<m;i++){
		v.push_back(array[i]+rhs[i]);
	}
	while(i<size){
		v.push_back(array[i]);
		i++;
	}
	while(i<rhs.size){
		v.push_back(rhs.array[i]);
		i++;
	}
	return v;
}

int VectorADT::length() const{
    return size;
}


int VectorADT::curr_capacity() const{
    return capacity;
}

ostream &operator<<(ostream &OUT,const VectorADT v){
	if(v.size==0)
		return(OUT);
	OUT <<v[0];
	for (int i = 1; i < v.size; i++)
   	{
      OUT << " , "<<v[i];
   	}
   	
   	return( OUT );
}

VectorADT::~VectorADT(){
	
}











