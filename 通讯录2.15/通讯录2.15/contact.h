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

//��̬�汾
typedef struct Contact
{
	PeoInfo data[MAX];
	int sz;
	int capacity;//��ǰ�������
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