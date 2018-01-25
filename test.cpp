/*（1）问题描述
学生信息包括：学号，姓名，年龄，性别，出生年月，地址，电话，E - mail等。试设计一学生信息管理系统，使之能提供以下功能：
1.系统以菜单方式工作
2.学生信息录入功能（学生信息用文件保存）-- - 输入
3.学生信息浏览功能——输出
4.查询、排序功能——算法
1、按学号查询
2、按姓名查询
5.学生信息的删除与修改（可选项）
（2）功能要求
1.界面简单明了；
2.有一定的容错能力，比如输入的成绩不在0～100之间，就提示不合法，要求重新输入；
3.最好用链表的方式实现

界面：
-------------学生信息管理系统---------------
1. 学生信息录入
2. 学生信息浏览
3. 学生信息查询
1.按学号查询
2.按姓名查询
4. 学生信息的删除与修改
--------------------------------------------
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996) 
void menu();
int input_stu_xinxi();
int check_stu_xinxi();
int browse_stu_xinxi();
/*
int revise_stu_xinxi();
*/
struct stu
{
	char stu_no[16];
	char name[20];
	char age[2];
	char sex[2];
	char birth_date[20];
	char address[1024];
	char phone[16];
	char email[24];
}students[500];
int main()
{
	menu();
	getchar();
	system("pause");
	return 0;
}

void menu()
{
	int choose;
	printf("-------------学生信息管理系统-------------\n");
	printf("\t1.学生信息录入\n");
	printf("\t2.学生信息浏览\n");
	printf("\t3.学生信息查询\n");
	printf("\t4.学生信息删除与修改\n");
	printf("\t0.退出系统\n");
	printf("------------------------------------------\n");
	printf("请输入您的选测（0-4）: ");
	scanf_s("%d", &choose);
	printf("您的选择：%d\n", choose);
	switch (choose)
	{
	case 0: exit(0); break;
	case 1: input_stu_xinxi(); break;
	case 2: check_stu_xinxi(); break;
	case 3: browse_stu_xinxi(); break;
		/*
		case 4: revise_stu_xinxi(); break;
		*/
	}
	while (choose > 4 || choose < 0)
	{
		printf("您输入了一个无效数字，请重新输入（0-4）: ");
		scanf_s("%d", &choose);
	}
}
int input_stu_xinxi()
{	/*************
	int flag = 1;
	while (flag)
	{
	struct stu students;
	FILE *fp;
	errno_t err= (fopen_s(&fp, "F:\stuinfo.txt", "w"));
	if (err!= 0)
	{
	printf("文件打开错误\n");
	exit(0);
	}
	if (fwrite(&students, sizeof(struct stu), 1, fp)!=1)
	{
	printf("\n file write error \n");
	}

	文件的写还需要完善
	printf("\t学号:");
	scanf("%s", students.stu_no);
	fputs(students.stu_no,fp);
	printf("\t姓名:");
	scanf("%s", students.name);
	fputs(students.name, fp);
	printf("\t年龄:");
	scanf("%s", students.age);
	fputs(students.age, fp);
	printf("\t性别:");
	scanf("%s", students.sex);
	fputs(students.sex, fp);
	printf("\t出生年月:");
	scanf("%s", students.birth_date);
	fputs(students.birth_date, fp);
	printf("\t地址:");
	scanf("%s", students.address);
	fputs(students.address, fp);
	printf("\t电话:");
	scanf("%s", students.phone);
	fputs(students.phone, fp);
	printf("\t邮件:");
	scanf("%s", students.email);
	fputs(students.email, fp);
	printf("\n");
	fclose(fp);
	memset(&students,0x00,sizeof(struct stu));
	printf("继续输入请按1，返回上级菜单请按2，退出请安0\n");
	scanf_s("%d", &flag);
	if (flag == 0)
	{
	exit(0);
	}
	if (flag == 1)
	{
	continue;
	}
	if (flag == 2)
	{
	menu();
	break;
	}
	}
	return 0;
	******/
	FILE *fp;
	int i, m, flag = 1;
	printf("请输入等级学生信息的总人数：");
	scanf_s("%d", &m);
	while (flag)
	{
		fp = fopen("F:\stuinfo.txt", "w");
		//errno_t err = (fopen_s(&fp, "F:\stuinfo.txt", "w"));
		if (fp == 0)
		{
			printf("文件打开错误\n");
			exit(0);
		}
		/****
		if (fwrite(&students[i], sizeof(struct stu), 1, fp) != 1)
		{
		printf("\n file write error \n");
		}
		****/
		for (i = 0; i < m; i++)
		{
			printf("学号：");   
			scanf("%s", &students[i].stu_no);
			fputs(students[i].stu_no, fp);
			fputs("\t", fp);

			printf("姓名：");
			scanf("%s", &students[i].name);
			fputs(students[i].name, fp);
			fputs("\t", fp);

			printf("年龄：");
			scanf("%s", &students[i].age);
			fputs(students[i].age, fp);
			fputs("\t", fp);

			printf("性别：");
			scanf("%s", &students[i].sex);
			fputs(students[i].sex, fp);
			fputs("\t", fp);

			printf("出生年月：");
			scanf("%s", &students[i].birth_date);
			fputs(students[i].birth_date, fp);
			fputs("\t", fp);

			printf("地址：");
			scanf("%s", &students[i].address);
			fputs(students[i].address, fp);
			fputs("\t", fp);

			printf("电话：");
			scanf("%s", &students[i].phone);
			fputs(students[i].phone, fp);
			fputs("\t", fp);

			printf("邮件：");
			scanf("%s", &students[i].email);
			fputs(students[i].email, fp);
			fputs("\n", fp);
		}
		fclose(fp);
		printf("继续输入请按1，返回上级菜单请按2，退出请安0\n");
		scanf_s("%d", &flag);
		if (flag == 0)
		{
			exit(0);
		}
		if (flag == 1)
		{
			continue;
		}
		if (flag == 2)
		{
			menu();
			break;
		}
	}
	return 0;
}

int check_stu_xinxi()
{
	//struct stu students;
	FILE *fp;
	int n = 0;		//文件总行数
	int flag = 0;
	char buf[1024];
	fp = fopen("F:\stuinfo.txt", "r");
	if (fp == 0)
	{
		printf("文件打开错误\n");
		exit(0);
	}
	while (fgets(buf, 1024, fp))
	{
		n++;
		printf("%s\n", buf);
	}
	fclose(fp);
	printf("该文件一共有%d条信息\n", n);
	printf("返回上级菜单请按2，退出请安0\n");
	scanf_s("%d", &flag);
	if (flag == 0)
	{
		exit(0);
	}
	if (flag == 2)
	{
		menu();
	}

	return 0;


}

int browse_stu_xinxi()
{
	char buf[1024];
	FILE *fp;
	//char *str;
	int i = 0;
	fp = fopen("F:\stuinfo.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开错误\n");
		exit(0);
	}
	while (fgets(buf, 1024, fp))
	{
		/*  思考 用strtok
		str = strtok(buf, "\t");
		while (str!=NULL)
		{
		students[i].stu_no = str;
		str = strtok(NULL, "\t");
		}
		*/
		fscanf(fp, "%s	%s	%s	%s	%s	%s	%s	%s", students[i].stu_no, students[i].name, students[i].age, students[i].sex, students[i].birth_date, students[i].phone, students[i].email);
		printf("%s %s %s %s %s %s %s %s,i\n", students[i].stu_no, students[i].name, students[i].age, students[i].sex, students[i].birth_date, students[i].phone, students[i].email);
		i++;

	}
	/*
	char buf[1024];
	scanf("%s",buf);
	printf("%d\n",sizeof());
	*/
	fclose(fp);
	return 0;
}

