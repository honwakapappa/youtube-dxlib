#include "DxLib.h"

int block[4][4] = {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0}
};

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //�E�C���h�E���[�h�ɕύX
    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1)  // �c�w���C�u��������������
    {
        return -1;   // �G���[���N�����璼���ɏI��
    }
    int x = 0;
    //���C�����[�v
    while (ProcessMessage() == 0)
    {
        x = x + 1;
        //-------------------
        // �`�揈��
        //-------------------
        // ��ʂ�����
        ClearDrawScreen();

        // ����`��
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                if (block[row][col] == 1) {
                    DrawBox(col * 100, row*100, col * 100 + 100, row*100+100, GetColor(255, 0, 0), TRUE);
                }
            }
        }


        // ��ʂ�؂�ւ���
        ScreenFlip();
    }

    DxLib_End();    // �c�w���C�u�����g�p�̏I������

    return 0;    // �\�t�g�̏I�� 
}