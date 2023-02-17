#pragma once
#define MAX 100
#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12
#include<string.h>
#include<stdio.h>
#include<assert.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char tele[TELE_MAX];
}PeoInfo;

typedef struct Contact
{
	PeoInfo data[MAX];
	int sz;
}Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//�����ϵ��
void AddContact(Contact* pc);

//��ʾͨѶ¼�е���Ϣ
void ShowContact(Contact* pc);

//ɾ��ͨѶ¼����Ϣ
void DelContact(const Contact* pc);

//����
void SearchContact(const Contact* pc);

//�޸�
void ModifyContact(const Contact* pc);