class game{
    public:
    bool Ifmove();//判断是否可以移动，包括边框与其他方块，但不包括底部

    bool Botton();//判断是否到达底部，以及为到达底部的方块固定。

    bool Getscore();//检测是否满行，以及满行后进行的消除行、加分和为另一玩家加行

    bool Faile();//判断失败条件

};