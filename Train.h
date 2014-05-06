#include <stdlib.h>
#include "Stack.h"
#include "Vagon.h"
using namespace std;
class Train{
public:
	int size;
	Stack<Vagon> tren;
	Train(int size){
		
		this->size = size;
	}
	void add(Vagon v){
		tren.push(v);

	}
	Vagon get(){
		return tren.pop();
	}
	void showtrain(){
		for(int i = 0; i <= tren.size(); i++){
			cout << tren.stackArray[i].id << " ";
		}
	}
};