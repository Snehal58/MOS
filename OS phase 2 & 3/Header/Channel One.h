#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<sstream>
using namespace std;
class ChannelOne{
    public:
    queue<Buffer>IFB;
    queue<Buffer>EB;
    queue<Buffer>OFB;
    bool busy = false;
    int timer = 0;
    bool isFull(){
            if((IFB.size() + EB.size() + OFB.size()) >= 10)
            return true;
            else return false;
        }
    bool isBusy(){
        if(busy)
        return true;
        else return false;
    }
    
   
    
}CH1;

