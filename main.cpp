#include <iostream>
#include <sstream>
using namespace std;
void merge(int *&tmp,int *leftpart,int *rightpart,int size,){
    int lp=0,rp=0,n=0;
	while(n<size){
		if(leftpart[lp]<=rightpart[rp]){
			tmp[n]=leftpart[lp];
			if(lp<size/2-1){
			        lp++;
			}
		}
		if(leftpart[lp]>rightpart[rp]){
			tmp[n]=rightpart[rp];
			if(rp<(size/2+size%2)-1){
			        rp++;
			}
		}
	}
}
void merge_sort(int *&ar,int size){
 	
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

    
    
   quicksort(arr,0,n-1,arr[0]);
   

    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    delete[] arr;
    return 0;
}
