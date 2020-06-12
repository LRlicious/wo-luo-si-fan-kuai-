#include<iostream>
#include"player.h"
#include"block.h"
#include"render.h"
#include"game.h"
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <Windows.h>
#include<conio.h>
ULONGLONG now,last;
void game::start_game(){
    player player1,player2;
    char key;
    int speed;
    int tick=100;
    last=GetTickCount();
    while (1){
        now=GetTickCount();
        if(now>last){//自动下落区域
            last+=tick;
            if(player1.Down()){
                    if(player1.Faile()){
                        player2.win=true;
                    }
                    int t=player1.Getscore();
                    if(t)
                    {
                        player2.Addline(t);
                        if(player2.Faile()){
                        player1.win=true;
                    }
                    }
                    
                }
             if(player2.Down()){
                    if(player2.Faile()){
                        player1.win=true;
                    }
                    int t=player2.Getscore();
                    if(t)
                    {
                        player1.Addline(t);
                        if(player1.Faile()){
                        player2.win=true;
                    }
                    }
                    
                
                }
        }
        while(_kbhit()){//命令区 wsad与8456识别
            key=_getch();
            if(key=='w'){
                player1.Up();
            }
            else if(key=='8'){
                player2.Up();
            }    
            else if(key=='a'){
                player1.Left();
            }
            else if(key=='4'){
                player2.Left();
            }
            else if(key=='s'){
                if(player1.Down()){
                     if(player1.Faile()){
                        player2.win=true;
                    }
                    int t=player1.Getscore();
                    if(t)
                    {
                        player2.Addline(t);
                        if(player2.Faile()){
                        player1.win=true;
                    }

                    }
                    
                    
                }
                
            }
            else if(key=='5'){
                if(player2.Down()){
                     if(player2.Faile()){
                        player1.win=true;
                    }
                    int t=player2.Getscore();
                    if(t)
                    {
                        player1.Addline(t);
                        if(player1.Faile()){
                        player2.win=true;
                    }
                    }
                    
                
                }
                
            }
            else if(key=='d'){
                player1.Right();
            }
            else if(key=='6'){
                player2.Right();
            }
            }
        Sleep(20);// 降低CPU占用
        if(player1.win==true){      //执行结束 还差一个endgame渲染函数

            return;
        }
        if(player2.win==true){      //执行结束 

            return;
        }
    }
}