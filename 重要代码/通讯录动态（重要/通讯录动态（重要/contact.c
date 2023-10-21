#define  _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

void InitContact(Contact* pc) {//初始化结构体内容
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

//添加数据
void AddContact(Contact* pc) {
	assert(pc);
	if (pc->sz == pc->capacity) {//检测空间是否满添加空间
		PeoInfo* p = (PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(PeoInfo));
		if (p == NULL) {
			perror("realloc p");
			return;
		}
		pc->data = p;
		pc->capacity += 2;
		printf("增容成功\n");
	}
	printf("请输入姓名：");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄：");
	scanf("%d", &pc->data[pc->sz].age);
	printf("请输入性别：");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话：");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址：");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
}

//显示数据
void ShowContact(const Contact* pc) {
	assert(pc);
	if (pc->sz == 0) {
		printf("没有任何数据，显示失败\n");
		return;
	}
	printf("%-15s%-5s%-5s%-15s%-15s\n", "姓名", "年龄", "性别", "电话", "地址");
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

//删除数据
void DelContact(Contact* pc) {
	assert(pc);
	char name[NAME_MAX];
	if (pc->sz == 0) {
		printf("没有任何数据,删除失败\n");
		return;
	}

	printf("输入要删除的姓名:");
	scanf("%s", name);
	//查找数据，失败返回-1，成功返回下标
	int sit = FindByName(pc, name);
	if (sit == -1) {
		printf("数据不存在\n");
		return;
	}
	for (int i = sit; i < pc->sz - 1; i++) {
		pc->data[sit] = pc->data[sit + 1];
	}
	pc->sz--;
	printf("删除成功\n");
}

//修改数据
void MoContact(Contact* pc) {
	assert(pc);
	char name[NAME_MAX];
	if (pc->sz == 0) {
		printf("没有任何数据,修改失败\n");
		return;
	}

	printf("输入要修改的姓名:");
	scanf("%s", name);
	//查找数据，失败返回-1，成功返回下标
	int sit = FindByName(pc, name);
	if (sit == -1) {
		printf("数据不存在\n");
		return;
	}
	printf("请输入姓名：");
	scanf("%s", pc->data[sit].name);
	printf("请输入年龄：");
	scanf("%d", &pc->data[sit].age);
	printf("请输入性别：");
	scanf("%s", pc->data[sit].sex);
	printf("请输入电话：");
	scanf("%s", pc->data[sit].tele);
	printf("请输入地址：");
	scanf("%s", pc->data[sit].addr);
}

//查询数据
void QuContact(Contact* pc) {
	assert(pc);
	char name[NAME_MAX];
	if (pc->sz == 0) {
		printf("没有任何数据,查询失败\n");
		return;
	}

	printf("输入要修改的姓名:");
	scanf("%s", name);
	//查找数据，失败返回-1，成功返回下标
	int sit = FindByName(pc, name);
	if (sit == -1) {
		printf("数据不存在\n");
		return;
	}
	printf("%-15s%-5s%-5s%-15s%-15s\n", "姓名", "年龄", "性别", "电话", "地址");
	printf("%-15s%-5d%-5s%-15s%-15s\n", pc->data[sit].name, pc->data[sit].age, pc->data[sit].sex, pc->data[sit].tele, pc->data[sit].addr);
}

static int pc_stu_asc_cmp(const void* a, const void* b) {//升序排序
	return strcmp((Contact*)a, (Contact*)b);
}

static int pc_stu_desc_cmp(const void* a, const void* b) {//降序排序
	return strcmp((Contact*)b, (Contact*)a);
}

//排序数据
void SortContact(Contact* pc) {
	assert(pc);
	int ch = 0;
	if (pc->sz == 0) {
		printf("没有任何数据\n");
		return;
	}
	printf("请选择升序还是降序排序（1、升 2、降）:");
	scanf("%d", &ch);
	if (ch == 1) {
		qsort(pc->data, pc->sz, sizeof(pc->data[0]), pc_stu_asc_cmp);
		printf("升序排序成功\n");
	}
	else if (ch == 2) {
		qsort(pc->data, pc->sz, sizeof(pc->data[0]), pc_stu_desc_cmp);
		printf("降序排序成功\n");
	}
	else {
		printf("选择错误，无效。\n");
	}
}

void ReContact(Contact* pc) {
	assert(pc);
	if (pc->sz == 0) {
		printf("没有任何数据,初始化失败\n");
		return;
	}
	pc->sz = 0;
	printf("数据重置成功\n"); 
}

//销毁通讯录
void DestoryContact(Contact* pc) {
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}