#pragma once
#define MAX 100
#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12
#include<string.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define DEFAULT_SIZE 3
#define INC_SIZE 2

typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char tele[TELE_MAX];
}PeoInfo;

//动态版本
typedef struct Contact
{
	PeoInfo data[MAX];
	int sz;
	int capacity;//当前最大容量
}Contact;

//初始化通讯录
void InitContact(Contact* pc);

//添加联系人
void AddContact(Contact* pc);

//显示通讯录中的信息
void ShowContact(Contact* pc);

//删除通讯录中信息
void DelContact(const Contact* pc);

//查找
void SearchContact(const Contact* pc);

//修改
void ModifyContact(const Contact* pc);