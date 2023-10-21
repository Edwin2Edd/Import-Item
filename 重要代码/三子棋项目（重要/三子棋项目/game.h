#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define ROW 3
#define COL 3

//��ʼ������
void InitBoard(char arr[][COL], int row, int col);

//��ӡ��������
void PrintBoard(char arr[][COL], int row, int col);

//����ƶ�
void PlayerMove(char arr[][COL], int row, int col);

//�����ƶ�
void ComputerMove(char arr[][COL], int row, int col);

//�ж�����״��
char IsWin(char arr[][COL], int row, int col);

