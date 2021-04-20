#include "DxLib.h"

//----------------------------
// �萔
//----------------------------
// �u���b�N�̎�ނ̐�
#define BLOCK_TYPE_NUM 7
// �u���b�N�̑傫��
#define BLOCK_SIZE     32
// �u���b�N�̉�]�p�^�[���̐�
#define BLOCK_ROT_NUM  4
// �X�e�[�W�̉���
#define STAGE_WIDTH    10
// �X�e�[�W�̏c��
#define STAGE_HEIGHT   20

// �u���b�N�̃f�[�^
int block[BLOCK_TYPE_NUM][BLOCK_ROT_NUM][4][4] = {
    // �_�^
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
    // L�^
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
    // �tL�^
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
    // Z�^
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
    // �tZ�^
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
    // �ʌ^
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
    // �l�p�^
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

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // �L�[�{�[�h�̉��������i�[���邽�߂̔z��
    char keyState[256];
    // 1�O�̃L�[�{�[�h�̉��������i�[����ׂ̔z��
    char oldKeyState[256];
    // �u���b�N�̉�]�ԍ�
    int blockRot = 0;
    // �u���b�N����]��������SE�p�n���h��
    int seBlockRot;
    // ���삷��u���b�N��X���W
    int blockX = 0;
    // ���삷��u���b�N��Y���W
    int blockY = 0;

    // 1�O�̃L�[�{�[�h�̉��������i�[����ׂ̔z���0�ŏ�����
    for (int i = 0; i < 256; i++) {
        oldKeyState[i] = 0;
    }

    // �E�C���h�E���[�h�ɕύX
    ChangeWindowMode(TRUE);
    
    // �𑜓x�̐ݒ�
    SetGraphMode(1024, 768, 16);

    if (DxLib_Init() == -1)  // �c�w���C�u��������������
    {
        return -1;   // �G���[���N�����璼���ɏI��
    }

    //--------------------------
    // SE�̓ǂݍ���
    //--------------------------
    seBlockRot = LoadSoundMem("se_maoudamashii_system43.ogg");

    //���C�����[�v
    while (ProcessMessage() == 0)
    {
        // ���݂̃L�[�{�[�h�̏�Ԃ����ׂĎ擾
        GetHitKeyStateAll(keyState);

        // Z�{�^���������ꂽ���Ƀu���b�N�̉�]�p�^�[����ς���
        if (keyState[KEY_INPUT_Z] == 1) {
            // Z�{�^�����A�����ĉ�����Ă��Ȃ����m�F
            if (oldKeyState[KEY_INPUT_Z] == 0) {
                blockRot++;
                blockRot = blockRot % BLOCK_ROT_NUM;
                PlaySoundMem(seBlockRot, DX_PLAYTYPE_BACK);
            }
        }
        // �E���L�[�������ꂽ���ɑ��삵�Ă���u���b�N��X���W��ύX����
        if (keyState[KEY_INPUT_RIGHT] == 1) {
            if (oldKeyState[KEY_INPUT_RIGHT] == 0) {
                blockX++;
            }
        }
        // �����L�[�������ꂽ���ɑ��삵�Ă���u���b�N��X���W��ύX����
        if (keyState[KEY_INPUT_LEFT] == 1) {
            if (oldKeyState[KEY_INPUT_LEFT] == 0) {
                blockX--;
            }
        }
        // �����L�[�������ꂽ���ɑ��삵�Ă���u���b�N��Y���W��ύX����
        if (keyState[KEY_INPUT_DOWN] == 1) {
            if (oldKeyState[KEY_INPUT_DOWN] == 0) {
                blockY++;
            }
        }

        //-------------------
        // �`�揈��
        //-------------------
        // ��ʂ�����
        ClearDrawScreen();
        
        // �X�e�[�W��`��
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

        // ���삵�Ă���u���b�N��`��
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


        // ��ʂ�؂�ւ���
        ::ScreenFlip();

        // �L�[�{�[�h�̉�������ۑ�
        for (int i = 0; i < 256; i++) {
            oldKeyState[i] = keyState[i];
        }
    }

    DxLib_End();    // �c�w���C�u�����g�p�̏I������

    return 0;    // �\�t�g�̏I�� 
}