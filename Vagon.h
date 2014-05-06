#ifndef __VAGON__H
#define __VAGON__H
#include <stdlib.h>
using namespace std;
	class Vagon{
	public:
		int id;
		Vagon(int id){
			this->id = id;
		}
		Vagon(){
			this->id = -1;
		}
	};
#endif
