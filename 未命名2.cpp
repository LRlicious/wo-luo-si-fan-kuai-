#include<stdio.h>
#include<windows.h>
#define SPACE 32
#define Wall 2
#define Box 1
#define Kong 0
#define FACE_X 29
#define FACE_Y 20   //界面尺寸	

void gotoxy(int x,int y) //移动坐标
{
    COORD coord;
    coord.X=y;
    coord.Y=x;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
struct Face
{
    int data[FACE_X][FACE_Y+10];    //数值，为1是方块，为0是空格
}face;
void inter_face();
int main()
{   
    system("cls");
    system("title 俄罗斯方块");
    system("mode con cols=70 lines=40");  //窗口宽度高度 
 
	inter_face();
	system("pause>nul");
    return 0;
}
void inter_face()//界面
{   int i,j;
    for(i=0;i<FACE_X;i++)
    {   for(j=0;j<FACE_Y+10;j++)
        {   if(j==0 || j==FACE_Y-1 || j==FACE_Y+9)
            {   face.data[i][j]=Wall;
                gotoxy(i,2*j);
                printf("■");
            }
            else if(i==FACE_X-1)
            {   face.data[i][j]=Box;
                gotoxy(i,2*j);
                printf("■");
            }
            else
            face.data[i][j]=Kong;
        }
    }
    gotoxy(FACE_X-18,2*FACE_Y+2);
    printf("左移：←");

    gotoxy(FACE_X-16,2*FACE_Y+2);
    printf("右移：→");

    gotoxy(FACE_X-14,2*FACE_Y+2);
    printf("旋转：space");

    gotoxy(FACE_X-12,2*FACE_Y+2);
    printf("暂停: S");

    gotoxy(FACE_X-10,2*FACE_Y+2);
    printf("退出: ESC");

    gotoxy(FACE_X-8,2*FACE_Y+2);
    printf("重新开始:R");
}
