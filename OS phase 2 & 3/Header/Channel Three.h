#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<sstream>
using namespace std;
class ChannelThree{
    public:
    queue<PCB>LQ;
    queue<PCB>RQ;
    queue<PCB>TQ;
    queue<PCB>IOQ;
    queue<Buffer> IS_Buffer;
    int timer = 0;
    bool busy = false;
    bool isBusy(){
        if(LQ.empty() && RQ.empty() && IOQ.empty())
        return false;
        else return true;
    }
    void IS(){
        if(!CH1.IFB.empty())
        {
            int count = 0;
            busy = true;
            Buffer temp = CH1.IFB.front();
            IS_Buffer.push(temp);
            CH1.IFB.pop();
            drum.Memory[drum.track_ptr] = temp.data;
            pcb.PTRACK = drum.track_ptr;
            drum.track_ptr++;
            pcb.count += ++count;

            IS_Buffer.pop();
        }
    }
    void LOAD(){
        if(!LQ.empty())
        {
            MM.page_table_ptr=rand()%30;
			MM.occupied_pages[MM.page_table_ptr]=true;
			MM.page_table_ptr*=10;
            PCB dmo = LQ.front();
            dmo.PTR = MM.page_table_ptr;
            cout<<dmo.ID<<dmo.TTL<<dmo.TLL<<dmo.F<< "PTR = "<<dmo.PTR<<endl;
            
            int mem_cnt = 0;
            cout<<"Program Count = "<<dmo.P<<endl;
            cout<<"Data Count = "<<dmo.D<<endl;
            int lc_count = dmo.P + dmo.D;
            while(lc_count > dmo.D){
                cout<<"Loading the Cards = "<<drum.Memory[drum.track_ptr - (lc_count)]<<endl;
                MM.store_card(drum.Memory[drum.track_ptr - (lc_count--)], mem_cnt++);
                
            }
            RQ.push(dmo);
            cout<<"PCB Popped from Load Queue"<<dmo.ID<<endl;
            LQ.pop();
        }


        
        
    }
}CH3;
