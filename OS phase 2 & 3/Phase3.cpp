#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<sstream>
#include "Header/Buffer.h"
#include "Header/PCB.h"
#include "Header/Virtual Memory.h"
#include "Header/DRUM.h"
#include "Header/Main Memory.h"
#include "Header/Channel One.h"
#include "Header/Channel Three.h"
#include "Header/CPU.h"
using namespace std;


int main()
{
    
	fin.open("input.txt");
    fout.open("output.txt");
	while(true)//ok
	{
		//get the line one byb one and check wether it contains as follows
        cpu.MOS(IOI);
        cout<<"IOI1 = "<<IOI<<endl;
        cpu.SIMULATION();
         cout<<"IOI2 = "<<IOI<<endl;
       // cout<<"Done"<<endl;
		
        
		
	}






    return 0;
}


