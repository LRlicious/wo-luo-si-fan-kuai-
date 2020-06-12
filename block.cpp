#include "block.h"
#include <string.h>
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

    memset(BLOCK ,0 , sizeof(BLOCK[7][4][4][4]));
    {
	    BLOCK[0][0][1][1] = 1;    //0 0 0 0
	    BLOCK[0][0][2][1] = 1;    //0 1 1 0
	    BLOCK[0][0][1][2] = 1;    //0 1 1 0
    	BLOCK[0][0][2][2] = 1;    //0 0 0 0
    	
    	BLOCK[0][1][1][1] = 1;    //0 0 0 0
    	BLOCK[0][1][2][1] = 1;    //0 1 1 0
    	BLOCK[0][1][1][2] = 1;    //0 1 1 0
    	BLOCK[0][1][2][2] = 1;    //0 0 0 0
    	
		BLOCK[0][2][1][1] = 1;    //0 0 0 0
    	BLOCK[0][2][2][1] = 1;    //0 1 1 0
    	BLOCK[0][2][1][2] = 1;    //0 1 1 0
    	BLOCK[0][2][2][2] = 1;    //0 0 0 0
		
    	BLOCK[0][3][1][1] = 1;    //0 0 0 0
    	BLOCK[0][3][2][1] = 1;    //0 1 1 0
    	BLOCK[0][3][1][2] = 1;    //0 1 1 0
    	BLOCK[0][3][2][2] = 1;    //0 0 0 0
	}
    {
    	BLOCK[1][0][0][1] = 1;    //0 1 0 0 
    	BLOCK[1][0][1][1] = 1;    //0 1 0 0 
    	BLOCK[1][0][2][1] = 1;    //0 1 0 0 
    	BLOCK[1][0][3][1] = 1;    //0 1 0 0 
		
    	BLOCK[1][1][1][0] = 1;    //0 0 0 0 
    	BLOCK[1][1][1][1] = 1;    //1 1 1 1
    	BLOCK[1][1][1][2] = 1;    //0 0 0 0
    	BLOCK[1][1][1][3] = 1;    //0 0 0 0
		
    	BLOCK[1][2][0][2] = 1;    //0 0 1 0 
    	BLOCK[1][2][1][2] = 1;    //0 0 1 0 
    	BLOCK[1][2][2][2] = 1;    //0 0 1 0 
	    BLOCK[1][2][3][2] = 1;    //0 0 1 0 
		
    	BLOCK[1][3][2][0] = 1;    //0 0 0 0 
    	BLOCK[1][3][2][1] = 1;    //0 0 0 0
    	BLOCK[1][3][2][2] = 1;    //1 1 1 1
    	BLOCK[1][3][2][3] = 1;    //0 0 0 0
	}
    {
    	BLOCK[2][0][0][1] = 1;    //0 1 0 0
    	BLOCK[2][0][1][1] = 1;    //0 1 0 0
    	BLOCK[2][0][2][1] = 1;    //0 1 1 0
    	BLOCK[2][0][2][2] = 1;    //0 0 0 0

    	BLOCK[2][1][1][1] = 1;    //0 0 0 0
    	BLOCK[2][1][1][2] = 1;    //0 1 1 1
    	BLOCK[2][1][1][3] = 1;    //0 1 0 0
    	BLOCK[2][1][2][1] = 1;    //0 0 0 0

    	BLOCK[2][2][1][1] = 1;    //0 0 0 0
    	BLOCK[2][2][1][2] = 1;    //0 1 1 0
    	BLOCK[2][2][2][2] = 1;    //0 0 1 0
    	BLOCK[2][2][3][2] = 1;    //0 0 1 0

    	BLOCK[2][3][1][2] = 1;    //0 0 0 0
    	BLOCK[2][3][2][0] = 1;    //0 0 1 0
    	BLOCK[2][3][2][1] = 1;    //1 1 1 0
    	BLOCK[2][3][2][2] = 1;    //0 0 0 0
	}
    {
    	BLOCK[3][0][0][2] = 1;    //0 0 1 0
    	BLOCK[3][0][1][2] = 1;    //0 0 1 0
    	BLOCK[3][0][2][1] = 1;    //0 1 1 0
    	BLOCK[3][0][2][2] = 1;    //0 0 0 0

    	BLOCK[3][1][1][1] = 1;    //0 0 0 0
    	BLOCK[3][1][2][1] = 1;    //0 1 0 0
   		BLOCK[3][1][2][2] = 1;    //0 1 1 1
   		BLOCK[3][1][2][3] = 1;    //0 0 0 0
		
	    BLOCK[3][2][1][1] = 1;    //0 0 0 0
	    BLOCK[3][2][1][2] = 1;    //0 1 1 0
	    BLOCK[3][2][2][1] = 1;    //0 1 0 0
	    BLOCK[3][2][3][1] = 1;    //0 1 0 0
	
	    BLOCK[3][3][1][0] = 1;    //0 0 0 0
	    BLOCK[3][3][1][1] = 1;    //1 1 1 0
	    BLOCK[3][3][1][2] = 1;    //0 0 1 0
	    BLOCK[3][3][2][2] = 1;    //0 0 0 0
	}
    {
    	BLOCK[4][0][1][1] = 1;    //0 0 0 0
    	BLOCK[4][0][2][0] = 1;    //0 1 0 0
    	BLOCK[4][0][2][1] = 1;    //1 1 1 0
    	BLOCK[4][0][2][2] = 1;    //0 0 0 0
	
	    BLOCK[4][1][1][1] = 1;    //0 0 0 0
	    BLOCK[4][1][2][1] = 1;    //0 1 0 0
	    BLOCK[4][1][2][2] = 1;    //0 1 1 0
	    BLOCK[4][1][3][1] = 1;    //0 1 0 0
	
	    BLOCK[4][2][2][0] = 1;    //0 0 0 0
    	BLOCK[4][2][2][1] = 1;    //0 0 0 0
    	BLOCK[4][2][2][2] = 1;    //1 1 1 0
    	BLOCK[4][2][3][1] = 1;    //0 1 0 0
	
	    BLOCK[4][3][1][1] = 1;    //0 0 0 0
	    BLOCK[4][3][2][0] = 1;    //0 1 0 0
	    BLOCK[4][3][2][1] = 1;    //1 1 0 0
	    BLOCK[4][3][3][1] = 1;    //0 1 0 0
	}
    {
    	BLOCK[5][0][1][0] = 1;    //0 0 0 0
    	BLOCK[5][0][1][1] = 1;    //1 1 0 0
    	BLOCK[5][0][2][1] = 1;    //0 1 1 0
    	BLOCK[5][0][2][2] = 1;    //0 0 0 0

	    BLOCK[5][1][1][2] = 1;    //0 0 0 0
    	BLOCK[5][1][2][1] = 1;    //0 0 1 0
    	BLOCK[5][1][2][2] = 1;    //0 1 1 0
    	BLOCK[5][1][3][1] = 1;    //0 1 0 0

    	BLOCK[5][2][1][1] = 1;    //0 0 0 0
    	BLOCK[5][2][1][2] = 1;    //0 1 1 0
    	BLOCK[5][2][2][2] = 1;    //0 0 1 1
    	BLOCK[5][2][2][3] = 1;    //0 0 0 0
	
    	BLOCK[5][3][0][2] = 1;    //0 0 1 0
    	BLOCK[5][3][1][1] = 1;    //0 1 1 0
    	BLOCK[5][3][1][2] = 1;    //0 1 0 0
    	BLOCK[5][3][2][1] = 1;    //0 0 0 0
    }
    {
		BLOCK[6][0][1][1] = 1;    //0 0 0 0
    	BLOCK[6][0][1][2] = 1;    //0 1 1 0
    	BLOCK[6][0][2][0] = 1;    //1 1 0 0
    	BLOCK[6][0][2][1] = 1;    //0 0 0 0
	
	    BLOCK[6][1][1][1] = 1;    //0 0 0 0
	    BLOCK[6][1][2][1] = 1;    //0 1 0 0
	    BLOCK[6][1][2][2] = 1;    //0 1 1 0
	    BLOCK[6][1][3][2] = 1;    //0 0 1 0
	
	    BLOCK[6][2][1][2] = 1;    //0 0 0 0
	    BLOCK[6][2][1][3] = 1;    //0 0 1 1
	    BLOCK[6][2][2][1] = 1;    //0 1 1 0
	    BLOCK[6][2][2][2] = 1;    //0 0 0 0
	
	    BLOCK[6][3][0][1] = 1;    //0 1 0 0
	    BLOCK[6][3][1][1] = 1;    //0 1 1 0
	    BLOCK[6][3][1][2] = 1;    //0 0 1 0
	    BLOCK[6][3][2][2] = 1;    //0 0 0 0
	}
}
void block::Create_Block(){         //创建新方块
    srand((unsigned)time(NULL));  //初始化随机数
    unsigned int ran=rand()%7;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            Block[i][j]=BLOCK[ran][0][i][j];
        }
    }
}
void  Change_Block(block b1,block b2){      //将next的block置入now的block并更新next
    for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                b2.Block[i][j]=b1.Block[i][j];
            }
        }
    b2.Create_Block();
}

block block::Spin_Block(){
	block b2;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			b2.Block[3-i][j]=Block[i][j];
		}
	}
	return b2;
}
/*void block::Change_Block(){
    for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                Block[i][j]=BlockNext[i][j];
            }
        }
        Create_Block();
    }
*/
/*void block::Start_Block(){
    Create_Block();
    Change_Block();
}*/
    
