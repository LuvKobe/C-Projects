#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"

// ���ݺ���
void CheckCapacity(Contact* pc) {
	assert(pc);

	if (pc->sz == pc->capacity) {
		PeoInfo* tmp = (PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(PeoInfo));
		if (tmp != NULL) {
			pc->data = tmp;
			// ���ݳɹ��Ժ�capacityҪ��
			pc->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else {
			printf("AddContact()::%s\n", strerror(errno));
		}
	}
}

// ��ȡ��һ��ͨѶ¼�е���Ϣ
void LoadContact(Contact* pc) {
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL) {
		printf("InitContact:: open for reading : %s\n", strerror(errno));
		return;
	}

	//���ļ�
	PeoInfo buf = { 0 };
	while (fread(&buf, sizeof(PeoInfo), 1, pf)) {
		CheckCapacity(pc);
		pc->data[pc->sz] = buf;
		pc->sz++;
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}


// ��ʼ��ͨѶ¼
void InitContact(Contact* pc) {
	assert(pc);
	pc->sz = 0;
	PeoInfo* tmp = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo)); //���4���˵���Ϣ
	if (tmp != NULL) {
		pc->data = tmp;
	}
	else {
		printf("InitContact()::%s\n", strerror(errno));
		return;
	}

	// ��Ĭ�ϵ�������ֵ��capacity
	pc->capacity = DEFAULT_SZ;

	//��ȡ��һ���˳�ʱ�������ͨѶ¼�е���Ϣ
	LoadContact(pc);
}

// 1. ������ϵ��
void AddContact(Contact* pc) {
	assert(pc);

	//������ϵ��֮ǰ���ж�ͨѶ¼�Ƿ������
	CheckCapacity(pc);

	//������ϵ��
	printf("����������:> ");
	scanf("%s", pc->data[pc->sz].name); //name�����������������ﲻ��Ҫȡ��ַ

	printf("����������:> ");
	scanf("%d", &pc->data[pc->sz].age);

	printf("�������Ա�(��orŮor����):> ");
	scanf("%s", pc->data[pc->sz].sex);

	printf("������绰(���ܳ���12λ��):> ");
	scanf("%s", pc->data[pc->sz].tele);

	printf("�������ַ(���ܳ���30���ַ�):> ");
	scanf("%s", pc->data[pc->sz].addr);

	// sz����data���������û��ĸ��������Ե������һ���˵���Ϣ�Ժ�sz�ͼ�1��ָ����һ��λ��
	pc->sz++;
	printf("������ϵ�˳ɹ�\n");
}


int FindByName(const Contact* pc, char name[]) {
	for (int j = 0; j < pc->sz; ++j) {
		if (0 == strcmp(pc->data[j].name, name)) {
			return j; //�ҵ���
		}
	}
	return -1; //û�ҵ�
}

// 2. ɾ����ϵ��
void DeleteContact(Contact* pc) {
	assert(pc);

	char name[MAX_NAME] = { 0 };
	if (0 == pc->sz) {
		printf("ͨѶ¼Ϊ��,ɾ��ʧ��\n");
		return;
	}
	printf("������Ҫɾ����ϵ�˵�����:> ");
	scanf("%s", name);

	//������ϵ��
	int pos = FindByName(pc, name);
	if (-1 == pos) {
		printf("���޴���\n");
	}
	else {
		for (int i = pos; i < (pc->sz) - 1; ++i) {
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("ɾ����ϵ�˳ɹ�\n");
	}

}

// 3. ������ϵ��
void SearchContact(const Contact* pc) {
	assert(pc);

	char name[MAX_NAME] = { 0 };
	printf("������Ҫ���ҵ���ϵ������:> ");
	scanf("%s", &name);
	int pos = FindByName(pc, name);

	if (-1 == pos) {
		printf("���޴���\n");
		return;
	}
	else {
		printf("���ҳɹ�\n");
		printf("%-4s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("%-4s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr
		);
	}
}

// 4. �޸���ϵ��
void ModifyContact(Contact* pc) {
	assert(pc);

	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸ĵ���ϵ������:> ");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (-1 == pos) {
		printf("���޴���\n");
	}
	else {
		printf("������Ҫ�޸������ϵ�˵�ʲô��Ϣ��\n");
		printf("1.���� 2.���� 3.�Ա� 4.�绰 5.��ַ\n");
		int n = 0;
		printf("��ѡ��:> ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("��������������:> ");
			scanf("%s", pc->data[pos].name);
			printf("�޸ĳɹ�\n");
			break;
		case 2:
			printf("��������������:> ");
			scanf("%d", &pc->data[pos].age);
			printf("�޸ĳɹ�\n");
			break;
		case 3:
			printf("�����������Ա�(��orŮor����):> ");
			scanf("%s", pc->data[pos].sex);
			printf("�޸ĳɹ�\n");
			break;
		case 4:
			printf("����������绰(���ܳ���12λ��):> ");
			scanf("%s", pc->data[pos].tele);
			printf("�޸ĳɹ�\n");
			break;
		case 5:
			printf("�����������ַ(���ܳ���30���ַ�):> ");
			scanf("%s", pc->data[pos].addr);
			printf("�޸ĳɹ�\n");
			break;
		}
	}
}

// ������������
int CmpByName(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

// ������������
int CmpByAge(const void* e1, const void* e2) {
	return ((PeoInfo*)e1)->age - ((PeoInfo*)e2)->age;
}

// 5. ������ϵ��
void SortContact(Contact* pc) {
	assert(pc);

	printf("������Ҫ��ʲô���ķ�ʽ��ͨѶ¼����ϵ�˽�������\n");
	printf("1.����  2.����\n");
	int n = 0;
	printf("��ѡ��:> ");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		qsort(pc->data, pc->sz, sizeof(pc->data[0]), CmpByName);//��������
		ShowContact(pc);
		break;
	case 2:
		qsort(pc->data, pc->sz, sizeof(pc->data[0]), CmpByAge);//��������
		ShowContact(pc);
		break;
	}
}

// 6. �鿴ͨѶ¼
void ShowContact(const Contact* pc) {
	assert(pc);

	if (0 == pc->sz) {
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	else {
		//��ӡ��Ϣ��
		printf("%-4s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
		int i = 0;
		for (i = 0; i < pc->sz; ++i) {
			printf("%-4s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				pc->data[i].name,
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].tele,
				pc->data[i].addr
			);
		}
	}
}

// ������Ϣ���ļ�
void SaveContact(Contact* pc) {
	//�ö����Ƶķ�ʽд
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL) {
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}

	//д�ļ�
	for (int i = 0; i < pc->sz; ++i) {
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}

// ����ͨѶ¼
void DestroyContact(Contact* pc) {
	assert(pc);

	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}
