#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
     int mid= (n/2)+1;
    for(int i=1;i<=n;i++){
        if(i==1){
            cout<<"* ";
            for(int j=2;j<=n;j++){
                if(j<mid){
                    cout<<"  ";
                }
                else{
                    cout<<"** ";
                }
            }
            cout<<endl;
        }
        if(i!=1 && i<mid){
            for(int j=1;j<=n;j++){
                if(j==1 || j==mid){
                    cout<<"** ";
                }
                else{
                    cout<<"  ";
                }
            }
            cout<<endl;
        }
        if(i==mid){
            for(int j=1;j<=n;j++){
                cout<<"** ";
            }
            cout<<endl;
        }

        if(i>mid && i!=n){
            for(int j=1;j<=n;j++){
                if(j==mid || j==n){
                    cout<<"** ";
                }
                else{
                    cout<<"  ";
                }
            }
            cout<<endl;
            
        }

        if(i==n){
            for(int j=1;j<=n-1;j++){
                if(j<=mid){
                    cout<<"** ";
                }
                else{
                    cout<<"  ";
                }
                
            }
            cout<<"** ";
            
        }
    }
    return 0;
}
