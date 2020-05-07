/*	Tic Tac Toe
by Devansh Mathur*/

// Header Files

#include <iostream>		//for cin and cout fxn
#include <conio.h>			// for getche() fxn
#include <windows.h>		// for Sleep() fxn
#include <stdio.h>          //for get() fxn
using namespace std;		// for endl

// Variable declaration

char Player[2][10]={"Player 1","Player 2"};
int size = 4;

//fxn for drawing Tic Tac Toe pattern
void Pattern(char val[])
{
	int i,j,x1_len,y1_len,x2_len,y2_len,posn=0;
	x1_len=size;
	y1_len=size*3;
	x2_len=x1_len*3;
	y2_len=y1_len*3;
	cout<<endl;
	for(i=1;i<x2_len;i++)
	{
		for(j=1;j<y2_len;j++)
        {
            if(i%x1_len==0)
            {
                cout<<"-";
            }
            else if(j%y1_len==0)
            {
                cout<<"|";
            }
            else if((i%(x1_len/2)==0&&i%x1_len!=0)&&(j%(y1_len/2)==0&&j%y1_len!=0))
            {
                if(val[posn]==' ')
                {
                    cout<<(char)(posn+97);
                    posn++;
                }
                else
                {
                    cout<<val[posn];
                    posn++;
                }
            }
            else
            {
                cout<<" ";
            }
        }
        cout << endl;
    }
}

// Check validity of move
int validity(char val[],int choice)
{
	int permission=0;
	if(val[choice]==' ')
		permission=1;
	return permission;
}

//check for the winning condition
int winning(char val[])
{
	int i,flag=0;
	for(i=0;i<7;i++)
	{
	    if(val[i]!=' ')
	    {
	        if(i%3==0)
            {
                //checking for rows
                if(val[i]==val[i+1]&&val[i+1]==val[i+2])
                {
                    flag=1;
                    cout<<"true";
                    break;
                }
            }

            if(i<3)
            {
                //checking for columns
                if(val[i]==val[i+3]&&val[i+3]==val[i+6])
                {
                    flag=1;
                    break;
                }
            }

            if(i==0)
            {
                //checking for diagonal
                if(val[i]==val[i+4]&&val[i+4]==val[i+8])
                {
                    flag=1;
                    break;
                }
            }

            if(i==2)
            {
                //checking for diagonal
                if(val[i]==val[i+2]&&val[i+2]==val[i+4])
                {
                    flag=1;
                    break;
                }
            }
	    }
	}
	return flag;
}

//Input names of the user if they want
void name()
{
	char choice;
	system("cls");
	cout<<"Welcome to the Game of Tic Tac Toe";
	cout<<"\nDo You Want to Enter Players Name? (Y/N)\t";
	choice=getche();
	system("cls");
	if(choice == 'Y' || choice == 'y')
	{
		cout<<"\nEnter first name of Player 1 : ";
		gets(Player[0]);
		cout<<"\nEnter first name of Player 2 : ";
		gets(Player[1]);
		system("cls");
		if(strcmp(Player[0],Player[1])==0)
		{
			cout<<"\nSorry! Both Players cannot have same names ";
			cout<<"\nPlease try again";
			Sleep(2000);
			name();
		}
		cout<<"OKEY! Lets get Started.";
		Sleep(2000);
	}
	else if(choice == 'N' || choice == 'n')
	{
		cout<<"OKEY! Lets get Started with Random names";
		Sleep(2000);
	}
	else
	{
		cout<<"\nInvalid choice! Please try again";
		Sleep(2000);
		name();
	}

}
void play()
{
	int i,chance,permission,win;
	char Value[9],choice;
	for(i=0;i<9;i++)
		Value[i]=' ';
	system("cls");
	for(i=0;i<9;i++)
	{
		cout<<"\n"<<Player[0]<<" : X\t"<<Player[1]<<" : O";
		Pattern(Value);
		chance=(i%2)+1;
		cout<<"\nChance : ";//<<Player[chance-1]<<" ";
		puts(Player[chance-1]);
		choice=getche();
		system("cls");
		choice=(choice-97);
		permission=validity(Value,choice);
		if(permission==0)
		{
			cout<<"\nInvalid move ";
			Sleep(2000);
			i--;
		}
		else
		{
			if(chance==1)
				Value[choice]='X';
			else
				Value[choice]='O';
			if(i>3)
			{
				win=winning(Value);
			}
			if(win==1)
			{
				break;
			}
		}
	}
	if(win==1)
	{
	    Pattern(Value);
		if(chance==1)
		{
			cout<<"\nCongratulations! ";
			puts(Player[chance-1]);
			cout<<"Win the game";
		}
		else
		{
			cout<<"\nCongratulations! ";
			puts(Player[chance-1]);
			cout<<"Win the game";
		}

	}
	else
	{
	    Pattern(Value);
		cout<<"\nGame Draw ";

	}



}
int main()
{
	char ch='z';
	do
	{
		name();
		play();
		cout<<"\n\nCreated By Devansh Mathur";
		Sleep(1000);
		printf("\nDo you want to play again (Y/N)\t");
		ch=getche();
		while (ch!='Y' and ch!='y' and ch!='N' and ch!='n')
		{
			printf("\nPlease Enter Valid choice\t");
			ch=getche();
		};
	}while (ch=='Y' || ch=='y');
	return 0;
}
