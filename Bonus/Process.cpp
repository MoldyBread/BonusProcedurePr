//Lyash Danylo, IPZ-2

#include <iostream>
#include <windows.h>

using namespace std;

const int N=10;//board const
const int M=10;//mines const
 
int board[N][N];//board array
bool opened[N][N];//mines array

//mine check
bool mine(int i, int j)
{
    if((i>=0) && (i<N))
	{
        if((j>=0) && (j<N))
		{
            if(board[i][j]==-1) 
				return true;
        }
    }
    return false;
}

//Game initializer
void initialize(int i,int j)
{

	int k=0;

    for(int c=0;c<100;c++)
	{ 
		board[c/10][c%10]=0; 
		opened[c/10][c%10]=false; 
	}

    for(int c=0;c<M;c++)
	{
        do
		{
            i=rand()%N; j=rand()%N;
        }
		while(board[i][j]!=0);

        board[i][j]=-1;
    }

    
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(board[i][j]!=-1)
			{
                k=0;
                if(mine(i-1,j-1)) k++;
                if(mine(i-1,j)) k++;
                if(mine(i-1,j+1)) k++;
                if(mine(i,j-1)) k++;
                if(mine(i,j+1)) k++;
                if(mine(i+1,j-1)) k++;
                if(mine(i+1,j)) k++;
                if(mine(i+1,j+1)) k++;
                board[i][j]=k;
            }
}
 


 
//is cell empty
bool isEmpty(int i, int j)
{
    if((i>=0) && (i<N))
	{
        if((j>=0) && (j<N))
		{
            if(board[i][j]==0) 
				return true;
        }
    }
    return false;
}
 
//player step
void step(int i,int j)
{
    if((i>=0) && (i<N))
	{
        if((j>=0) && (j<N))
		{
            if(!opened[i][j])
			{
                opened[i][j]=true;
                if(board[i][j]==0)
				{
                    step(i-1,j-1);
                    step(i-1,j);
                    step(i-1,j+1);
                    step(i,j-1);
                    step(i,j+1);
                    step(i+1,j-1);
                    step(i+1,j);
                    step(i+1,j+1);
                }
                else
				{
                    if(isEmpty(i-1,j-1)) 
						step(i-1,j-1);
                    if(isEmpty(i-1,j)) 
						step(i-1,j);
                    if(isEmpty(i-1,j+1)) 
						step(i-1,j+1);
                    if(isEmpty(i,j-1)) 
						step(i,j-1);
                    if(isEmpty(i,j+1)) 
						step(i,j+1);
                    if(isEmpty(i+1,j-1)) 
						step(i+1,j-1);
                    if(isEmpty(i+1,j)) 
						step(i+1,j);
                    if(isEmpty(i+1,j+1)) 
						step(i+1,j+1);
                }
            }
        }
    }
}


//draws gameboard
void drawBoard(bool error)
{

	if(error)
	{
		cout<<"Write right coordinates"<<endl;
		cout<<endl;
	}

    cout<<"  A B C D E F G H I J"<<endl;
    for(int x=0;x<N;x++)
	{
        cout<<x<<" ";
        for(int y=0;y<N;y++)
		{
            if(opened[x][y])
			{
                if(board[x][y]==-1) 
					cout<<"* ";
                else if(board[x][y]==0) 
					cout<<". ";
                else 
					cout<<board[x][y]<<" ";
            }
            else
			{
                cout<<"# ";
            }
        }
        cout<<endl;
    }
}

//shows mines
void showMines()
{
    for(int i=0;i<N;i++)
	{
        for(int j=0;j<N;j++)
		{
            if(board[i][j]==-1) 
				opened[i][j]=true;
        }
    }
}
 
//end of the game process
void end(bool result)
{
	showMines(); 
	system("cls");
    drawBoard(false);
	cout<<endl;
	cout<<"* - mines"<<endl;
	cout<<endl;
    if(result)
	{
        cout<<"YOU LOST THE GAME!"<<endl;
    }
    else
	{
        cout<<"YOU WIN THE GAME!"<<endl;
	}
	cout<<endl;
    system("pause");
}
 

//checks player's win
bool checkwin()
{
    for(int x=0;x<N;x++)
	{
        for(int y=0;y<N;y++)
		{
            if(!opened[x][y] && board[x][y]!=-1) 
				return false;
        }
    }
    return true;
}