#include "DxLib.h"

int block[7][4][4][4] = {
    // _^
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
    // L^
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
    // tL^
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
    // Z^
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
    // tZ^
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
    // Ê^
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
    // lp^
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

// vOÍ WinMain ©çnÜèÜ·
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // L[{[hÌºîñði[·é½ßÌzñ
    char keyState[256];
    // 1ÂOÌL[{[hÌºîñði[·é×Ìzñ
    char oldKeyState[256];
    // ubNÌñ]Ô
    int blockRot = 0;
    // ubNðñ]µ½ÌSEpnh
    int seBlockRot;

    // 1ÂOÌL[{[hÌºîñði[·é×Ìzñð0Åú»
    for (int i = 0; i < 256; i++) {
        oldKeyState[i] = 0;
    }

    //EChE[hÉÏX
    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1)  // cwCuú»
    {
        return -1;   // G[ªN«½ç¼¿ÉI¹
    }

    //--------------------------
    // SEÌÇÝÝ
    //--------------------------
    seBlockRot = LoadSoundMem("se_maoudamashii_system43.ogg");

    //C[v
    while (ProcessMessage() == 0)
    {
        // »ÝÌL[{[hÌóÔð·×Äæ¾
        GetHitKeyStateAll(keyState);

        // Z{^ª³ê½ÉubNÌñ]p^[ðÏ¦é
        if (keyState[KEY_INPUT_Z] == 1) {
            // Z{^ªA±µÄ³êÄ¢È¢©mF
            if (oldKeyState[KEY_INPUT_Z] == 0) {
                blockRot++;
                blockRot = blockRot % 4;
                PlaySoundMem(seBlockRot, DX_PLAYTYPE_BACK);
            }
        }

        //-------------------
        // `æ
        //-------------------
        // æÊðÁ·
        ClearDrawScreen();

        //  ð`æ
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                if (block[5][blockRot][row][col] == 1) {
                    DrawBox(col * 100, row*100, col * 100 + 100, row*100+100, GetColor(255, 0, 0), TRUE);
                }
            }
        }


        // æÊðØèÖ¦é
        ::ScreenFlip();

        // L[{[hÌºîñðÛ¶
        for (int i = 0; i < 256; i++) {
            oldKeyState[i] = keyState[i];
        }
    }

    DxLib_End();    // cwCugpÌI¹

    return 0;    // \tgÌI¹ 
}