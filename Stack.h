#ifndef __STACK__H
#define __STACK__H
#include <iostream>
#include <stdlib.h>
using namespace std;

template<typename T>
class Stack {
	private:
		
		// pozitia in vector a varfului stivei
		int topLevel,max;
	public:
		
		// vectorul de stocare
		T* stackArray;
		// constructor
		Stack() {
			stackArray = (T*)malloc(sizeof(T));
			topLevel = -1;
			max=1;
		}

		// destructor
		~Stack() {
			free(stackArray);
		}

		// operator de adaugare
		void push(T x) {
			if (topLevel >= max-1) {
				stackArray = (T*)realloc(stackArray, 2*max*sizeof(T));
				max *= 2;
			}
			topLevel++;
			stackArray[topLevel] = x;
		}

		// operatorul de stergere
		T pop() {
			if ( isEmpty() ) {
				T x;
				return x;
			}
			T x = stackArray[topLevel];
			topLevel--;
			return x;
		}

		// operatorul de consultare
		T peek() {
			if ( isEmpty() ){
				T x;
				return x;
			}
			return stackArray[topLevel];
		}

		// operatorul de verificare daca stiva e goala
		int isEmpty() {
			return (topLevel<0);
		}

		int size() {
			return topLevel;
		}

		void display() {
			for(int i=0;i<this->size();i++) {
				cout<<stackArray[i]<<" ";	
			}
			cout<<endl;
		}
};
 
#endif // __STACK__H
