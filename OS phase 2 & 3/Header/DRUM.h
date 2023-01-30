#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<sstream>
using namespace std;
class DRUM{
    public:
    string Memory[500];
    int track_ptr = 0;
    void Print_Memory(){
        for(int i = 0; i < 5; i++)
        {
            cout<<Memory[i]<<endl;
        }
    }

}drum;