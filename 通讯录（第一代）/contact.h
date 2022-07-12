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



// 用户的结构体
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

// 通讯录的结构体
typedef struct Contact
{
	PeoInfo data[MAX]; // 定义了1000个元素的数组，每个元素包含用户的信息
	int sz; // 通讯录中有效信息的个数
}Contact;

// 初始化通讯录
void InitContact(Contact* pc);

// 1. 增加联系人
void AddContact(Contact* pc);

// 2. 删除联系人
void DeleteContact(Contact* pc);

// 3. 查找联系人
void SearchContact(const Contact* pc);

// 4. 修改联系人
void ModifyContact(Contact* pc);

// 5. 排序联系人
void SortContact(Contact* pc);

// 6. 查看通讯录
void ShowContact(const Contact* pc);
