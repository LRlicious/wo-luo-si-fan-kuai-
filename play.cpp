#include "block.h"
#include "player.h"
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
player::player(){
    memset(Player1_map,0 , sizeof(Player1_map[20][10]));

    memset(Player2_map,0 , sizeof(Player2_map[20][10]));

    Player1_Score = 0;

    Player2_Score = 0;

    win = false;
}