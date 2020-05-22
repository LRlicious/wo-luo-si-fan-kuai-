#include "block.h"
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
block::block(){             //初始化方块
    //数轴  [x][y]
    //[x]
    // 0 1 2 3  [y]
    // 1
    // 2
    // 3

    memset(Block_1 ,0 , sizeof(Block_1[4][4][4]));
    Block_1[0][2][0] = 0;    //0 0 0 0
    Block_1[0][2][1] = 0;    //0 0 0 0
    Block_1[0][3][0] = 0;    //1 1 0 0
    Block_1[0][3][1] = 0;    //1 1 0 0

    Block_1[1][2][0] = 0;    //0 0 0 0
    Block_1[1][2][1] = 0;    //0 0 0 0
    Block_1[1][3][0] = 0;    //1 1 0 0
    Block_1[1][3][1] = 0;    //1 1 0 0

    Block_1[2][2][0] = 0;    //0 0 0 0
    Block_1[2][2][1] = 0;    //0 0 0 0
    Block_1[2][3][0] = 0;    //1 1 0 0
    Block_1[2][3][1] = 0;    //1 1 0 0

    Block_1[3][2][0] = 0;    //0 0 0 0
    Block_1[3][2][1] = 0;    //0 0 0 0
    Block_1[3][3][0] = 0;    //1 1 0 0
    Block_1[3][3][1] = 0;    //1 1 0 0

    memset(Block_2 ,0 , sizeof(Block_2[4][4][4]));
    Block_2[0][0][0] = 1;    //1 0 0 0 
    Block_2[0][1][0] = 1;    //1 0 0 0 
    Block_2[0][2][0] = 1;    //1 0 0 0 
    Block_2[0][3][0] = 1;    //1 0 0 0 

    Block_2[1][0][0] = 1;    //1 1 1 1 
    Block_2[1][0][1] = 1;    //0 0 0 0
    Block_2[1][0][2] = 1;    //0 0 0 0
    Block_2[1][0][3] = 1;    //0 0 0 0

    Block_2[2][0][0] = 1;    //1 0 0 0 
    Block_2[2][1][0] = 1;    //1 0 0 0 
    Block_2[2][2][0] = 1;    //1 0 0 0 
    Block_2[2][3][0] = 1;    //1 0 0 0 

    Block_2[3][0][0] = 1;    //1 1 1 1 
    Block_2[3][0][1] = 1;    //0 0 0 0
    Block_2[3][0][2] = 1;    //0 0 0 0
    Block_2[3][0][3] = 1;    //0 0 0 0

    memset(Block_3 ,0 , sizeof(Block_3[4][4][4]));
    Block_3[0][1][0] = 1;    //0 0 0 0
    Block_3[0][2][0] = 1;    //1 0 0 0
    Block_3[0][3][0] = 1;    //1 0 0 0
    Block_3[0][3][1] = 1;    //1 1 0 0

    Block_3[1][2][0] = 1;    //0 0 0 0
    Block_3[1][2][1] = 1;    //0 0 0 0
    Block_3[1][2][2] = 1;    //1 1 1 0
    Block_3[1][3][0] = 1;    //1 0 0 0

    Block_3[2][1][0] = 1;    //0 0 0 0
    Block_3[2][1][1] = 1;    //1 1 0 0
    Block_3[2][2][1] = 1;    //0 1 0 0
    Block_3[2][3][1] = 1;    //0 1 0 0

    Block_3[3][2][0] = 1;    //0 0 0 0
    Block_3[3][3][0] = 1;    //0 0 0 0
    Block_3[3][3][1] = 1;    //1 0 0 0
    Block_3[3][3][2] = 1;    //1 1 1 0

    memset(Block_4 ,0 , sizeof(Block_4[4][4][4]));
    Block_4[0][2][0] = 1;    //0 0 0 0
    Block_4[0][2][0] = 1;    //0 1 0 0
    Block_4[0][2][0] = 1;    //0 1 0 0
    Block_4[0][2][0] = 1;    //1 1 0 0

    Block_4[1][2][0] = 1;    //0 0 0 0
    Block_4[1][3][0] = 1;    //0 0 0 0
    Block_4[1][3][1] = 1;    //1 0 0 0
    Block_4[1][3][2] = 1;    //1 1 1 0

    Block_4[2][1][0] = 1;    //0 0 0 0
    Block_4[2][1][1] = 1;    //1 1 0 0
    Block_4[2][2][0] = 1;    //1 0 0 0
    Block_4[2][3][0] = 1;    //1 0 0 0

    Block_4[3][1][0] = 1;    //0 0 0 0
    Block_4[3][1][0] = 1;    //0 0 0 0
    Block_4[3][1][0] = 1;    //1 1 1 0
    Block_4[3][1][0] = 1;    //0 0 1 0

    memset(Block_5 ,0 , sizeof(Block_5[4][4][4]));
    Block_5[0][2][1] = 1;    //0 0 0 0
    Block_5[0][3][0] = 1;    //0 0 0 0
    Block_5[0][3][1] = 1;    //0 1 0 0
    Block_5[0][3][2] = 1;    //1 1 1 0

    Block_5[1][1][1] = 1;    //0 0 0 0
    Block_5[1][2][1] = 1;    //0 1 0 0
    Block_5[1][2][2] = 1;    //0 1 1 0
    Block_5[1][3][1] = 1;    //0 1 0 0

    Block_5[2][2][0] = 1;    //0 0 0 0
    Block_5[2][2][1] = 1;    //0 0 0 0
    Block_5[2][2][2] = 1;    //1 1 1 0
    Block_5[2][3][1] = 1;    //0 1 0 0

    Block_5[3][1][1] = 1;    //0 0 0 0
    Block_5[3][2][0] = 1;    //0 1 0 0
    Block_5[3][2][1] = 1;    //1 1 0 0
    Block_5[3][3][1] = 1;    //0 1 0 0

    memset(Block_6 ,0 , sizeof(Block_6[4][4][4]));
    Block_6[0][2][0] = 1;    //0 0 0 0
    Block_6[0][2][1] = 1;    //0 0 0 0
    Block_6[0][3][1] = 1;    //1 1 0 0
    Block_6[0][3][2] = 1;    //0 1 1 0

    Block_6[1][2][0] = 1;    //0 0 0 0
    Block_6[1][2][1] = 1;    //0 1 0 0
    Block_6[1][3][1] = 1;    //1 1 0 0
    Block_6[1][3][2] = 1;    //1 0 0 0

    Block_6[2][2][0] = 1;    //0 0 0 0
    Block_6[2][2][1] = 1;    //0 0 0 0
    Block_6[2][3][1] = 1;    //1 1 0 0
    Block_6[2][3][2] = 1;    //0 1 1 0

    Block_6[3][2][0] = 1;    //0 0 0 0
    Block_6[3][2][1] = 1;    //0 1 0 0
    Block_6[3][3][1] = 1;    //1 1 0 0
    Block_6[3][3][2] = 1;    //1 0 0 0

    memset(Block_7 ,0 , sizeof(Block_7[4][4][4]));
    Block_7[0][2][0] = 1;    //0 0 0 0
    Block_7[0][2][1] = 1;    //0 0 0 0
    Block_7[0][3][1] = 1;    //0 1 1 0
    Block_7[0][3][2] = 1;    //1 1 0 0

    Block_7[1][2][0] = 1;    //0 0 0 0
    Block_7[1][2][1] = 1;    //1 0 0 0
    Block_7[1][3][1] = 1;    //1 1 0 0
    Block_7[1][3][2] = 1;    //0 1 0 0

    Block_7[2][2][0] = 1;    //0 0 0 0
    Block_7[2][2][1] = 1;    //0 0 0 0
    Block_7[2][3][1] = 1;    //0 1 1 0
    Block_7[2][3][2] = 1;    //1 1 0 0

    Block_7[3][2][0] = 1;    //0 0 0 0
    Block_7[3][2][1] = 1;    //1 0 0 0
    Block_7[3][3][1] = 1;    //1 1 0 0
    Block_7[3][3][2] = 1;    //0 1 0 0
}
void block::Create_Block(){         //创建新方块
    srand((unsigned)time(NULL));  //初始化随机数
    switch (rand()%7)
    {
    case 0:{
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                BlockNext[i][j]=Block_1[0][i][j];
            }
        }
    }
     case 1:{
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                BlockNext[i][j]=Block_2[0][i][j];
            }
        }
    }
     case 2:{
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                BlockNext[i][j]=Block_3[0][i][j];
            }
        }
    }
     case 3:{
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                BlockNext[i][j]=Block_4[0][i][j];
            }
        }
    }
     case 4:{
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                BlockNext[i][j]=Block_5[0][i][j];
            }
        }
    }
     case 5:{
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                BlockNext[i][j]=Block_6[0][i][j];
            }
        }
    }
     case 6:{
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                BlockNext[i][j]=Block_7[0][i][j];
            }
        }
    }

    }
}
void block::Change_Block(){
    for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                BlockNow[i][j]=BlockNext[i][j];
            }
        }
        Create_Block();
    }

void block::Start_Block(){
    Create_Block();
    Change_Block();
}
    
