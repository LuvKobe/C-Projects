#pragma once
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30



// �û��Ľṹ��
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

// ͨѶ¼�Ľṹ��
typedef struct Contact
{
	PeoInfo data[MAX]; // ������1000��Ԫ�ص����飬ÿ��Ԫ�ذ����û�����Ϣ
	int sz; // ͨѶ¼����Ч��Ϣ�ĸ���
}Contact;

// ��ʼ��ͨѶ¼
void InitContact(Contact* pc);

// 1. ������ϵ��
void AddContact(Contact* pc);

// 2. ɾ����ϵ��
void DeleteContact(Contact* pc);

// 3. ������ϵ��
void SearchContact(const Contact* pc);

// 4. �޸���ϵ��
void ModifyContact(Contact* pc);

// 5. ������ϵ��
void SortContact(Contact* pc);

// 6. �鿴ͨѶ¼
void ShowContact(const Contact* pc);
