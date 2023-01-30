#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<sstream>
using namespace std;

class PCB{
    public:
    int PTR;
    int ID;
    int TTL;
    int TLL;
    int TTC;
    int LLC;
    int PTRACK;
    int DTRACK;
    char F;
    int P = 0;
    int D = 0;
    int count = 0;
    PCB(){}
    PCB(int ptr,int id, int ttl, int tll, int ttc, int llc, int ploc, int dloc)
    {
        PTR = ptr;
        ID = id;
        TTL = ttl;
        TLL = tll;
        TTC = ttc;
        LLC = llc;
        PTRACK = ploc;
        DTRACK = dloc;
        
    }
    void Clear(){
        PTR = 0;
        ID = 0;
        TTL = 0;
        TLL = 0;
        TTC = 0;
        LLC = 0;
        PTRACK = 0;
        DTRACK = 0;
        count = 0;
        P = 0;
        D = 0;
    }
}pcb;
