#include<cstdio>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#define xx 29
#define yy 20
#define wall 2
#define box 1
#define kong 0
#define SPACE 32
#define LEFT  75
#define RIGHT 77
#define DOWN 80
#define UP 72
#define ESC 27
using namespace std;
int nn=0;
int Block[7][4][4][4]={0};
typedef struct Diamonds
{   int space[4][4];        //4*4矩阵，为1为方块，为0 为空
}Dia;
Dia dia[7][4];
int face[xx][yy+39]={0};
void init_dia();
void start_game();
void draw_dia(int n,int space_c,int x,int y);   //覆盖方块
void draw_kong(int n,int space_c,int x,int y);
int pd(int n,int space_c,int x,int y);
void csh();
int xc();
void gotoxy(int x,int y);
void hidden_cursor()//隐藏光标
{
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cci;
  GetConsoleCursorInfo(hOut,&cci);
  cci.bVisible=0;//赋1为显示，赋0为隐藏
  SetConsoleCursorInfo(hOut,&cci);
}
class player{
	private:
		int score;
	public:
		void move_(int n,int space_c,int x,int y);
};
void player::move_(int n,int space_c,int x,int y)
{
	 draw_kong(n,space_c,x,y);
}

void modeset(int w,int h) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size = {w, h};
	SetConsoleScreenBufferSize(hOut,size);
	SMALL_RECT rc = {1,1, w, h};
	SetConsoleWindowInfo(hOut ,true ,&rc);
	system("cls");
	return;
}
void ks(){
	gotoxy(12,50);
	printf("  我罗斯方块");
	gotoxy(14,53);
	printf(" 开始");
	gotoxy(16,50);printf("(请按enter键)"); 
}
int main(){
	hidden_cursor();
	modeset(120,60);
	ks();
	init_dia();
	if(getchar()=='\n'){
		system("cls");
		csh();
	}
	while(1){
		start_game();
	}
	system("pause>nul");
	return 0;
}
void gotoxy(int x,int y) //移动坐标
{
    COORD coord;
    coord.X=y;
    coord.Y=x;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}

int xc(){
	int sum=0,k,j,i;
	for(i=xx-2;i>4;i--)
	{
		sum=0;
		for(j=1;j<yy-1;j++)
		{
			sum+=face[i][j];
		}
		if(sum==0) break;
		if(sum==yy-2)
		{
			for(j=1;j<yy-1;j++){
				face[i][j]=0;
				gotoxy(i,2*j);
				printf(" ");
			}
		
			for(j=i;j>1;j--)
            {   sum=0;
                for(k=1;k<yy-1;k++)
                {
                    sum+=face[j-1][k]+face[j][k];
                    face[j][k]=face[j-1][k];
                    if(face[j][k]==0)
                    {
                        gotoxy(j,2*k);
                        cout<<" ";
                    }
                    else
                    {
                        gotoxy(j,2*k);
                        cout<<"■";
                    }
                }
                if(sum==0)
                    return 1;
            }
		}
		
	}
	return 0;
}
void csh()//初始化页面。 
{
	
   int i,j;
    for(i=0;i<xx;i++)
    {   for(j=0;j<yy+39;j++)
        {   if(j==0 || j==yy-1 || j==yy+9||j==yy+19||j==yy+38)
            {   face[i][j]=wall;
                gotoxy(i,2*j);
                printf("■");
            }
            else if(i==xx-1)
            {   face[i][j]=box;
                gotoxy(i,2*j);
                printf("■");
            }
            else
            face[i][j]=kong;
        }
    }

    gotoxy(xx-18,2*yy+2);
    printf("左移：d");
    
	gotoxy(xx-18,2*yy+2+20);
    printf("左移：Left");
    
    gotoxy(xx-16,2*yy+2);
    printf("右移：a");

	gotoxy(xx-16,2*yy+2+20);
    printf("右移：Right");
    
    gotoxy(xx-14,2*yy+2);
    printf("旋转：w");
	
	gotoxy(xx-14,2*yy+2+20);
    printf("旋转：Up");
    
    gotoxy(xx-12,2*yy+2);
    printf("暂停: Q");

	gotoxy(xx-12,2*yy+2+20);
    printf("暂停: SPACE");
    
    gotoxy(xx-10,2*yy+2);
    printf("退出: ESC");
    
    gotoxy(xx-10,2*yy+2+20);
    printf("退出: ESC");
}
void draw_dia(int n,int space_c,int x,int y)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            gotoxy(x+i,2*(y+j));
            if(dia[n][space_c].space[i][j]==1)
            printf("■");
        }
    }
}
void draw_kong(int n,int space_c,int x,int y)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            gotoxy(x+i,2*(y+j));
            if(dia[n][space_c].space[i][j]==1)
            printf(" ");
        }
    }

}
int pd(int n,int space_c,int x,int y)   //判断是否到底
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
           if(dia[n][space_c].space[i][j]==0)
               continue;
           else if(face[x+i][y+j]==wall||face[x+i][y+j]==box)
               return 0;
        }
    }
    return 1;
}
void start_game()
{  player player1,player2;
   int n,ch,t=0,x=0,y=yy/2-2,i,j;
    int space_c=0;//旋转次数
    draw_kong(nn,space_c,4,yy+3);
    n=nn;   
    nn=rand()%7;    //随机生成下一块
    draw_dia(nn,space_c,4,yy+3);
    while(1)
    {   
        draw_dia(n,space_c,x,y);//画出图形
        if(t==0)
            t=15000;
        while(--t)
        {   if(kbhit()!=0)//有输入就跳出
                break;  
        }
        if(t==0)
        {
            if(pd(n,space_c,x+1,y)==1)
            {   draw_kong(n,space_c,x,y);
                x++;          //向下降落
            }
            else
            {
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    { 
                        if(dia[n][space_c].space[i][j]==1)
                        {   
                           	face[x+i][y+j]=box;
                           	while(xc()){} 
                        }
                    }
                }
                return;
            }
        }
        else
        {
            ch=getch();
            switch(ch)     //移动
            {
            case LEFT: if(pd(n,space_c,x,y-1)==1)   //判断是否可以移动
                       {   player1.move_(n,space_c,x,y);
                           y--;
                       }
                       break;
            case RIGHT: if(pd(n,space_c,x,y+1)==1)
                        {   player1.move_(n,space_c,x,y);
                            y++;
                        }
                        break;
            case DOWN: if(pd(n,space_c,x+1,y)==1)
                        {   player1.move_(n,space_c,x,y);
                            x++;
                        }
                        break;
            case UP: if(pd(n,(space_c+1)%4,x+1,y)==1)
                        {   player1.move_(n,space_c,x,y);
                            space_c=(space_c+1)%4;
                        }
                        break;
            case 'a': if(pd(n,space_c,x,y-1)==1)   //判断是否可以移动
                       {   player2.move_(n,space_c,x,y);
                           y--;
                       }
                       break;
            case 'd': if(pd(n,space_c,x,y+1)==1)
                        {   player2.move_(n,space_c,x,y);
                            y++;
                        }
                        break;
            case 's': if(pd(n,space_c,x+1,y)==1)
                        {  player2.move_(n,space_c,x,y);
                            x++;
                        }
                        break;
            case 'w': if(pd(n,(space_c+1)%4,x+1,y)==1)
                        {   player2.move_(n,space_c,x,y);
                            space_c=(space_c+1)%4;
                        }
                        break;
            case ESC  : system("cls");
                        gotoxy(xx/2,yy);
                        printf("---游戏结束!---\n\n");
                        gotoxy(xx/2+2,yy);
                        printf("---按任意键退出!---\n");
                        getch();
                        exit(0);
                        break;
            case SPACE :
            case  'q':  while(1)
                        {   if(kbhit()!=0)//有输入就跳出
                            break;  
                        }
                        break;
            case  'r':  main();
                        exit(0);
			}
        
        }
    }
}

void init_dia()
{
    int i,j,k,z;
    int tmp[4][4];
    for(i=0;i<3;i++)
    dia[0][0].space[1][i]=1;
    dia[0][0].space[2][1]=1;     //土形

    for(i=1;i<4;i++)
        dia[1][0].space[i][1]=1;
    dia[1][0].space[1][2]=1;    //L形--1

    for(i=1;i<4;i++)
        dia[2][0].space[i][2]=1;
    dia[2][0].space[1][1]=1;    //L形--2

    for(i=0;i<2;i++)
    {   dia[3][0].space[1][i]=1;
        dia[3][0].space[2][i+1]=1; //Z形--1

        dia[4][0].space[1][i+1]=1;
        dia[4][0].space[2][i]=1;//Z形--2

        dia[5][0].space[1][i+1]=1;
        dia[5][0].space[2][i+1]=1;//田字形
    }
    for(i=0;i<4;i++)
        dia[6][0].space[i][2]=1;//1形 
    //////////////////////////////////基础7个形状
    for(i=0;i<7;i++)
    {
        for(z=0;z<3;z++)
        {
            for(j=0;j<4;j++)
            {
                for(k=0;k<4;k++)
                {
                  tmp[j][k]=dia[i][z].space[j][k];
                }   
            }
            for(j=0;j<4;j++)
            {
                for(k=0;k<4;k++)
                {
                  dia[i][z+1].space[j][k]=tmp[4-k-1][j];
                }   
            }
        }
    }
    ///////////////////////////////////旋转后的21个形状
}
    
