#define  _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

void InitContact(Contact* pc) {//��ʼ���ṹ������
	assert(pc);
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	PeoInfo* p = (PeoInfo *)calloc(pc->capacity ,sizeof(PeoInfo));
	if (p == NULL) {
		perror("calloc p");
		exit(1);
	}
	pc->data = p;
}

//�������
void AddContact(Contact* pc) {
	assert(pc);
	if (pc->sz == pc->capacity) {//���ռ��Ƿ�����ӿռ�
		PeoInfo* p = (PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(PeoInfo));
		if (p == NULL) {
			perror("realloc p");
			return;
		}
		pc->data = p;
		pc->capacity += 2;
		printf("���ݳɹ�\n");
	}
	printf("������������");
	scanf("%s", pc->data[pc->sz].name);
	printf("���������䣺");
	scanf("%d", &pc->data[pc->sz].age);
	printf("�������Ա�");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰��");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ��");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
}

//��ʾ����
void ShowContact(const Contact* pc) {
	assert(pc);
	if (pc->sz == 0) {
		printf("û���κ����ݣ���ʾʧ��\n");
		return;
	}
	printf("%-15s%-5s%-5s%-15s%-15s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (int i = 0; i < pc->sz; i++) {
		printf("%-15s%-5d%-5s%-15s%-15s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}

static int FindByName(Contact* pc, char name[]) {
	assert(pc);
	for (int i = 0; i < pc->sz; i++) {
		if (strcmp(pc->data[i].name, name) == 0) {
			return i;
		}
	}
	return -1;

}

//ɾ������
void DelContact(Contact* pc) {
	assert(pc);
	char name[NAME_MAX];
	if (pc->sz == 0) {
		printf("û���κ�����,ɾ��ʧ��\n");
		return;
	}

	printf("����Ҫɾ��������:");
	scanf("%s", name);
	//�������ݣ�ʧ�ܷ���-1���ɹ������±�
	int sit = FindByName(pc, name);
	if (sit == -1) {
		printf("���ݲ�����\n");
		return;
	}
	for (int i = sit; i < pc->sz - 1; i++) {
		pc->data[sit] = pc->data[sit + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
}

//�޸�����
void MoContact(Contact* pc) {
	assert(pc);
	char name[NAME_MAX];
	if (pc->sz == 0) {
		printf("û���κ�����,�޸�ʧ��\n");
		return;
	}

	printf("����Ҫ�޸ĵ�����:");
	scanf("%s", name);
	//�������ݣ�ʧ�ܷ���-1���ɹ������±�
	int sit = FindByName(pc, name);
	if (sit == -1) {
		printf("���ݲ�����\n");
		return;
	}
	printf("������������");
	scanf("%s", pc->data[sit].name);
	printf("���������䣺");
	scanf("%d", &pc->data[sit].age);
	printf("�������Ա�");
	scanf("%s", pc->data[sit].sex);
	printf("������绰��");
	scanf("%s", pc->data[sit].tele);
	printf("�������ַ��");
	scanf("%s", pc->data[sit].addr);
}

//��ѯ����
void QuContact(Contact* pc) {
	assert(pc);
	char name[NAME_MAX];
	if (pc->sz == 0) {
		printf("û���κ�����,��ѯʧ��\n");
		return;
	}

	printf("����Ҫ�޸ĵ�����:");
	scanf("%s", name);
	//�������ݣ�ʧ�ܷ���-1���ɹ������±�
	int sit = FindByName(pc, name);
	if (sit == -1) {
		printf("���ݲ�����\n");
		return;
	}
	printf("%-15s%-5s%-5s%-15s%-15s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-15s%-5d%-5s%-15s%-15s\n", pc->data[sit].name, pc->data[sit].age, pc->data[sit].sex, pc->data[sit].tele, pc->data[sit].addr);
}

static int pc_stu_asc_cmp(const void* a, const void* b) {//��������
	return strcmp((Contact*)a, (Contact*)b);
}

static int pc_stu_desc_cmp(const void* a, const void* b) {//��������
	return strcmp((Contact*)b, (Contact*)a);
}

//��������
void SortContact(Contact* pc) {
	assert(pc);
	int ch = 0;
	if (pc->sz == 0) {
		printf("û���κ�����\n");
		return;
	}
	printf("��ѡ�������ǽ�������1���� 2������:");
	scanf("%d", &ch);
	if (ch == 1) {
		qsort(pc->data, pc->sz, sizeof(pc->data[0]), pc_stu_asc_cmp);
		printf("��������ɹ�\n");
	}
	else if (ch == 2) {
		qsort(pc->data, pc->sz, sizeof(pc->data[0]), pc_stu_desc_cmp);
		printf("��������ɹ�\n");
	}
	else {
		printf("ѡ�������Ч��\n");
	}
}

void ReContact(Contact* pc) {
	assert(pc);
	if (pc->sz == 0) {
		printf("û���κ�����,��ʼ��ʧ��\n");
		return;
	}
	pc->sz = 0;
	printf("�������óɹ�\n"); 
}

//����ͨѶ¼
void DestoryContact(Contact* pc) {
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}