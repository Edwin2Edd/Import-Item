#pragma once
#include<stdio.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define easy_game 4

//��ʼ������
void InitBoard(char ground[][COLS], int rows, int cols, char set);
//��ӡ����ͼ
void SurveyBoard(char ground[][COLS], int row, int col);
//������õ���
void SetBoom(char mine[][COLS], int row, int col);
//���ҵ���
void FindBoom(char mine[][COLS], char check[][COLS], int row, int col);