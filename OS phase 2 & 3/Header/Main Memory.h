#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<sstream>
using namespace std;
class MainMemory{
    public:
    
    char Memory[300][4];
    bool occupied_pages[30];
    int page_table_ptr;
    
    
    MainMemory(){
        memset(Memory,'$',sizeof(char)*300*4);
		memset(occupied_pages,false,sizeof(bool)*30);
    }
        string get_mem(int pos)//get word form memory
		{
			//get the memory contents of given position
			string temp="";
			for(int i=0;i<4;i++)
				temp+=Memory[pos][i];
			return temp;
		}
        void set_mem(string s, int pos)//store word in mem
		{
			//set the memory for the recieved value at postion
			for(int i=0;i<4;i++)
				Memory[pos][i]=s[i];
		}
        int get_page_table_ptr()
        {
            return page_table_ptr;
        }
        int allocate_page()
		{
			int page_no=rand()%30;
			while(occupied_pages[page_no]==true)
				page_no=rand()%30;
			occupied_pages[page_no]=true;
			return page_no;
		}
        void set_page_table(int row_num,int page_no)
		{
			ostringstream temp;
			temp << page_no;
			string table_entry;
			if(page_no<10)
				table_entry="$00"+temp.str();
			else
				table_entry="$0"+temp.str();
			set_mem(table_entry,page_table_ptr+row_num);
		}
        void store_card(string s,int mem_cnt)
		{
			//extract the words and call the setmem function
			string word="";
			int page_no=allocate_page();
			//occupied_pages[page_no] = true;
			set_page_table(mem_cnt, page_no);
			page_no*=10;
			for(int i=0;i<s.length();i+=4)
			{
				for(int j=0;j<4;j++)
				{
					word+=s[i+j];
				}
				set_mem(word,page_no);
				page_no++;
				word="";
			}
		}
        void print_mem()
		{
			int flag=0;
			for(int i=0;i<300;i++)
			{
				cout<<i<<" ";
				for(int j=0;j<4;j++)
				{
					cout<<Memory[i][j];
				}
				if (flag)
					break;
				cout<<endl;
			}
		}
        int s_to_i(string operand)//ok
		{
			//return the integer no for the given string
			if(operand[0]>='0' && operand[0]<='9' && operand[1]>='0' && operand[1]<='9')
				return ((int)operand[0]-48)*10+((int)operand[1]-48);
			return -1;
		}
        PCB set_limits(string limits, PCB pcb)
		{
			pcb.ID=s_to_i(limits.substr(4,2))*100+s_to_i(limits.substr(6,2));
			pcb.TTL=s_to_i(limits.substr(8,2))*100+s_to_i(limits.substr(10,2));
			pcb.TLL=s_to_i(limits.substr(12,2))*100+s_to_i(limits.substr(14,2));
			pcb.LLC=0;
            return pcb;
		}
    
}MM;
