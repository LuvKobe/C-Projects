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

#define DEFAULT_SZ 4 //设置通讯录的初始化容量为4


//用户结构体
typedef struct PeoInfo
{
	char name[MAX_NAME]; 
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//通讯录结构体
typedef struct Contact
{
	PeoInfo* data; //存放用户的数据
	int sz; //记录通讯录中有效用户的个数
	int capacity; //记录当前通讯录的最大容量（就是能放多少个元素个数）
}Contact;



// 初始化通讯录
void InitContact(Contact* pc);

// 从文件加载数据
void LoadContact(Contact* pc);

// 销毁通讯录
void DestroyContact(Contact* pc);

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

// 保存信息到文件
void SaveContact(Contact* pc);



