#include "DxLib.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //ウインドウモードに変更
    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1)  // ＤＸライブラリ初期化処理
    {
        return -1;   // エラーが起きたら直ちに終了
    }

    
    DrawCircle(110, 205, 50, GetColor(0, 255, 0));
    DrawCircle(530, 175, 50, GetColor(0, 0, 255));
    DrawLine(50, 260, 590, 220, GetColor(255, 0, 0));
    DrawTriangle(320, 240, 270, 290, 370, 290, GetColor(255, 0, 255), TRUE);
    DrawBox(270, 290, 370, 350, GetColor(255, 255, 0), TRUE);

    //アンチエイリアス版
    //DrawCircleAA(110, 205, 50, 40, GetColor(0, 255, 0));
    //DrawCircleAA(530, 175, 50, 40, GetColor(0, 0, 255));
    //DrawLineAA(50, 260, 590, 220, GetColor(255, 0, 0));
    //DrawTriangleAA(320, 240, 270, 290, 370, 290, GetColor(255, 0, 255), TRUE);
    //DrawBoxAA(270, 290, 370, 350, GetColor(255, 255, 0), TRUE);

    WaitKey();    // キー入力待ち

    DxLib_End();    // ＤＸライブラリ使用の終了処理

    return 0;    // ソフトの終了 
}