#pragma once

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>


#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 15
#define ADDR_MAX 15
#define DATA_MAX 100

typedef struct PeoInfo
{
	char name[NAME_MAX];//����
	int age;//����
	char sex[SEX_MAX];//�Ա�
	char tele[TELE_MAX];//�绰
	char addr[ADDR_MAX];//��ַ
}PeoInfo;

typedef struct Contact
{
	PeoInfo data[DATA_MAX];
	int sz;
}Contact;

//��ʼ���ṹ������
void InitContact(Contact *pc);

//�������
void AddContact(Contact* pc);

//��ʾ����
void ShowContact(const Contact* pc);

//ɾ������
void DelContact(Contact* pc);

//�޸�����
void MoContact(Contact* pc);

//��ѯ����
void QuContact(Contact* pc);

//��������
void SortContact(Contact* pc);

