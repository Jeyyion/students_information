/*��1����������
ѧ����Ϣ������ѧ�ţ����������䣬�Ա𣬳������£���ַ���绰��E - mail�ȡ������һѧ����Ϣ����ϵͳ��ʹ֮���ṩ���¹��ܣ�
1.ϵͳ�Բ˵���ʽ����
2.ѧ����Ϣ¼�빦�ܣ�ѧ����Ϣ���ļ����棩-- - ����
3.ѧ����Ϣ������ܡ������
4.��ѯ�������ܡ����㷨
1����ѧ�Ų�ѯ
2����������ѯ
5.ѧ����Ϣ��ɾ�����޸ģ���ѡ�
��2������Ҫ��
1.��������ˣ�
2.��һ�����ݴ���������������ĳɼ�����0��100֮�䣬����ʾ���Ϸ���Ҫ���������룻
3.���������ķ�ʽʵ��

���棺
-------------ѧ����Ϣ����ϵͳ---------------
1. ѧ����Ϣ¼��
2. ѧ����Ϣ���
3. ѧ����Ϣ��ѯ
1.��ѧ�Ų�ѯ
2.��������ѯ
4. ѧ����Ϣ��ɾ�����޸�
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
	printf("-------------ѧ����Ϣ����ϵͳ-------------\n");
	printf("\t1.ѧ����Ϣ¼��\n");
	printf("\t2.ѧ����Ϣ���\n");
	printf("\t3.ѧ����Ϣ��ѯ\n");
	printf("\t4.ѧ����Ϣɾ�����޸�\n");
	printf("\t0.�˳�ϵͳ\n");
	printf("------------------------------------------\n");
	printf("����������ѡ�⣨0-4��: ");
	scanf_s("%d", &choose);
	printf("����ѡ��%d\n", choose);
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
		printf("��������һ����Ч���֣����������루0-4��: ");
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
	printf("�ļ��򿪴���\n");
	exit(0);
	}
	if (fwrite(&students, sizeof(struct stu), 1, fp)!=1)
	{
	printf("\n file write error \n");
	}

	�ļ���д����Ҫ����
	printf("\tѧ��:");
	scanf("%s", students.stu_no);
	fputs(students.stu_no,fp);
	printf("\t����:");
	scanf("%s", students.name);
	fputs(students.name, fp);
	printf("\t����:");
	scanf("%s", students.age);
	fputs(students.age, fp);
	printf("\t�Ա�:");
	scanf("%s", students.sex);
	fputs(students.sex, fp);
	printf("\t��������:");
	scanf("%s", students.birth_date);
	fputs(students.birth_date, fp);
	printf("\t��ַ:");
	scanf("%s", students.address);
	fputs(students.address, fp);
	printf("\t�绰:");
	scanf("%s", students.phone);
	fputs(students.phone, fp);
	printf("\t�ʼ�:");
	scanf("%s", students.email);
	fputs(students.email, fp);
	printf("\n");
	fclose(fp);
	memset(&students,0x00,sizeof(struct stu));
	printf("���������밴1�������ϼ��˵��밴2���˳��밲0\n");
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
	printf("������ȼ�ѧ����Ϣ����������");
	scanf_s("%d", &m);
	while (flag)
	{
		fp = fopen("F:\stuinfo.txt", "w");
		//errno_t err = (fopen_s(&fp, "F:\stuinfo.txt", "w"));
		if (fp == 0)
		{
			printf("�ļ��򿪴���\n");
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
			printf("ѧ�ţ�");   
			scanf("%s", &students[i].stu_no);
			fputs(students[i].stu_no, fp);
			fputs("\t", fp);

			printf("������");
			scanf("%s", &students[i].name);
			fputs(students[i].name, fp);
			fputs("\t", fp);

			printf("���䣺");
			scanf("%s", &students[i].age);
			fputs(students[i].age, fp);
			fputs("\t", fp);

			printf("�Ա�");
			scanf("%s", &students[i].sex);
			fputs(students[i].sex, fp);
			fputs("\t", fp);

			printf("�������£�");
			scanf("%s", &students[i].birth_date);
			fputs(students[i].birth_date, fp);
			fputs("\t", fp);

			printf("��ַ��");
			scanf("%s", &students[i].address);
			fputs(students[i].address, fp);
			fputs("\t", fp);

			printf("�绰��");
			scanf("%s", &students[i].phone);
			fputs(students[i].phone, fp);
			fputs("\t", fp);

			printf("�ʼ���");
			scanf("%s", &students[i].email);
			fputs(students[i].email, fp);
			fputs("\n", fp);
		}
		fclose(fp);
		printf("���������밴1�������ϼ��˵��밴2���˳��밲0\n");
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
	int n = 0;		//�ļ�������
	int flag = 0;
	char buf[1024];
	fp = fopen("F:\stuinfo.txt", "r");
	if (fp == 0)
	{
		printf("�ļ��򿪴���\n");
		exit(0);
	}
	while (fgets(buf, 1024, fp))
	{
		n++;
		printf("%s\n", buf);
	}
	fclose(fp);
	printf("���ļ�һ����%d����Ϣ\n", n);
	printf("�����ϼ��˵��밴2���˳��밲0\n");
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
		printf("�ļ��򿪴���\n");
		exit(0);
	}
	while (fgets(buf, 1024, fp))
	{
		/*  ˼�� ��strtok
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

