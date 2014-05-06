#include <iostream>
#include <string>
#include <fstream>
#include "Vagon.h"
#include "Depot.h"
#include "Train.h"
#include "Stack.h"
using namespace std;
int main(int argc, char** argv){
 	ifstream ifs, ifs2;
    ifs.open(argv[1]);
    int n, m, nop;
    ifs >> n;
    ifs >> m;
    int capacitate = n*m;
    ifs >> nop;
    int mata = 0;
    int contor = 0;

    //initializarea depoului
    Depot d(n,m);

 	        //executia operatiilor din fisierul de intrare  
    		for(int t = 0; t < nop; t++){
    			contor++;
    			
    			int val, lung;
    			ifs >> val;
    			ifs >> lung;
                
    			Train t(lung);

                int nrvag;
    			int tipvag;
                
                //cazul in care este ceruta inserarea unui tren in depou
    			if(val == 0){

    				if(lung > (capacitate - d.size)){ 
    					cout << "Dock error!" << endl;
    					d.showdepot();
                       
    				}else{
    					int dep = 0;

    					while(dep < lung){
                            
    						ifs >> nrvag;
    						ifs >> tipvag;
                           
    					
    						for(int j = 0; j < nrvag; j++){
    							Vagon v(tipvag);
                                t.add(v);
    						}
                            
    						dep += nrvag;
    					}
                        
                        for(int j = 0; j < lung; j++){
                            d.addvagon(t.get());
                        }
                        d.ad = 0;
    					d.showdepot();
                        
    				}

    				
    			}

                //cazul in care este ceruta extragerea unui tren din depou
                if(val == 1){
                    
                    // verificare daca se poate extrage trenul din depou
                    int de = 0;
                    int c = 0;
                    int vagmele[4];
                    Vagon vecdevagoane[lung];
                        for(int i = 0; i < 5; i++){
                             vagmele[i] = 0;
                        }
                        while(de < lung){
                           
                            ifs >> nrvag;   
                            ifs >> tipvag;    
                            for(int i = 0; i < nrvag; i++){
                                Vagon v(tipvag);
                                vecdevagoane[c] = v;
                                c++;
                            }
                            
                            vagmele[tipvag] += nrvag;
                            de += nrvag;
                        }
                        int ok = 0;
                        for(int i = 0; i < 5; i++){
                            if(vagmele[i] > d.vagoane[i]){
                                ok = 1;
                            }
                        }
                    //afisarea mesajului de eroare sau extragerea trenului
                    if(ok == 1){
                        cout << "Train error!" << endl;
                        d.showdepot();
                        
                    }else{
                    
                    
                    int dep = 0;

                        
                            for(int j = 0; j < c; j++){
                                Vagon v = vecdevagoane[j];
                                d.getvagon(v);

                            }
                            
                       
                        d.showdepot();
                       
                    
                    }
                }
            }
        }
    		


 		
	
    

	

