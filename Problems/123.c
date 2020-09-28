#include <stdio.h>
#include <string.h>

typedef struct BOOK {
	char title[100];
	char author[100];
}BOOK;

void menu();
void add_book(FILE* fp);
void print_book(FILE* fp);
void search_book(FILE* fp);
int main(void) {
	FILE* fp;
	int choose, n;
	while (1)
	{
		if ((fp = fopen("librarybook.txt", "a+")) == NULL)
		{
			fprintf(stderr, "�Է��� ���� ������ �� �� �����ϴ�");
			exit(1);
		}
		menu();
		scanf("%d", &choose);
		switch (choose)
		{
		case 1: add_book(fp); fclose(fp); break;
		case 2: print_book(fp); fclose(fp); break;
		case 3: search_book(fp); fclose(fp); break;
		case 4: return 0;
		}
	}
	fclose(fp);
	return 0;
}

void menu()
{
	printf("====================\n");
	printf("1.\t�߰�\n2.\t���\n3.\t�˻�\n4.\t����\n");
	printf("====================\n");
	printf("�������� �Է��Ͻÿ� :");
}
void add_book(FILE* fp)
{
	BOOK temp = { "","" };
	getchar();
	printf("������ �̸�: ");
	gets(temp.title);
	printf("����: ");
	gets(temp.author);
	fseek(fp, 0, SEEK_END);
	fwrite(&temp, sizeof(temp), 1, fp);

}

void print_book(FILE* fp)
{
	BOOK temp2;
	fseek(fp, 0, SEEK_SET);

	while (!feof(fp))
	{
		fread(&temp2, sizeof(BOOK), 1, fp);
		printf("������ �̸�: %s\n", temp2.title);
		printf("����:%s\n", temp2.author);
	}
}

void search_book(FILE* fp)
{
	char bookname[256];
	BOOK temp3;
check:
	fseek(fp, 0, SEEK_SET);
	printf("�˻��� �����̸�: ");
	scanf("%s", bookname);
	while (fread(&temp3, sizeof(BOOK), 1, fp))
	{
		if (strcmp(temp3.title, bookname) == 0)
		{
			printf("�����̸�: %s\n", temp3.title);
			printf("����: %s\n", temp3.author);
			return;
		}
	}
	printf("�ش��ϴ� ������ �����ϴ�.\n\n");
	goto check;
}
