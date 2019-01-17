#include "ListADT.h"
#include "VectorADT.h"
#include <cstdlib>
#include <vector>

using namespace std;



int main() {
	
	ListADT l;
	l.push_front(2);
	l.push_front(3);
	l.push_front(4);
	l.push_front(5);
	l.pop_back();
	cout<< "Length of the list: " << l.length()<<endl;
	
	ListADT temp1;	
	temp1=l;
	cout<<"List after copying l to temp: "<<temp1;
	


	VectorADT v;
	cout<<endl;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);
	cout << "Vector with capacity less than 10: " ;
	for(int i=0;i<v.curr_capacity();i++)
		cout<<v[i]<<" ";
	cout<<endl;
	v.push_back(4);
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	
	VectorADT temp(v);
	temp = v;
	cout << "Vector with capacity more than 10 and after copying to temp: ";
	for(int i=0;i<v.curr_capacity();i++){
		cout<<temp[i]<<" ";
	}
	cout << endl;
	cout<< "using the << operator: "<< temp<<endl;
	return 0;
}