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
    player player1;
    char key;
    int speed;
    int tick=100;
    last=GetTickCount();
    while (1){
        now=GetTickCount();
        if(now>last){//自动下落区域
            last+=tick;
        }
        while(_kbhit()){//命令区 wsad与方向键识别（或许把方向键改为更好识别的键？）
            key=_getch();
            switch(key){


                default:break;
            }
        }
    }
}