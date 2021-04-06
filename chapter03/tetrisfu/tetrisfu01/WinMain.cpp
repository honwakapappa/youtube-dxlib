#include "DxLib.h"

int block[4][4] = {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0}
};

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //ウインドウモードに変更
    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1)  // ＤＸライブラリ初期化処理
    {
        return -1;   // エラーが起きたら直ちに終了
    }
    int x = 0;
    //メインループ
    while (ProcessMessage() == 0)
    {
        x = x + 1;
        //-------------------
        // 描画処理
        //-------------------
        // 画面を消す
        ClearDrawScreen();

        // 箱を描画
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                if (block[row][col] == 1) {
                    DrawBox(col * 100, row*100, col * 100 + 100, row*100+100, GetColor(255, 0, 0), TRUE);
                }
            }
        }


        // 画面を切り替える
        ScreenFlip();
    }

    DxLib_End();    // ＤＸライブラリ使用の終了処理

    return 0;    // ソフトの終了 
}