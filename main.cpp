#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;
void copy(int *&dist,int *scr,int size){
    	for(int i=0;i<size;i++){
 	   dist[i]=scr[i];
 	}	
}
void merge(int *&tmp,int *leftpart,int *rightpart,int size){
    int lp=0,rp=0,n=0;
    
	while(n<size){
	            
		while(lp<size/2&&(leftpart[lp]<=rightpart[rp]||rp==size/2+size%2)){
			tmp[n]=leftpart[lp];
			
			lp++;
			
			n++;
			
		}
		while(rp<size/2+size%2&&(rightpart[rp]<leftpart[lp]||lp==size/2)){
			tmp[n]=rightpart[rp];
		            
			rp++;
		            
	
			n++;
			
		}
	}
}
void merge_sort(int *&ar,int size){
 	if(size==1){
 		return;
 	}
 	int *tmp=new int[size];
 	int *arh=ar+size/2;
 	merge_sort(ar,size/2);
 	merge_sort(arh,(size/2)+(size%2));
 	merge(tmp,ar,arh,size);
 
 	copy(ar,tmp,size);
 
 	delete[] tmp;
 	
 	
}
int main() {
   unsigned  int n;
   char e;
    string line;
    getline(cin,line);
    istringstream numstream(line);
    if(!(numstream>>n)||!(n>0)){
        cout<<"An error has occuried while reading input data.";
        exit(0);
    }

    getline(cin,line);
    istringstream arrstream(line);
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        if(!(arrstream>>arr[i])){
            cout<<"An error has occuried while reading input data.";
            delete[] arr;
            exit(0);
        }

    }
    if(arrstream>>e){
         cout<<"An error has occuried while reading input data.";
            delete[] arr;
            exit(0);	
    }

    
    
   merge_sort(arr,n);
   

    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    delete[] arr;
    return 0;
}
