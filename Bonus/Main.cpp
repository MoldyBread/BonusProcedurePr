//Lyash Danylo, IPZ-2

#include <iostream>
#include <time.h>
#include "Header.h"
 
using namespace std;
 
 
int main()
{
	bool writeError=false;
    int i=0,j=0;
    char s[3];
    
    srand((int)time(NULL));

	initialize(i,j);
 
    while(true){
		
        system("cls");

		drawBoard(writeError);
        cout<<endl;

		cout<<"Write coords to open(Example: a1,C3): ";
        cin>>s;

		
		if((s[0]>=65) && (s[0]<=74))
		{
			writeError=false;
			j=s[0]-65;        
		}
        else if((s[0]>=97) && (s[0]<=106)) 
		{
			writeError=false;
			j=s[0]-97;  
		}
        else 
		{
			writeError=true;
			continue; 
		}

        if((s[1]>=48)&&(s[1]<=57)) 
		{
			writeError=false;
			i=s[1]-48;
		}
        else 
		{
			writeError=true;
			continue;
		}



        step(i,j);


        if(mine(i,j))
		{ 
			end(true); 
			break; 
		}  


		if(checkwin()){ 
			end(false); 
			break; 
		}                 
    }
 
    return 0;
}
