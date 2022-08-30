#pragma once
#pragma warning(disable:4996)

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#define DEFAULT_SZ 4 //����ͨѶ¼�ĳ�ʼ������Ϊ4


//�û��ṹ��
typedef struct PeoInfo
{
	char name[MAX_NAME]; 
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//ͨѶ¼�ṹ��
typedef struct Contact
{
	PeoInfo* data; //����û�������
	int sz; //��¼ͨѶ¼����Ч�û��ĸ���
	int capacity; //��¼��ǰͨѶ¼����������������ܷŶ��ٸ�Ԫ�ظ�����
}Contact;



// ��ʼ��ͨѶ¼
void InitContact(Contact* pc);

// ���ļ���������
void LoadContact(Contact* pc);

// ����ͨѶ¼
void DestroyContact(Contact* pc);

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

// ������Ϣ���ļ�
void SaveContact(Contact* pc);



