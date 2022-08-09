#include"�ҽ�.h"
int tic;
char tic_text[15];

void gotoxy(int x, int y) {
    COORD Pos = { x - 1, y - 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void cursor(int n)
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = n;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void p_sound(int n) {
    switch (n)
    {
    case 1:
        PlaySound(TEXT("C:\\Users\\USER\\Source\\Repos\\����\\bgm\\bgm.wav"), NULL, SND_ASYNC | SND_LOOP);
        break;
    case 2:
        PlaySound(TEXT("C:\\Users\\USER\\Source\\Repos\\����\\bgm\\effect.wav"), NULL, SND_ASYNC | SND_LOOP);
        break;
    default:
        PlaySound(NULL, 0, 0);
        break;
    }
}

void color(int c) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void drawToBackBuffer(const int i, const int j, char* image) {
    int ix = 0;
    while (1) {
        if (image[ix] == '\0') break;

        back_buffer[j][i + ix] = image[ix];

        ix++;
    }
}

void render() {
    for (int i = 0; i < HIGH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (back_buffer[i][j] != front_buffer[i][j]) {
                gotoxy(j, i);

                if (back_buffer[i][j] == '\0')
                    printf("%s", "  ");
                else {
                    if (player_info.x_p == j && player_info.y_p == i)
                        color(6);
                    for (int l = 0; l < fish_num; l++)
                        if (fish_info[l].x_f == j && fish_info[l].y_f == i)
                            color(9);
                    printf("%c", back_buffer[i][j]);
                }
            }
            else if (i == 2 && j == 2) {
                color(7);
                gotoxy(j, i);
                printf("%c%c", back_buffer[i][j], back_buffer[i][j + 1]);
            }
        }
    }
    for (int i = 0; i < HIGH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            front_buffer[i][j] = back_buffer[i][j];
            back_buffer[i][j] = '\0';
        }
    }
}

void cls() {
    for (int i = 0; i < HIGH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            front_buffer[i][j] = '\0';
            back_buffer[i][j] = '\0';
        }
    }
    player_info.x_p = 59;
    player_info.y_p = 23;
    player_info.hp = 5;
    tic = 0;
    fish_num = 0;
    difficulty = 0;
    CLAER = 3;
    for (int i = 0; i < 100; i++)
        strcpy_s(fish_info[i].emage, 10, "*");
    p_sound(0);
}

void fishman() {
    printf("       ����\n");
    printf("     ������             ��\n");
    printf("   ��������          // \\ \n");
    printf("    (| '  .  ' |)         //   \\ \n");
    printf("      ---------          //     \\ \n");
    printf("    / | |   | | \\       //       \\ \n");
    printf("   |  | |---| |  ----- //         \\ \n");
    printf("   |  |       |-------��           \\ \n");
    printf("    ��| |___| |                     \\ \n");
    printf("      |   |   |                      ��\n");
    printf("      |___|___|  \n");
    printf("      [____]___]      \n");

}

void fish_pixel(int x, int y) { // x = 99  y = 103
    //�� ���� ����
    SetPixel(hdc, x * pixel + 3, y * pixely - 3 + 3, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 3, y * pixely - 3 + 4, RGB(0, 100, 200));

    //�� ��
    SetPixel(hdc, x * pixel + 4, y * pixely - 3 + 2, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 5, y * pixely - 3 + 2, RGB(0, 100, 200));

    //�� ������ ����
    SetPixel(hdc, x * pixel + 6, y * pixely - 3 + 3, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 6, y * pixely - 3 + 4, RGB(0, 100, 200));

    //�� �Ʒ�
    SetPixel(hdc, x * pixel + 4, y * pixely - 3 + 5, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 5, y * pixely - 3 + 5, RGB(0, 100, 200));

    //�� ���� �� ä���
    SetPixel(hdc, x * pixel + 4, y * pixely - 3 + 4, RGB(0, 100, 300)); SetPixel(hdc, x * pixel + 4, y * pixely - 3 + 4, RGB(0, 100, 300));
    SetPixel(hdc, x * pixel + 4, y * pixely - 3 + 3, RGB(255, 255, 255)); SetPixel(hdc, x * pixel + 5, y * pixely - 3 + 3, RGB(0, 100, 300));

    //��, �Ӹ�!

    //�� �� �κ�

    SetPixel(hdc, x * pixel + 8, y * pixely - 3 - 2, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 7, y * pixely - 3 - 2, RGB(0, 100, 200));
    SetPixel(hdc, x * pixel + 6, y * pixely - 3 + -1, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 5, y * pixely - 3 + -1, RGB(0, 100, 200));
    SetPixel(hdc, x * pixel + 4, y * pixely - 3, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 3, y * pixely - 3, RGB(0, 100, 200));
    SetPixel(hdc, x * pixel + 2, y * pixely - 3 + 1, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 1, y * pixely - 3 + 1, RGB(0, 100, 200));
    SetPixel(hdc, x * pixel, y * pixely - 3 + 2, RGB(0, 100, 200)); SetPixel(hdc, x * pixel, y * pixely, RGB(0, 100, 200));

    SetPixel(hdc, x * pixel + 1, y * pixely - 3 + 4, RGB(0, 100, 200)); // �� �߰� 

    // �� �Ʒ� �κ�

    SetPixel(hdc, x * pixel, y * pixely - 3 + 5, RGB(0, 100, 200)); SetPixel(hdc, x * pixel, y * pixely - 3 + 6, RGB(0, 100, 200));
    SetPixel(hdc, x * pixel + 1, y * pixely - 3 + 7, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 2, y * pixely - 3 + 7, RGB(0, 100, 200));
    SetPixel(hdc, x * pixel + 3, y * pixely - 3 + 8, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 4, y * pixely - 3 + 8, RGB(0, 100, 200));
    SetPixel(hdc, x * pixel + 5, y * pixely - 3 + 9, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 6, y * pixely - 3 + 9, RGB(0, 100, 200));
    SetPixel(hdc, x * pixel + 7, y * pixely - 3 + 10, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 8, y * pixely - 3 + 10, RGB(0, 100, 200));

    //����!

    //���� �� �κ�

    SetPixel(hdc, x * pixel + 9, y * pixely - 3 + -2, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 10, y * pixely - 3 + -2, RGB(0, 100, 200));
    SetPixel(hdc, x * pixel + 11, y * pixely - 3 + -2, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 12, y * pixely - 3 + -2, RGB(0, 100, 200));
    SetPixel(hdc, x * pixel + 13, y * pixely - 3 + -2, RGB(0, 100, 200));

    //���� �Ʒ� �κ�

    SetPixel(hdc, x * pixel + 9, y * pixely - 3 + 10, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 10, y * pixely - 3 + 10, RGB(0, 100, 200));
    SetPixel(hdc, x * pixel + 11, y * pixely - 3 + 10, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 12, y * pixely - 3 + 10, RGB(0, 100, 200));
    SetPixel(hdc, x * pixel + 13, y * pixely - 3 + 10, RGB(0, 100, 200));

    // ����+����

    // �� �κ�

    SetPixel(hdc, x * pixel + 14, y * pixely - 3 + -1, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 15, y * pixely - 3, RGB(0, 100, 200));
    SetPixel(hdc, x * pixel + 16, y * pixely - 3, RGB(0, 100, 200));

    // �Ʒ� �κ�

    SetPixel(hdc, x * pixel + 14, y * pixely - 3 + 9, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 15, y * pixely - 3 + 8, RGB(0, 100, 200));
    SetPixel(hdc, x * pixel + 16, y * pixely - 3 + 7, RGB(0, 100, 200));

    //����

    //���� �� �κ�

    SetPixel(hdc, x * pixel + 17, y * pixely - 3 + 1, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 18, y * pixely - 3, RGB(0, 100, 200));
    SetPixel(hdc, x * pixel + 19, y * pixely - 3 + -1, RGB(0, 100, 200));

    //���� �Ʒ� �κ�

    SetPixel(hdc, x * pixel + 17, y * pixely - 3 + 7, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 18, y * pixely - 3 + 8, RGB(0, 100, 200));
    SetPixel(hdc, x * pixel + 19, y * pixely - 3 + 9, RGB(0, 100, 200));

    //���� �� �κ�

    SetPixel(hdc, x * pixel + 19, y * pixely - 3 + 0, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 19, y * pixely - 3 + 1, RGB(0, 100, 200));
    SetPixel(hdc, x * pixel + 19, y * pixely - 3 + 2, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 18, y * pixely - 3 + 3, RGB(0, 100, 200));
    SetPixel(hdc, x * pixel + 18, y * pixely - 3 + 4, RGB(0, 100, 200)); SetPixel(hdc, x * pixel + 18, y * pixely - 3 + 5, RGB(0, 100, 200));
    SetPixel(hdc, 18 + x * pixel + 1, y * pixely - 3 + 6, RGB(0, 100, 200)); SetPixel(hdc, 18 + x * pixel + 1, y * pixely - 3 + 7, RGB(0, 100, 200));
    SetPixel(hdc, 18 + x * pixel + 1, y * pixely - 3 + 8, RGB(0, 100, 200));

    //���� ä���

    SetPixel(hdc, 17 + x * pixel + 1, y * pixely - 3 + 1, RGB(0, 0, 230)); SetPixel(hdc, x * pixel + 1 + 17, y * pixely - 3 + 2, RGB(0, 0, 230));
    SetPixel(hdc, x * pixel + 1 + 16, y * pixely - 3 + 3, RGB(0, 0, 230)); SetPixel(hdc, x * pixel + 1 + 16, y * pixely - 3 + 2, RGB(0, 0, 230));
    SetPixel(hdc, x * pixel + 1 + 16, y * pixely - 3 + 4, RGB(0, 0, 230)); SetPixel(hdc, x * pixel + 1 + 16, y * pixely - 3 + 5, RGB(0, 0, 230));
    SetPixel(hdc, x * pixel + 1 + 16, y * pixely - 3 + 6, RGB(0, 0, 230)); SetPixel(hdc, x * pixel + 1 + 17, y * pixely - 3 + 6, RGB(0, 0, 230));
    SetPixel(hdc, x * pixel + 1 + 17, y * pixely - 3 + 7, RGB(0, 0, 230));


    //��

    SetPixel(hdc, x * pixel + 1 + 1, y * pixely - 3 + 3, RGB(0, 20, 255)); SetPixel(hdc, x * pixel + 1, y * pixely - 3 + 3, RGB(0, 20, 255));
    SetPixel(hdc, x * pixel + 1 + 5, y * pixely - 3 + 1, RGB(0, 20, 255)); SetPixel(hdc, x * pixel + 1 + 6, y * pixely - 3 + 1, RGB(0, 20, 255));
    SetPixel(hdc, x * pixel + 1 + 7, y * pixely - 3 + 1, RGB(0, 20, 255)); SetPixel(hdc, x * pixel + 1 + 8, y * pixely - 3 + 1, RGB(0, 20, 255));
    SetPixel(hdc, x * pixel + 1 + 9, y * pixely - 3 + 1, RGB(0, 20, 255)); SetPixel(hdc, x * pixel + 1 + 10, y * pixely - 3 + 1, RGB(0, 20, 255));
    SetPixel(hdc, x * pixel + 1 + 11, y * pixely - 3 + 1, RGB(0, 20, 255)); SetPixel(hdc, x * pixel + 1 + 12, y * pixely - 3 + 1, RGB(0, 20, 255));
    SetPixel(hdc, x * pixel + 1 + 13, y * pixely - 3 + 2, RGB(0, 20, 255)); SetPixel(hdc, x * pixel + 1 + 14, y * pixely - 3 + 3, RGB(0, 20, 255));
    SetPixel(hdc, x * pixel + 1 + 15, y * pixely - 3 + 3, RGB(0, 20, 255)); SetPixel(hdc, x * pixel + 1 + 2, y * pixely - 3 + 2, RGB(0, 20, 255));
    SetPixel(hdc, x * pixel + 1 + 15, y * pixely - 3 + 4, RGB(0, 20, 250));


    // �� ä���
    SetPixel(hdc, x * pixel + 1 + 15, y * pixely - 3 + 2, RGB(0, 70, 255)); SetPixel(hdc, x * pixel + 1 + 15, y * pixely - 3 + 1, RGB(0, 70, 255));
    SetPixel(hdc, x * pixel + 1 + 14, y * pixely - 3 + 1, RGB(0, 70, 255)); SetPixel(hdc, x * pixel + 1 + 14, y * pixely - 3 + 2, RGB(0, 70, 255));
    SetPixel(hdc, x * pixel + 1 + 13, y * pixely - 3 + 1, RGB(0, 70, 255)); SetPixel(hdc, x * pixel + 1 + 13, y * pixely - 3 + 0, RGB(0, 70, 255));
    SetPixel(hdc, x * pixel + 1 + 12, y * pixely - 3 + 0, RGB(0, 70, 255)); SetPixel(hdc, x * pixel + 1 + 12, y * pixely - 3 + -1, RGB(0, 70, 255));
    SetPixel(hdc, x * pixel + 1 + 11, y * pixely - 3 + 0, RGB(0, 70, 255)); SetPixel(hdc, x * pixel + 1 + 11, y * pixely - 3 + -1, RGB(0, 70, 255));
    SetPixel(hdc, x * pixel + 1 + 10, y * pixely - 3 + 0, RGB(0, 70, 255)); SetPixel(hdc, x * pixel + 1 + 10, y * pixely - 3 + -1, RGB(0, 70, 255));
    SetPixel(hdc, x * pixel + 1 + 9, y * pixely - 3, RGB(0, 70, 255)); SetPixel(hdc, x * pixel + 1 + 9, y * pixely - 3 + -1, RGB(0, 70, 255));
    SetPixel(hdc, x * pixel + 1 + 8, y * pixely - 3 + 0, RGB(0, 70, 255)); SetPixel(hdc, x * pixel + 1 + 8, y * pixely - 3 + -1, RGB(0, 70, 255));
    SetPixel(hdc, x * pixel + 1 + 7, y * pixely - 3 + 0, RGB(0, 70, 255)); SetPixel(hdc, x * pixel + 1 + 7, y * pixely - 3 + -1, RGB(0, 70, 255));
    SetPixel(hdc, x * pixel + 1 + 6, y * pixely - 3 + 0, RGB(0, 70, 255)); SetPixel(hdc, x * pixel + 1 + 6, y * pixely - 3 + -1, RGB(0, 70, 255));
    SetPixel(hdc, x * pixel + 1 + 5, y * pixely - 3 + 0, RGB(0, 70, 255)); SetPixel(hdc, x * pixel + 1 + 5, y * pixely - 3 + 1, RGB(0, 70, 255));
    SetPixel(hdc, x * pixel + 1 + 4, y * pixely - 3 + 0, RGB(0, 70, 255)); SetPixel(hdc, x * pixel + 1 + 4, y * pixely - 3 + 1, RGB(0, 70, 255));
    SetPixel(hdc, x * pixel + 1 + 3, y * pixely - 3 + 1, RGB(0, 70, 255)); SetPixel(hdc, x * pixel + 1 + 2, y * pixely - 3 + 1, RGB(0, 70, 255));
    SetPixel(hdc, x * pixel + 1 + 1, y * pixely - 3 + 2, RGB(0, 70, 255)); SetPixel(hdc, x * pixel + 1, y * pixely - 3 + 2, RGB(0, 70, 255));

    //��

    SetPixel(hdc, x * pixel + 1 + 6, y * pixely - 3 + 9, RGB(150, 150, 150)); SetPixel(hdc, x * pixel + 1 + 7, y * pixely - 3 + 9, RGB(150, 150, 150));
    SetPixel(hdc, x * pixel + 1 + 8, y * pixely - 3 + 9, RGB(150, 150, 150)); SetPixel(hdc, x * pixel + 1 + 9, y * pixely - 3 + 9, RGB(150, 150, 150));
    SetPixel(hdc, x * pixel + 1 + 10, y * pixely - 3 + 9, RGB(150, 150, 150)); SetPixel(hdc, x * pixel + 1 + 11, y * pixely - 3 + 9, RGB(150, 150, 150));
    SetPixel(hdc, x * pixel + 1 + 12, y * pixely - 3 + 9, RGB(150, 150, 150));

    SetPixel(hdc, x * pixel + 1 + 4, y * pixely - 3 + 8, RGB(160, 160, 160)); SetPixel(hdc, x * pixel + 1 + 5, y * pixely - 3 + 8, RGB(160, 160, 160));
    SetPixel(hdc, x * pixel + 1 + 6, y * pixely - 3 + 8, RGB(160, 160, 160)); SetPixel(hdc, x * pixel + 1 + 7, y * pixely - 3 + 8, RGB(160, 160, 160));
    SetPixel(hdc, x * pixel + 1 + 8, y * pixely - 3 + 8, RGB(160, 160, 160)); SetPixel(hdc, x * pixel + 1 + 9, y * pixely - 3 + 8, RGB(160, 160, 160));
    SetPixel(hdc, x * pixel + 1 + 10, y * pixely - 3 + 8, RGB(160, 160, 160)); SetPixel(hdc, x * pixel + 1 + 11, y * pixely - 3 + 8, RGB(160, 160, 160));
    SetPixel(hdc, x * pixel + 1 + 12, y * pixely - 3 + 8, RGB(160, 160, 160)); SetPixel(hdc, x * pixel + 1 + 13, y * pixely - 3 + 8, RGB(160, 160, 160));

    SetPixel(hdc, x * pixel + 1 + 2, y * pixely - 3 + 7, RGB(170, 170, 170)); SetPixel(hdc, x * pixel + 1 + 3, y * pixely - 3 + 7, RGB(170, 170, 170));
    SetPixel(hdc, x * pixel + 1 + 4, y * pixely - 3 + 7, RGB(170, 170, 170)); SetPixel(hdc, x * pixel + 1 + 5, y * pixely - 3 + 7, RGB(170, 170, 170));
    SetPixel(hdc, x * pixel + 1 + 6, y * pixely - 3 + 7, RGB(170, 170, 170)); SetPixel(hdc, x * pixel + 1 + 7, y * pixely - 3 + 7, RGB(170, 170, 170));
    SetPixel(hdc, x * pixel + 1 + 8, y * pixely - 3 + 7, RGB(170, 170, 170)); SetPixel(hdc, x * pixel + 1 + 9, y * pixely - 3 + 7, RGB(170, 170, 170));
    SetPixel(hdc, x * pixel + 1 + 10, y * pixely - 3 + 7, RGB(170, 170, 170)); SetPixel(hdc, x * pixel + 1 + 11, y * pixely - 3 + 7, RGB(170, 170, 170));
    SetPixel(hdc, x * pixel + 1 + 12, y * pixely - 3 + 7, RGB(170, 170, 170)); SetPixel(hdc, x * pixel + 1 + 13, y * pixely - 3 + 7, RGB(170, 170, 170));
    SetPixel(hdc, x * pixel + 1 + 14, y * pixely - 3 + 7, RGB(170, 170, 170));

    SetPixel(hdc, x * pixel + 1 + 2, y * pixely - 3 + 7, RGB(180, 180, 180)); SetPixel(hdc, x * pixel + 1 + 3, y * pixely - 3 + 7, RGB(180, 180, 180));
    SetPixel(hdc, x * pixel + 1 + 4, y * pixely - 3 + 7, RGB(180, 180, 180)); SetPixel(hdc, x * pixel + 1 + 5, y * pixely - 3 + 7, RGB(180, 180, 180));
    SetPixel(hdc, x * pixel + 1 + 6, y * pixely - 3 + 7, RGB(180, 180, 180)); SetPixel(hdc, x * pixel + 1 + 7, y * pixely - 3 + 7, RGB(180, 180, 180));
    SetPixel(hdc, x * pixel + 1 + 8, y * pixely - 3 + 7, RGB(180, 180, 180)); SetPixel(hdc, x * pixel + 1 + 9, y * pixely - 3 + 7, RGB(180, 180, 180));
    SetPixel(hdc, x * pixel + 1 + 10, y * pixely - 3 + 7, RGB(180, 180, 180)); SetPixel(hdc, x * pixel + 1 + 11, y * pixely - 3 + 7, RGB(180, 180, 180));
    SetPixel(hdc, x * pixel + 1 + 12, y * pixely - 3 + 7, RGB(180, 180, 180)); SetPixel(hdc, x * pixel + 1 + 13, y * pixely - 3 + 7, RGB(180, 180, 180));
    SetPixel(hdc, x * pixel + 1 + 14, y * pixely - 3 + 7, RGB(180, 180, 180));

    SetPixel(hdc, x * pixel + 1, y * pixely - 3 + 6, RGB(190, 190, 190)); SetPixel(hdc, x * pixel + 1 + 1, y * pixely - 3 + 6, RGB(190, 190, 190));
    SetPixel(hdc, x * pixel + 1 + 2, y * pixely - 3 + 6, RGB(190, 190, 190)); SetPixel(hdc, x * pixel + 1 + 3, y * pixely - 3 + 6, RGB(190, 190, 190));
    SetPixel(hdc, x * pixel + 1 + 4, y * pixely - 3 + 6, RGB(190, 190, 190)); SetPixel(hdc, x * pixel + 1 + 5, y * pixely - 3 + 6, RGB(190, 190, 190));
    SetPixel(hdc, x * pixel + 1 + 6, y * pixely - 3 + 6, RGB(190, 190, 190)); SetPixel(hdc, x * pixel + 1 + 7, y * pixely - 3 + 6, RGB(190, 190, 190));
    SetPixel(hdc, x * pixel + 1 + 8, y * pixely - 3 + 6, RGB(190, 190, 190)); SetPixel(hdc, x * pixel + 1 + 9, y * pixely - 3 + 6, RGB(190, 190, 190));
    SetPixel(hdc, x * pixel + 1 + 10, y * pixely - 3 + 6, RGB(190, 190, 190)); SetPixel(hdc, x * pixel + 1 + 11, y * pixely - 3 + 6, RGB(190, 190, 190));
    SetPixel(hdc, x * pixel + 1 + 12, y * pixely - 3 + 6, RGB(190, 190, 190)); SetPixel(hdc, x * pixel + 1 + 13, y * pixely - 3 + 6, RGB(190, 190, 190));
    SetPixel(hdc, x * pixel + 1 + 14, y * pixely - 3 + 6, RGB(190, 190, 190)); SetPixel(hdc, x * pixel + 1 + 15, y * pixely - 3 + 6, RGB(190, 190, 190));

    SetPixel(hdc, x * pixel + 1, y * pixely - 3 + 5, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 1, y * pixely - 3 + 5, RGB(200, 200, 200));
    SetPixel(hdc, x * pixel + 1 + 2, y * pixely - 3 + 5, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 5, y * pixely - 3 + 5, RGB(200, 200, 200));
    SetPixel(hdc, x * pixel + 1 + 6, y * pixely - 3 + 5, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 7, y * pixely - 3 + 5, RGB(200, 200, 200));
    SetPixel(hdc, x * pixel + 1 + 8, y * pixely - 3 + 5, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 9, y * pixely - 3 + 5, RGB(200, 200, 200));
    SetPixel(hdc, x * pixel + 1 + 10, y * pixely - 3 + 5, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 11, y * pixely - 3 + 5, RGB(200, 200, 200));
    SetPixel(hdc, x * pixel + 1 + 12, y * pixely - 3 + 5, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 13, y * pixely - 3 + 5, RGB(200, 200, 200));
    SetPixel(hdc, x * pixel + 1 + 14, y * pixely - 3 + 5, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 15, y * pixely - 3 + 5, RGB(200, 200, 200));

    SetPixel(hdc, x * pixel + 1 + 1, y * pixely - 3 + 4, RGB(200, 200, 200));
    SetPixel(hdc, x * pixel + 1 + 6, y * pixely - 3 + 4, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 7, y * pixely - 3 + 4, RGB(200, 200, 200));
    SetPixel(hdc, x * pixel + 1 + 8, y * pixely - 3 + 4, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 9, y * pixely - 3 + 4, RGB(200, 200, 200));
    SetPixel(hdc, x * pixel + 1 + 10, y * pixely - 3 + 4, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 11, y * pixely - 3 + 4, RGB(200, 200, 200));
    SetPixel(hdc, x * pixel + 1 + 12, y * pixely - 3 + 4, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 13, y * pixely - 3 + 4, RGB(200, 200, 200));
    SetPixel(hdc, x * pixel + 1 + 14, y * pixely - 3 + 4, RGB(200, 200, 200));

    SetPixel(hdc, x * pixel + 1 + 6, y * pixely - 3 + 3, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 7, y * pixely - 3 + 3, RGB(200, 200, 200));
    SetPixel(hdc, x * pixel + 1 + 8, y * pixely - 3 + 3, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 9, y * pixely - 3 + 3, RGB(200, 200, 200));
    SetPixel(hdc, x * pixel + 1 + 10, y * pixely - 3 + 3, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 11, y * pixely - 3 + 3, RGB(200, 200, 200));
    SetPixel(hdc, x * pixel + 1 + 12, y * pixely - 3 + 3, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 13, y * pixely - 3 + 3, RGB(200, 200, 200));

    SetPixel(hdc, x * pixel + 1 + 5, y * pixely - 3 + 2, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 6, y * pixely - 3 + 2, RGB(200, 200, 200));
    SetPixel(hdc, x * pixel + 1 + 7, y * pixely - 3 + 2, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 8, y * pixely - 3 + 2, RGB(200, 200, 200));
    SetPixel(hdc, x * pixel + 1 + 9, y * pixely - 3 + 2, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 10, y * pixely - 3 + 2, RGB(200, 200, 200));
    SetPixel(hdc, x * pixel + 1 + 11, y * pixely - 3 + 2, RGB(200, 200, 200)); SetPixel(hdc, x * pixel + 1 + 12, y * pixely - 3 + 2, RGB(200, 200, 200));

}

void cls_fish();

void c_n_fish();

void p_fish();

void game_start_move() {
    if (GetAsyncKeyState(0x57) && 0x8000) { //��
        gotoxy(110, player_info.y_p);
        printf(" ");
        if (player_info.y_p == 23) player_info.y_p = 20;
        else player_info.y_p = 17;
        Sleep(150);
    }
    if (GetAsyncKeyState(0x53) && 0x8000) { //�Ʒ�
        gotoxy(110, player_info.y_p);
        printf(" ");
        if (player_info.y_p == 17) player_info.y_p = 20;
        else player_info.y_p = 23;
        Sleep(150);
    }
    if (GetAsyncKeyState(0x41) && 0x8000) { //��
        if (player_info.y_p == 17) difficulty = 0;
        Sleep(150);
    }
    if (GetAsyncKeyState(0x44) && 0x8000) { //��
        if (player_info.y_p == 17) difficulty = 1;
        Sleep(150);
    }
}

void game_start_printing() {
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
}

int game_strat() {
    player_info.y_p = 17;
    color(7);
    game_start_printing();
    gotoxy(94, 5);
    printf("ź�� ���ϱ�");
    gotoxy(91, 17);
    gotoxy(95, 20);
    printf("���� ����");
    gotoxy(95, 23);
    printf("���� ����");
    while (1) {
        gotoxy(90, 17);
        if (!difficulty)
            printf("�� ���� ���� ���� ��");
        else
            printf("�� �ϵ� ���� ���� ��");
        gotoxy(110, player_info.y_p);
        printf("<");
        game_start_move();
        if (GetAsyncKeyState(VK_RETURN)) {
            system("cls");
            Sleep(1);
            if (player_info.y_p == 17) return 1;
            else if (player_info.y_p == 20) return 2;
            else return 0;
        }
    }
}

void game_over() {
    system("cls");
    p_sound(2);
    while (1) {
        if (GetAsyncKeyState(VK_RETURN)) {
            go = 1;
            Sleep(300);
            return;
        }
        gotoxy(54, 8);
        printf(" GAME OVER");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 16);
        gotoxy(rand() % 119 + 1, rand() % 59 + 1);
        printf("��");
        Sleep(10);
    }
}

void game_clere() {
    system("cls");
    color(7);
    p_sound(1);
    gotoxy(54, 8);
    printf("GAME CLERE");
    gotoxy(1, 20);
    fishman();
    for (int i = 0; i < 30;i++) {
        fish_pixel(rand() % 50 + 70, rand() % 21 + 14);
    }
    while (1)
    {
        if (GetAsyncKeyState(VK_RETURN)) {
            gc = 1;
            return;
        }
    }
}

void hp_print() {
    gotoxy(2, 39);
    for (int i = 0; i < player_info.hp; i++) {
        color(4);
        printf("��");
    }
    if (player_info.hp <= 0) {
        game_over();
        Sleep(1);
        return;
    }
}

void move() {
    if (GetAsyncKeyState(0x41)) { //����
        player_info.x_p -=2;
    }
    if (GetAsyncKeyState(0x44)) { //������
        player_info.x_p +=2;
    }
    if (GetAsyncKeyState(0x57)) { //��
        player_info.y_p--;
    }
    if (GetAsyncKeyState(0x53)) { //�Ʒ�
        player_info.y_p++;
    }
    if (player_info.x_p >= 119) player_info.x_p = 118;
    if (player_info.x_p < 1) player_info.x_p = 1;
    if (player_info.y_p > 39) player_info.y_p = 39;
    if (player_info.y_p < 1) player_info.y_p = 1;
    drawToBackBuffer(player_info.x_p, player_info.y_p, "��");
    Sleep(1);
}

void game_play() {
    int game = 0;
GAME:
    cls();
    system("cls");
    game = game_strat();
    if (difficulty) {
        CLAER = 40;
    }
    Sleep(300);
    if (game == 1) {
        while (1) {
            tic++;
            Sleep(60);
            hp_print();
            if (go) {
                go = 0;
                goto GAME;
            }
            if (gc) {
                gc = 0;
                goto GAME;
            }
            cls_fish();
            p_fish();
            if (tic % 50 == 1) c_n_fish();
            move();
            sprintf_s(tic_text, 15, "%d", tic / 10);
            drawToBackBuffer(2, 2, tic_text);
            render();
            if (GetAsyncKeyState(VK_RETURN)) {
                Sleep(300);
                goto GAME;
            }
        }
    }
    if (game == 2) {
        printf("<���� ����>\n\n");
        printf("\t�� ������ ����⸦ �ʹ� ���� ����(��� ���ΰ� �޸�) ��ΰ�\n");
        printf("\t�������� ������ ��ġ��� ���� ��Ƴ��� �����Դϴ�.\n");
        printf("\n\t���� ��� : \n");
        printf("\tW: ��\n\tA: ������\n\tS: �Ʒ�\n\tD: ����\n\tENTER: ���� ����, ����, �Ϸ�\n\n\n");
        fishman();
        Sleep(300);
        while (1) {
            if (GetAsyncKeyState(VK_RETURN)) {
                Sleep(300);
                goto GAME;
            }
        }
    }
}

int main() {
    hwnd = GetForegroundWindow();
    hdc = GetWindowDC(hwnd);
    system("mode con cols=120 lines=40");
    cursor(0);
    srand((unsigned int)time(NULL));
    game_play();
    return 0;
}