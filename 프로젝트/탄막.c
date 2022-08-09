#include"¼Ò½º.h"

void gotoxy(int x, int y);

void game_clere();

void drawToBackBuffer(const int i, const int j, char* image);

void c_n_fish() {
    int s_p = 0;
    s_p = rand() % 4;
    if (difficulty) {
        switch (s_p) {
        case 0:
            fish_info[fish_num].x_f = rand() % 114;
            fish_info[fish_num].y_f = 0;
            fish_info[fish_num].drection = rand() % 3 + 4;
            break;
        case 1:
            fish_info[fish_num].x_f = rand() % 114;
            fish_info[fish_num].y_f = 39;
            fish_info[fish_num].drection = (7 + rand() % 3) % 8 + 1;
            break;
        case 2:
            fish_info[fish_num].x_f = 0;
            fish_info[fish_num].y_f = rand() % 40;
            fish_info[fish_num].drection = rand() % 3 + 2;
            break;
        case 3:
            fish_info[fish_num].x_f = 113;
            fish_info[fish_num].y_f = rand() % 40;
            fish_info[fish_num].drection = rand() % 3 + 6;
            break;
        }
    }
    else {
        switch (s_p) {
        case 0:
            fish_info[fish_num].x_f = rand() % 120;
            fish_info[fish_num].y_f = 0;
            fish_info[fish_num].drection = rand() % 3 + 4;
            break;
        case 1:
            fish_info[fish_num].x_f = rand() % 120;
            fish_info[fish_num].y_f = 39;
            fish_info[fish_num].drection = (7 + rand() % 3) % 8 + 1;
            break;
        case 2:
            fish_info[fish_num].x_f = 0;
            fish_info[fish_num].y_f = rand() % 40;
            fish_info[fish_num].drection = rand() % 3 + 2;
            break;
        case 3:
            fish_info[fish_num].x_f = 119;
            fish_info[fish_num].y_f = rand() % 40;
            fish_info[fish_num].drection = rand() % 3 + 6;
            break;
        }
    }
    fish_num++;
    if (fish_num > CLAER) game_clere();
}

void m_fish(int* px, int* py, int d, int i) {
    switch (d) {
    case 1:
        *py -= 1;
        if(difficulty)
            strcpy_s(fish_info[i].emage, 10, "¢¸¢º¢¸");
        break;
    case 2:
        *py -= 1;
        *px += 1;
        if (difficulty)
            strcpy_s(fish_info[i].emage, 10, "¢º¢¸¢º");
        break;
    case 3:
        *px += 1;
        if (difficulty)
            strcpy_s(fish_info[i].emage, 10, "¢º¢¸¢º");
        break;
    case 4:
        *px += 1;
        *py += 1;
        if (difficulty)
            strcpy_s(fish_info[i].emage, 10, "¢º¢¸¢º");
        break;
    case 5:
        *py += 1;
        if (difficulty)
            strcpy_s(fish_info[i].emage, 10, "¢¸¢º¢¸");
        break;
    case 6:
        *py += 1;
        *px -= 1;
        if (difficulty)
            strcpy_s(fish_info[i].emage, 10, "¢¸¢º¢¸");
        break;
    case 7:
        *px -= 1;
        if (difficulty)
            strcpy_s(fish_info[i].emage, 10, "¢¸¢º¢¸");
        break;
    case 8:
        *px -= 1;
        *py -= 1;
        if (difficulty)
            strcpy_s(fish_info[i].emage, 10, "¢¸¢º¢¸");
        break;

    }
}

void cls_fish() {
    for (int i = 0; i < fish_num; i++) {
        drawToBackBuffer(fish_info[i].x_f, fish_info[i].y_f, "\0");
    }
}

void cut_fish(int i) {
    drawToBackBuffer(fish_info[i].x_f, fish_info[i].y_f, "\0");
}

void fish_cpy(int x, int y) {
    fish_info[x].x_f = fish_info[y].x_f;
    fish_info[x].y_f = fish_info[y].y_f;
    fish_info[x].drection = fish_info[y].drection;
}

void k_fish(int n) {
    for (int i = n; i < fish_num; i++) {
        fish_cpy(i, i + 1);
        cut_fish(i);
    }
    fish_num--;
}

void p_fish() {
    int i, new_fish = 0;
    for (i = 0; i < fish_num; i++) {
        m_fish(&fish_info[i].x_f, &fish_info[i].y_f, fish_info[i].drection, i);
        if (difficulty) {
            if (fish_info[i].x_f < 0 || fish_info[i].x_f>113) {
                k_fish(i);
                i--;
                new_fish++;
            }
            else if (fish_info[i].y_f < 0 || fish_info[i].y_f > 39) {
                k_fish(i);
                i--;
                new_fish++;
            }
            else if ((fish_info[i].x_f >= player_info.x_p - 7 && fish_info[i].x_f <= player_info.x_p + 1) && fish_info[i].y_f == player_info.y_p) {
                player_info.hp--;
                system("cls");
                k_fish(i);
                i--;
                new_fish++;
                Sleep(50);
            }
        }
        else {
            if (fish_info[i].x_f < 0 || fish_info[i].x_f>119) {
                k_fish(i);
                i--;
                new_fish++;
            }
            else if (fish_info[i].y_f < 0 || fish_info[i].y_f > 39) {
                k_fish(i);
                i--;
                new_fish++;
            }
            else if ((fish_info[i].x_f >= player_info.x_p - 1 && fish_info[i].x_f <= player_info.x_p + 2) && fish_info[i].y_f == player_info.y_p) {
                player_info.hp--;
                system("cls");
                k_fish(i);
                i--;
                new_fish++;
                Sleep(50);
            }
        }
    }
    for (i = 0; i < new_fish; i++) c_n_fish();
    for (i = 0; i < fish_num; i++) {
        drawToBackBuffer(fish_info[i].x_f, fish_info[i].y_f, fish_info[i].emage);
    }
}