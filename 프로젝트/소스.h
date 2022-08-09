#pragma once
#include<stdio.h>
#include<string.h>
#include<winsock.h>
#include<windows.h>
#include<process.h>
#include<stdlib.h>
#include<time.h>
#include <sys/types.h>
#include<mmsystem.h>
#define HIGH 40
#define WIDTH 120
#define pixel 10
#define pixely 25
#pragma comment(lib,"winmm.lib")

char front_buffer[HIGH][WIDTH];
char back_buffer[HIGH][WIDTH];

HWND hwnd;
HDC hdc;
CRITICAL_SECTION cs;

typedef struct player {
    int x_p;
    int y_p;
    int hp;
}PLAYER;

PLAYER player_info;

typedef struct fish {
    int x_f;
    int y_f;
    int drection;
    char emage[10];
}FISH;

FISH fish_info[100];
int fish_num;
int gc;
int go;
int difficulty;
int CLAER;