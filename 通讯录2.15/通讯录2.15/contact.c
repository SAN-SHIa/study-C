#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//��̬�汾
//void InitContact(Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}
//��̬�汾
void InitContact(Contact* pc)
{
	pc->sz = 0;
	PeoInfo* ptr=(PeoInfo*)calloc(DEFAULT_SIZE,sizeof(PeoInfo));
	if (ptr == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->data = ptr;
	pc->capacity = DEFAULT_SIZE;
}
void AddContact(Contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("ͨѶ¼����\n");
		return;
	}
	//����һ����
	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������:>");
	scanf("%d", &pc->data[pc->sz].age);
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������סַ:>");
	scanf("%s", pc->data[pc->sz].addr);
	printf("������绰:>");
	scanf("%s", pc->data[pc->sz].tele);
	pc->sz++;
}
void ShowContact(Contact* pc)
{
	int i = 0;
	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "����", " ����", "�Ա�", "��ַ", "�绰");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-4d\t%-5s\t%-20s\t%-12s\n", pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].addr,
			pc->data[i].tele);
	}
}

int FindByName(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void DelContact(Contact* pc)
{
	char name[NAME_MAX];
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	//ɾ��
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	int i = 0;
	//ɾ��
	for (i = ret; i < pc->sz-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
}

void SearchContact(const Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ�����˵����֣�>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (-1 == pos)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "����", " ����", "�Ա�", "��ַ", "�绰");
	printf("%-20s\t%-4d\t%-5s\t%-20s\t%-12s\n", pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].addr,
			pc->data[pos].tele);
}

void ModifyContact(const Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ�޸��˵����֣�>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (-1 == pos)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	printf("����������:>");
	scanf("%s", pc->data[pos].name);
	printf("����������:>");
	scanf("%d", &pc->data[pos].age);
	printf("�������Ա�:>");
	scanf("%s", pc->data[pos].sex);
	printf("������סַ:>");
	scanf("%s", pc->data[pos].addr);
	printf("������绰:>");
	scanf("%s", pc->data[pos].tele);
	printf("�޸����\n");
}