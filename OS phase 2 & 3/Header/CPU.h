#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<sstream>

using namespace std;
ifstream fin;
ofstream fout;
int IOI = 1;
bool mos = false;
int universal_timer = 0;
int SI,PI,TI;
class CPU{
    public:
    string s,s1;
    void Start_Channel(int val){
        
        if(val == 1)
        {
            IOI-=1;
            CH1.busy = true;
            CH1.timer = 0;
            
        }
        if(val == 3){
            IOI-=4;
            CH3.timer = 0;
            CH3.busy = true;

        }
        
        
        //SIMULATION();
    }

    void SIMULATION(){
        
            if(CH1.busy){
            
                CH1.timer+=1;
                if(CH1.timer == 5)
                {
                    CH1.timer = 0;
                    IOI+=2;
                    IOI%=8;
                    mos = true;
                }
                
                
                
            }
            if(CH3.busy){
                CH3.timer+=1;
                if(CH3.timer == 2){
                    IOI+=4;
                    IOI%=8;
                    CH3.timer = 0;
                }
            }
        
    }
    void IR1(){
        getline(fin,s);
        buffer.data = s;
        buffer.status = "ifb";
        CH1.IFB.push(buffer);
        if(!(fin.eof()) && VM.isBufferAvailable() != -1)
        {
            
            Start_Channel(1);
        }
        else if((fin.eof()) && CH3.LQ.empty()){
            MM.print_mem();
            exit(0);
        }
        buffer = CH1.IFB.front();
        CH1.IFB.pop();
        // buffer.status = "eb";
        // // CH1.IFB.push(buffer);
        int bf_val = VM.isBufferAvailable();
        // VM.Memory[bf_val] = buffer;
        string card = buffer.data;
        cout<<card<<endl;       
        if(card.find("$AMJ")!=-1)
		{
            pcb.Clear();
            cout<<"PCB Cleared"<<endl;
            pcb = MM.set_limits(card, pcb);
            pcb.F = 'P';
            buffer.status = "eb";
            VM.Memory[bf_val] = buffer;
		}
        else if(card.find("$DTA")!=-1)
		{
			pcb.F = 'D';
            buffer.status = "eb";
            VM.Memory[bf_val] = buffer;
		}
        else if(s.find("$END")!=-1)
		{
			//proceed to the next job
			CH3.LQ.push(pcb);
            buffer.status = "eb";
            VM.Memory[bf_val] = buffer;
            CH3.LOAD();
            

		}
        else
		{
			//load the program card as soon as it comes
			CH1.IFB.push(buffer);
            cout<<"PCB data "<<buffer.data<<endl;
            cout<<"PCB FLAG "<<pcb.F<<endl;
            cout<<"PGM count = "<<pcb.P<<"DTA count = "<<pcb.D<<endl;
            if(pcb.F == 'P')
            {
                pcb.P+=1;

            }
            else{
                pcb.D+=1;
            }
           // CH3.IS();
            cout<<"DRUM  = ";
            drum.Print_Memory();
            
		}
        // cout<<pcb.ID<<pcb.TTL<<pcb.TLL<<pcb.F<<endl;

    }
    void IR3(){
        CH3.IS();
        CH3.LOAD();
    }

    void MOS(int IOI){
        switch (IOI)
        {
            case 1:
            IR1();
            break;
            case 2:
            break;
            case 3:
            IR1();
            break;
            case 4:
            IR3();
            case 5:
            IR1();
            IR3();
            break;
            case 6:
            IR3();
            break;
            case 7:
            IR1();
            IR3();
            break;
            default:
            break;
        }
    }       
}cpu;
