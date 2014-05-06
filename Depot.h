#include <stdlib.h>
#include "Stack.h"
using namespace std;
class Depot{
	public:
		int N;
		int M;
		int ad;
		int gt;
		int size;
		int vagoane[5];
		Stack<Vagon> linii[300]; 

		//constructor Depou
		Depot(int N, int M){
			this->N = N;
			this->M = M;
			this->size = 0;
			Stack<Vagon> linii[N];
			ad = 0;
			for(int i = 0; i < 5; i++){
				vagoane[i] = 0;
			}
		}
		~Depot() {
			
		}
		//functie care afiseaza configuratia depoului la 
		void showdepot(){
			int c = 0;
			for(int i = 0; i < N; i++){
				if(linii[i].size() == -1){
					cout<<i<<": "<<linii[i].size() + 1<<"";
				}else{
					cout<<i<<": "<<linii[i].size() + 1<<" ";
				}
				int n = linii[i].size() + 1;
			    if(n == 1){
					cout <<"1 "<<linii[i].stackArray[0].id<<"";
				}else{
					int a[n];
					int v[n];
					int c = 1;
					for(int j = 0; j <= linii[i].size(); j++){
						a[j] = linii[i].stackArray[j].id;
					}
					for (int i = 1; i < n; i++) {
						if (a[i] == a[i - 1]) {
						c++;
						v[i] = c;

						} else {
							c = 1;
							v[i] = c;
						}
					}
					if (a[0] != a[1]) {
							v[0] = 1;
					}
					for (int i = 0; i < n; i++) {
						if (i == n - 1) {
						cout <<v[i]<<" "<<a[i]<<"";

						} else {
							if (a[i] != a[i + 1]) {
							cout <<v[i]<<" "<<a[i]<<" ";
						}
					}
				}
			}
			cout << endl;
			}
			cout << endl;
			std::cout.flush();
		}
		//functie care adauga un vagon in depou
		void addvagon(Vagon v){
			
			while(linii[ad].size() > M-2){
				if((ad + 1) == (this->N)){
				ad = 0;
				}else{
					ad++;
				}
			}
			linii[ad].push(v);
			if((ad + 1) == (this->N)){
				ad = 0;
			}else{
				ad++;
			}
			int a = v.id;
			vagoane[a]++;
			size++;
			
		}
		//functie pentru extractia unui vagon
		void getvagon(Vagon v){
			for(int i = 0; i < N; i++){
				int ok = 0;
				for(int j = 0;j <= linii[i].size(); j++){
					if(linii[i].stackArray[j].id == v.id){
						ok = 1;
					}
				}
				if(ok == 1){
					gt = i;	
					while(linii[i].peek().id != v.id){

							gt++;
							while(linii[gt].size() > M-2){
								gt++;
								if(gt == N){
									gt = 0;
								}
							}
							
							if(gt == N){
								gt = 0;
								while(linii[gt].size() > M-2){
								gt++;
								if(gt == N){
									gt = 0;
								}
							}
							}
						
						
							linii[gt].push(linii[i].pop());
						
						
						
						
					}
					linii[i].pop();
					size--;
					vagoane[v.id]--;

					break;
				}
			}
		}
};
			
			
		
		





