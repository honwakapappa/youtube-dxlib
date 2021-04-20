#include "DxLib.h"

//----------------------------
// 定数
//----------------------------
// ブロックの種類の数
#define BLOCK_TYPE_NUM 7
// ブロックの大きさ
#define BLOCK_SIZE     32
// ブロックの回転パターンの数
#define BLOCK_ROT_NUM  4
// ステージの横幅
#define STAGE_WIDTH    10
// ステージの縦幅
#define STAGE_HEIGHT   20

// ブロックのデータ
int block[BLOCK_TYPE_NUM][BLOCK_ROT_NUM][4][4] = {
    // 棒型
    {
        {
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0}
        },
        {
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0}
        }
    },
    // L型
    {
        {
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 1, 1, 1},
            {0, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 1, 1},
            {0, 0, 0, 1},
            {0, 0, 0, 1},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 1},
            {0, 1, 1, 1},
            {0, 0, 0, 0}
        }
    },
    // 逆L型
    {
        {
            {0, 0, 0, 1},
            {0, 0, 0, 1},
            {0, 0, 1, 1},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 1, 1},
            {0, 0, 0, 0}
        },
        {
            {0, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 1, 1, 1},
            {0, 0, 0, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        }
    },
    // Z型
    {
        {
            {0, 0, 0, 0},
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}
        }
    },
    // 逆Z型
    {
        {
            {0, 0, 0, 0},
            {0, 0, 1, 1},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 1, 1},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
        }
    },
    // 凸型
    {
        {
            {0, 0, 0, 0},
            {0, 0, 1, 0},
            {0, 1, 1, 1},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 1},
            {0, 0, 1, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 1, 1, 1},
            {0, 0, 1, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 1, 0}
        }
    },
    // 四角型
    {
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        }
    }
};

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // キーボードの押下情報を格納するための配列
    char keyState[256];
    // 1つ前のキーボードの押下情報を格納する為の配列
    char oldKeyState[256];
    // ブロックの回転番号
    int blockRot = 0;
    // ブロックを回転した時のSE用ハンドル
    int seBlockRot;
    // 操作するブロックのX座標
    int blockX = 0;
    // 操作するブロックのY座標
    int blockY = 0;

    // 1つ前のキーボードの押下情報を格納する為の配列を0で初期化
    for (int i = 0; i < 256; i++) {
        oldKeyState[i] = 0;
    }

    // ウインドウモードに変更
    ChangeWindowMode(TRUE);
    
    // 解像度の設定
    SetGraphMode(1024, 768, 16);

    if (DxLib_Init() == -1)  // ＤＸライブラリ初期化処理
    {
        return -1;   // エラーが起きたら直ちに終了
    }

    //--------------------------
    // SEの読み込み
    //--------------------------
    seBlockRot = LoadSoundMem("se_maoudamashii_system43.ogg");

    //メインループ
    while (ProcessMessage() == 0)
    {
        // 現在のキーボードの状態をすべて取得
        GetHitKeyStateAll(keyState);

        // Zボタンが押された時にブロックの回転パターンを変える
        if (keyState[KEY_INPUT_Z] == 1) {
            // Zボタンが連続して押されていないか確認
            if (oldKeyState[KEY_INPUT_Z] == 0) {
                blockRot++;
                blockRot = blockRot % BLOCK_ROT_NUM;
                PlaySoundMem(seBlockRot, DX_PLAYTYPE_BACK);
            }
        }
        // 右矢印キーが押された時に操作しているブロックのX座標を変更する
        if (keyState[KEY_INPUT_RIGHT] == 1) {
            if (oldKeyState[KEY_INPUT_RIGHT] == 0) {
                blockX++;
            }
        }
        // 左矢印キーが押された時に操作しているブロックのX座標を変更する
        if (keyState[KEY_INPUT_LEFT] == 1) {
            if (oldKeyState[KEY_INPUT_LEFT] == 0) {
                blockX--;
            }
        }
        // 下矢印キーが押された時に操作しているブロックのY座標を変更する
        if (keyState[KEY_INPUT_DOWN] == 1) {
            if (oldKeyState[KEY_INPUT_DOWN] == 0) {
                blockY++;
            }
        }

        //-------------------
        // 描画処理
        //-------------------
        // 画面を消す
        ClearDrawScreen();
        
        // ステージを描画
        for (int height = 0; height < STAGE_HEIGHT; height++) {
            for (int width = 0; width < STAGE_WIDTH; width++) {
                DrawBox(
                    width   * BLOCK_SIZE,
                    height  * BLOCK_SIZE,
                    (width  * BLOCK_SIZE) + BLOCK_SIZE,
                    (height * BLOCK_SIZE) + BLOCK_SIZE,
                    GetColor(255, 255, 255), FALSE);
            }
        }

        // 操作しているブロックを描画
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                if (block[5][blockRot][row][col] == 1) {
                    DrawBox(
                        (blockX * BLOCK_SIZE) + col * BLOCK_SIZE, 
                        (blockY * BLOCK_SIZE) + row * BLOCK_SIZE,
                        (blockX * BLOCK_SIZE) + (col * BLOCK_SIZE) + BLOCK_SIZE,
                        (blockY * BLOCK_SIZE) + (row * BLOCK_SIZE) + BLOCK_SIZE,
                        GetColor(255, 0, 0), TRUE);
                }
            }
        }


        // 画面を切り替える
        ::ScreenFlip();

        // キーボードの押下情報を保存
        for (int i = 0; i < 256; i++) {
            oldKeyState[i] = keyState[i];
        }
    }

    DxLib_End();    // ＤＸライブラリ使用の終了処理

    return 0;    // ソフトの終了 
}