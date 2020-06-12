#include "block.h"
class player{
    public:
        int X;
        int Y;
        void Up();//玩家1变换方块形状

        bool Down();//玩家1方块向下移动

        void Right();//玩家1方块向右移动

        void Left();//玩家1方块向左移动

/*        void W();//玩家2变换方块形状

        void S();//玩家2方块向下移动

        void D();//玩家2方块向右移动

        void A();//玩家2方块向左移动
*/
        void Cin_1_Block();//若此时操作的方块为空，将下一个的方块进入游戏            好像也用不上

//        void Cin_2_Block();//若此时操作的方块为空，将下一个的方块进入游戏

        void Auto_1_Block();//玩家1方块自行下落                                     好像用不上

//        void Auto_1_Block();//玩家2方块自行下落

        bool Ifmove(block bl, int x, int y);//碰撞检测

        bool Botton();//判断是否到达底部，以及为到达底部的方块固定。                好像还是用不上

        int Getscore();//检测是否满行，以及满行后进行的消除行、加分 此功能将在到达底部后执行 放在down里执行还是放在

        void Addline(int t);//加行

        bool Faile();//判断失败条件


        //这里还能进一步修改

        int Player1_map[25][10];    //玩家1的游戏状况       前5行经作为越界判定胜负使用，

//        int Player2_map[20][10];    //玩家2的游戏状况

        player();

        bool win;

    private:
        int Player1_Score;

//        int Player2_Score;

        block Player1_Block_NOW;

//        block Player2_Block_NOW;

        block Player1_Block_next;

//        block Player2_Block_next;
        
        //判断胜负
};