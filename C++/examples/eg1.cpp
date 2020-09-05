#include <iostream>
#include "../include/linkedlist.h"

using std::endl;
using std::cout;

int main(){
	dsalib::LinkedList<int> l1;
	l1.push_front(5);     // 5
	l1.push_front(3);     // 3 5
	l1.push_back(6);      // 3 5 6
	l1.insert(4,1);       // 3 4 5 6
	dsalib::LinkedList<int>::Iterator itr;
	itr = l1.get_iterator(2);
	cout<<*itr<<endl;       // 5
	cout<<*(++itr)<<endl;   // 6
	cout<<*(----itr)<<endl; // 4

	for (dsalib::LinkedList<int>::Iterator j=l1.first(); j!=NULL; j++){
		cout<<*j<<" ";
	} // 3 4 5 6
	cout<<endl;
}