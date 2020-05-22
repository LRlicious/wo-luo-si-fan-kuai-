class player{
    public:
        void Up();//玩家1变换方块形状

        void Down();//玩家1方块向下移动

        void Right();//玩家1方块向右移动

        void Left();//玩家1方块向左移动

        void W();//玩家2变换方块形状

        void S();//玩家2方块向下移动

        void D();//玩家2方块向右移动

        void A();//玩家2方块向左移动

        void Cin_1_Block();//若此时操作的方块为空，将下一个的方块进入游戏

        void Cin_2_Block();//若此时操作的方块为空，将下一个的方块进入游戏

        void Auto_1_Block();//玩家1方块自行下落

        void Auto_1_Block();//玩家2方块自行下落
    private:
        int Player1_Score;

        int Player2_Score;


};