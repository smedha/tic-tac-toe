#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int ar[3][3]={{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};

//returns -1, if the bots cannot be placed at (x,y)
int place(int x, int y, int s)
{
	int i,j;
	if(x>=150 && x<=250)
	{
		i=0;
		if(y<=190)
		{
			j=0;
		}
		else if(y<=290)
		{
			j=1;
		}
		else if(y<=390)
		{
			j=2;
		}
		else
		{
			return -1;
		}
	}
	else if(x>250 && x<=350)
	{
		i=1;
		if(y<=190)
		{
			j=0;
		}
		else if(y<=290)
		{
			j=1;
		}
		else if (y<=350)
		{
			j=2;
		}
		else
		{
			return -1;
		}
	}
	else if(x>350 && x<=450)
	{
		i=2;
		if(y<=190)
		{
			j=0;
		}
		else if(y<=290)
		{
			j=1;
		}
		else if(y<=350)
		{
			j=2;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
	if(ar[i][j]==-1)
	{
		ar[i][j]=s;
		return 1;
	}
	else
	{
		return -1;
	}
}

int win()
{
	if ((ar[0][0]==ar[0][1] && ar[0][1]==ar[0][2] && ar[0][0]!=-1) || (ar[1][0]==ar[1][1] && ar[1][1]==ar[1][2] && ar[1][0]!=-1) 
	|| (ar[2][0]==ar[2][1] && ar[2][1]==ar[2][2] && ar[2][0]!=-1) || (ar[0][1]==ar[1][1] && ar[1][1]==ar[2][1] && ar[0][1]!=-1)
	|| (ar[0][0]==ar[1][0] && ar[1][0]==ar[2][0] && ar[0][0]!=-1) || (ar[0][2]==ar[1][2] && ar[1][2]==ar[2][2] && ar[0][2]!=-1) 
	|| (ar[0][0]==ar[1][1] && ar[1][1]==ar[2][2] && ar[0][0]!=-1) || (ar[0][2]==ar[1][1] && ar[1][1]==ar[2][0] && ar[0][2]!=-1))
	{
		return 1;
	}
	else 
		return -1;
} 
		
void main()
{
	int gd=DETECT,gm;
	int x1=175,y1=115,n=1,check,w;
	char ch;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	setbkcolor(WHITE);
	setcolor(BLUE);
	settextstyle(3,0,5);
	outtextxy(25,20,"Instructions : ");
	setcolor(MAGENTA);
	outtextxy(25,70,"u : up , d: down ");
	setcolor(CYAN);
	outtextxy(25,130, "l : left , r : right ");
	setcolor(BLACK);
	outtextxy(25,180,"Enter key : to place the bot ");
	setcolor(GREEN);
	outtextxy(25,220,"e : exit ");

	outtextxy(25,350,"TIC TAC TOE GAME :");
	setcolor(BROWN);
	outtextxy(25,400,"  Press any key to begin  ");
	getch();
	cleardevice();


	//grid
	setbkcolor(LIGHTBLUE);
	setcolor(MAGENTA);
	rectangle(150,90,450,390);
	setcolor(GREEN);
	line(250,90,250,390);
	setcolor(YELLOW);
	line(350,90,350,390);
	setcolor(CYAN);
	line(150,190,450,190);
	setcolor(RED);
	line(150,290,450,290);
	setcolor(WHITE);
	rectangle(x1,y1,x1+50,y1+50);

	while(1)
	{
		if(n>9)
		{
			setcolor(WHITE);
			settextstyle(3,0,5);
			outtextxy(150,400, "It's a draw !! ");
			break;
		}
		if(n%2==1)
		{
			setcolor(LIGHTBLUE);
			settextstyle(3,0,5);
			outtextxy(20,20,"2nd Player, your turn");
			setcolor(WHITE);
			settextstyle(3,0,5);
			outtextxy(20,20,"1st Player, your turn");
		}
		else
		{
			setcolor(LIGHTBLUE);
			settextstyle(3,0,5);
			outtextxy(20,20,"1st Player, your turn");
			setcolor(YELLOW);
			settextstyle(3,0,5);
			outtextxy(20,20,"2nd Player, your turn");
		}
		ch=getch();
		//ascii value of enter key = 13
		if(ch==13)
		{
			if(n%2==1)
			{
				check=place(x1,y1,1);
				if(check!=-1)
				{
				n++;
				settextstyle(3,0,5);
				outtextxy(x1,y1,"X");
				w=win();
				if(w==1)
				{
					setcolor(YELLOW);
					outtextxy(150,420,"Player 1 wins");
					break;
				}

				}
			}
			else
			{

				check=place(x1,y1,2);
				if(check!=-1)
				{
					n++;
					settextstyle(3,0,5);
					outtextxy(x1,y1,"O");
					if(w==1)
					{
						setcolor(YELLOW);
						outtextxy(150,420,"Player 2 wins");
						break;
					}
				}
			}
			
			
			if(check==-1)
			{
				setcolor(YELLOW);
				outtextxy(10,10,"cannot be placed here");
				delay(10);
				setcolor(LIGHTBLUE);
				outtextxy(10,10,"cannot be placed here");
			}
			
		}
		if(ch=='e')
		{
			break;
		}
		if(ch=='r')
		{
			setcolor(LIGHTBLUE);
			rectangle(x1,y1,x1+50,y1+50);
			x1=x1+100;
			setcolor(WHITE);
			rectangle(x1,y1,x1+50,y1+50);
		}
		if(ch=='u')
		{
			setcolor(LIGHTBLUE);
			rectangle(x1,y1,x1+50,y1+50);
			y1=y1-100;
			setcolor(WHITE);
			rectangle(x1,y1,x1+50,y1+50);
		}
		if(ch=='d')
		{
			setcolor(LIGHTBLUE);
			rectangle(x1,y1,x1+50,y1+50);
			y1=y1+100;
			setcolor(WHITE);
			rectangle(x1,y1,x1+50,y1+50);
		}
		if(ch=='l')
		{
			setcolor(LIGHTBLUE);
			rectangle(x1,y1,x1+50,y1+50);
			x1=x1-100;
			setcolor(WHITE);
			rectangle(x1,y1,x1+50,y1+50);
		}

	}
	getch();
}
