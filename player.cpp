#include "block.h"
#include "player.h"
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
player::player(){
    memset(Player1_map,0 , sizeof(Player1_map[25][10]));

//    memset(Player2_map,0 , sizeof(Player2_map[20][10]));

    Player1_Score = 0;

//    Player2_Score = 0;

    win = false;

    X=0;
    //这两个值不知道该如何设置
    Y=4;
    Player1_Block_NOW.Create_Block();
    Player1_Block_next.Create_Block();
    
}

void player::Up(){
        block temp=Player1_Block_NOW.Spin_Block();
        if(Ifmove(Player1_Block_NOW,X,Y)){
            return;
        }
        else
        {
            Player1_Block_NOW=temp;
        }
        
}
void player::Right(){
    if(Ifmove(Player1_Block_NOW,X,Y)){
        Y++;
    }
}
void player::Left(){
    if(Ifmove(Player1_Block_NOW,X,Y)){
        Y--;
    }
}
bool player::Down(){    //这里用bool值来判断是否到底部停止，true则接着调用检测消行的 bool Getscore();
    if(Ifmove(Player1_Block_NOW,X,Y)){
        X++;
        return false;
    }
    else
    {
        int i,j;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++)
                if(Player1_Block_NOW.Block[i][j]==1){
                    Player1_map[X+i][Y+j]=1;
                }
        }
        Player1_Block_NOW=Player1_Block_next;
        Player1_Block_next.Create_Block();
        X=0;
        Y=4;
        return true;
    }
    
}
bool player::Ifmove(block bl, int x, int y) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            // 如果检测到block中该位置为1的话
            // 先检测这个位置是否越界
            // 再检测这个位置对应的map位置是否也为1
            if(bl.Block[i][j]==1) {
                if(x + i >= 25 || y + j < 0 || y + j >= 10) {
                    return false;
                }
                else if(Player1_map[x+i][y+j]==1 && x + i >=0) {
                    return false;
                }
            }
        }
    }
    return true;
}
void player::Addline(int t){
    for(int i=0;i<t;i++){
        for(int m=0; m<19; m++) {
            for(int n=0; n<10; n++) {
                Player1_map[m][n]=Player1_map[m+1][n];
            }
        }
        for(int j=0; j<10; j++) {
                Player1_map[19][j] = 0;
        }
        for(int j=0; j<10; j++) {
            Player1_map[19][j]=1;
        }
        Player1_map[19][rand()%10]=0;
    }
}
bool player::Faile(){       //若上边界处出现1（及0——4排），则判负，返回false,游戏结束。
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<10;j++){
            if(Player1_map[i][j]==1){
                return false;
            }
        }
    }
    return true;
}
int player::Getscore(){
    int count;
    for(int i=0;i<25;i++){
        int flag=1;
        for(int j=0;j<10;j++){
            if(Player1_map[i][j]==0){
                flag=0;
                break;
            }
        }
        if(flag!=0){
            Player1_Score+=10;
            count++;
            for(int k=i;k>=1;k--) {
                for(int j=0;j<10;j++) {
                    Player1_map[k][j]=Player1_map[k-1][j];
                }
            }
        }
    }
    return count;
}