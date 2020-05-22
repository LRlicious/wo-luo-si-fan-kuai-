class game{
    public:
    void Ifmove();//判断是否可以移动，包括边框与其他方块，但不包括底部

    void Botton();//判断是否到达底部，以及为到达底部的方块固定。

    int Getscore();//检测是否满行，以及满行后进行的消除行、加分和为另一玩家加行

    void Faile();//判断失败条件

};