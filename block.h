#ifndef _BLOCK_H_
#define _BLOCK_H_

class block{
    public:
        void Create_Block();//随机生成方块

        friend void Change_Block(block b1,block b2);//将下一个方块置入游戏

        //void Start_Block();//游戏开始时的方块建立
        
        block Spin_Block();

        block();

        int Block[4][4];

    private:
        int BLOCK[7][4][4][4];
};

#endif
