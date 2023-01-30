#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<sstream>
using namespace std;
class VirtualMemory{
    public: 
    
    Buffer Memory[10];
    bool END = false;
    int isBufferAvailable()
    {
        for(int i = 0; i < 10; i++)
        {
            if(Memory[i].status.compare("eb") == 0)
            return i;
        }
        return -1;
    }
     bool isEND(){
        if(END)
        return true;
        else return false;
    }
}VM;