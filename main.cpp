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
using namespace std;

int main(){

    //此处应有渲染开始界面函数
    if(_kbhit()){
    srand((unsigned)time(NULL));  //初始化随机数
    game::start_game();

    }
    
}