#pragma once

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 15
#define ADDR_MAX 15
#define DEFAULT_SZ 3

typedef struct PeoInfo
{
	char name[NAME_MAX];//姓名
	int age;//年龄
	char sex[SEX_MAX];//性别
	char tele[TELE_MAX];//电话
	char addr[ADDR_MAX];//地址
}PeoInfo;

typedef struct Contact
{
	PeoInfo * data;
	int sz;
	int capacity;
}Contact;

//初始化结构体内容
void InitContact(Contact* pc);

//添加数据
void AddContact(Contact* pc);

//显示数据
void ShowContact(const Contact* pc);

//删除数据
void DelContact(Contact* pc);

//修改数据
void MoContact(Contact* pc);

//查询数据
void QuContact(Contact* pc);

//排序数据
void SortContact(Contact* pc);

//初始化结构体内容
void ReContact(Contact* pc);

//销毁通讯录
void DestoryContact(Contact* pc);

