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
            //此处应有游戏界面初始化渲染用的函数
    while (1){
        now=GetTickCount();
        if(now>last){//自动下落区域
            last+=tick;
            if(player1.Down()){
                        //此处应有游戏界面更新用的函数
                    if(player1.Faile()){
                        player2.win=true;
                    }
                    int t=player1.Getscore();
                    if(t)
                    {
                            //此处应有游戏界面更新用的函数
                        player2.Addline(t);
                            //此处应有游戏界面更新用的函数
                        if(player2.Faile()){
                        player1.win=true;
                    }
                    }
                    
                }
             if(player2.Down()){
                        //此处应有游戏界面更新用的函数
                    if(player2.Faile()){
                        player1.win=true;
                    }
                    int t=player2.Getscore();
                    if(t)
                    {
                            //此处应有游戏界面更新用的函数
                        player1.Addline(t);
                            //此处应有游戏界面更新用的函数
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
                    //此处应有游戏界面更新用的函数
            }
            else if(key=='8'){
                player2.Up();
                    //此处应有游戏界面更新用的函数
            }    
            else if(key=='a'){
                player1.Left();
                    //此处应有游戏界面更新用的函数
            }
            else if(key=='4'){
                player2.Left();
                    //此处应有游戏界面更新用的函数
            }
            else if(key=='s'){
                if(player1.Down()){
                        //此处应有游戏界面更新用的函数
                     if(player1.Faile()){
                        player2.win=true;
                    }
                    int t=player1.Getscore();
                    if(t)
                    {
                            //此处应有游戏界面更新用的函数
                        player2.Addline(t);
                            //此处应有游戏界面更新用的函数
                        if(player2.Faile()){
                        player1.win=true;
                    }

                    }
                    
                    
                }
                
            }
            else if(key=='5'){
                if(player2.Down()){
                        //此处应有游戏界面更新用的函数
                     if(player2.Faile()){
                        player1.win=true;
                    }
                    int t=player2.Getscore();
                    if(t)
                    {
                            //此处应有游戏界面更新用的函数
                        player1.Addline(t);
                            //此处应有游戏界面更新用的函数
                        if(player1.Faile()){
                        player2.win=true;
                    }
                    }
                    
                
                }
                
            }
            else if(key=='d'){
                player1.Right();
                    //此处应有游戏界面更新用的函数
            }
            else if(key=='6'){
                player2.Right();
                    //此处应有游戏界面更新用的函数
            }
            }
        Sleep(20);// 降低CPU占用
        if(player1.win==true){      //执行结束 
                //此处应有显示玩家1获胜用的函数
            return;
        }
        if(player2.win==true){      //执行结束 
                //此处应有显示玩家2获胜用的函数
            return;
        }
    }
}