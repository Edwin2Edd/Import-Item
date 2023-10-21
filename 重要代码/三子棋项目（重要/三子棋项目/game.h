#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define ROW 3
#define COL 3

//初始化数组
void InitBoard(char arr[][COL], int row, int col);

//打印数组内容
void PrintBoard(char arr[][COL], int row, int col);

//玩家移动
void PlayerMove(char arr[][COL], int row, int col);

//电脑移动
void ComputerMove(char arr[][COL], int row, int col);

//判断棋盘状况
char IsWin(char arr[][COL], int row, int col);

