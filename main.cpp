#include<iostream>
#include"player.h"
#include"block.h"
#include"render.h"
#include"game.h"
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
using namespace std;

int main(){
    srand((unsigned)time(NULL));  //初始化随机数
    game::start_game();

}