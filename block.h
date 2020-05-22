class block{
    public:
        void Create_Block();//随机生成方块

        void Change_Block();//将下一个方块置入游戏

        void Start_Block();//游戏开始时的方块建立

        block();

        int BlockNow[4][4];

        int BlockNext[4][4];

    private:
        int Block_1[4][4][4];//"O形"

        int Block_2[4][4][4];//"I形1"

        int Block_3[4][4][4];//"L形1"

        int Block_4[4][4][4];//"J形1"

        int Block_5[4][4][4];//"T形1"

        int Block_6[4][4][4];//"Z形1"

        int Block_7[4][4][4];//"S形1"
};