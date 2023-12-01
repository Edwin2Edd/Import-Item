#pragma once
#include<stdio.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define easy_game 4

//初始化地雷
void InitBoard(char ground[][COLS], int rows, int cols, char set);
//打印地雷图
void SurveyBoard(char ground[][COLS], int row, int col);
//随机放置地雷
void SetBoom(char mine[][COLS], int row, int col);
//查找地雷
void FindBoom(char mine[][COLS], char check[][COLS], int row, int col);