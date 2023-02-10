

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#pragma warning(disable : 4996)
#define ERROR_FILE_OPEN -3
void add(void), lookup(void), mexpenses(void), natarea(void), deletef(void);
char menu(void);

int main(void)
{
	char choice;
	do
	{
		choice = menu();
		switch (choice)
		{
		case 'n': natarea(); break;
		case 'm': mexpenses(); break;
		case 'l': lookup(); break;
		case 'a': add(); break;
		case 'd': deletef(); break;
		};
	} while (choice != 'q');
	return 0;
};
char menu(void)
{
	char ch;
	do
	{
		printf("(N)atural area (M)onthly price (D)elete (L)ookup (A)dd (Q)uit: ");
		ch = tolower(getchar());
	} while (ch != 'q' && ch != 'n' && ch != 'm' && ch != 'a' && ch != 'l' && ch != 'd');
	return ch;
};
void add(void)
{
	FILE* fp;
	if ((fp = fopen("C:\\Users\\SOR\\Desktop\\zoo2.bin", "ab")) == NULL) exit(1);
	int summ;
	char c;
	printf("Enter the name ");
	fseek(fp, 0, SEEK_SET);
	while ((getchar()) != '\n');
	while ((c = getchar()) != '\n')  putc(c, fp);
	putc(' ', fp);
	printf("Enter natural area ");
	while ((c = getchar()) != '\n')  putc(c, fp);
	putc(' ', fp);
	printf("Enter feed costs ");
	scanf("%d", &summ);
	fwrite(&summ, sizeof(int), 1, fp);
	putc('\n', fp);
	fclose(fp);
};
void lookup(void)
{
	char* name2 = NULL, * name1 = NULL, c, ch;
	int len = 1, i = 1, p = 0, summ;
	int r = 0;
	name2 = (char*)malloc(sizeof(char));
	name1 = (char*)malloc(sizeof(char));
	FILE* fp;
	if ((fp = fopen("C:\\Users\\SOR\\Desktop\\zoo2.bin", "rb")) == NULL) exit(1);
	printf("(N)ame (A)ll:\n ");
	while ((getchar()) != '\n');
	scanf("%c", &ch);
	if (ch == 'N' || ch == 'n')
	{
		printf("Name: ");
		while ((getchar()) != '\n');
		while ((name1[len - 1] = getchar()) != '\n')
		{
			len++;
			name1 = (char*)realloc(name1, len);
			name2 = (char*)realloc(name2, len);
		}
		name1[len - 1] = '\0';
		if (name2 != NULL)while ((name2[i - 1] = getc(fp)) != EOF)
		{
			if (name2[i - 1] == '\n')
			{
				r = ftell(fp);
				i = 0;
				p = 0;
			}
			if (name2[i - 1] == ' ')p = 1;
			i++;
			if ((i >= len))
			{
				name2[i - 1] = '\0';
				if (!strcmp(name1, name2) && p < 1)
				{
					p = 0;
					rewind(fp);
					fseek(fp, r, SEEK_SET);
					while ((c = getc(fp)) != '\n')
					{
						if (c == ' ') p++;
						if (p < 2)
						{
							printf("%c", c);
						}
						else if (p == 2)
						{
							r = ftell(fp);
							fseek(fp, r, SEEK_SET);
							fread(&summ, sizeof(int), 1, fp);
							printf(" %d\n", summ);
							break;
						}
					}
				}
				else i = 1;
			}
		}
	}
	else if (ch == 'A' || ch == 'a') while ((c = getc(fp)) != EOF) printf("%c", c);
	free(name1);
	free(name2);
	fclose(fp);
}
void mexpenses(void)
{
	char* name2 = NULL, * name1 = NULL, c, ch;
	int len = 1, i = 1, p = 0, summ;
	int r = 0;
	name2 = (char*)malloc(sizeof(char));
	name1 = (char*)malloc(sizeof(char));
	FILE* fp;
	if ((fp = fopen("C:\\Users\\SOR\\Desktop\\zoo2.bin", "rb")) == NULL) exit(1);
	while ((getchar()) != '\n');
	printf("Name: ");
		while ((name1[len - 1] = getchar()) != '\n')
		{
			len++;
			name1 = (char*)realloc(name1, len);
			name2 = (char*)realloc(name2, len);
		}
		name1[len - 1] = '\0';
		if (name2 != NULL)while ((name2[i - 1] = getc(fp)) != EOF)
		{
			if (name2[i - 1] == '\n')
			{
				r = ftell(fp);
				i = 0;
				p = 0;
			}
			if (name2[i - 1] == ' ')p = 1;
			i++;
			if ((i >= len))
			{
				name2[i - 1] = '\0';
				if (!strcmp(name1, name2) && p < 1)
				{
					p = 0;
					rewind(fp);
					fseek(fp, r, SEEK_SET);
					while ((c = getc(fp)) != '\n')
					{
						if (c == ' ') p++;
						else if (p == 2)
						{
							r = ftell(fp);
							fseek(fp, r, SEEK_SET);
							fread(&summ, sizeof(int), 1, fp);
							printf(" %d\n", summ *= 30);
							break;
						}
					}
				}
				else i = 1;
			}
		}
	free(name1);
	free(name2);
	fclose(fp);
}
void natarea(void)
{
	char* natarea1 = NULL, * natarea2 = NULL, c;
	int len = 1, i = 1, r = 0, p = 1;
	natarea1 = (char*)malloc(sizeof(char));
	natarea2 = (char*)malloc(sizeof(char));
	FILE* fp;
	if ((fp = fopen("C:\\Users\\SOR\\Desktop\\zoo2.bin", "rb")) == NULL) exit(1);
	printf("Natural area ");
	while ((getchar()) != '\n');
	while ((natarea1[len - 1] = getchar()) != '\n')
	{
		len++;
		natarea1 = (char*)realloc(natarea1, len);
		natarea2 = (char*)realloc(natarea2, len);
	}
	natarea1[len - 1] = '\0';
	if (natarea2 != NULL)while ((natarea2[i - 1] = getc(fp)) != EOF)
	{
		if (natarea2[i - 1] == ' ')i = p = 0;
		if (natarea2[i - 1] == '\n')
		{
			i = 0;
			p = 1;
		}
		i++;
		natarea2 = (char*)realloc(natarea2, i);
		if ((i >= len))
		{
			natarea2[i - 1] = '\0';
			if (!strcmp(natarea1, natarea2) && p == 0) r++;
			else i = 1;
		}
	}
	printf("%s-%d\n", natarea1, r);
	free(natarea1);
	free(natarea2);
	fclose(fp);
}
void deletef(void)
{
	char* name2 = NULL, * name1 = NULL, c, ch;
	int len = 1, i = 1, p = 0;
	int r = 0, r2 = 0;
	name2 = (char*)malloc(sizeof(char));
	name1 = (char*)malloc(sizeof(char));
	FILE* fp1;
	printf("(N)ame (A)ll (R)emove (E)xit:");
	while ((getchar()) != '\n');
	scanf("%c", &ch);
	if (ch == 'E' || ch == 'e') exit(1);
	if (ch == 'N' || ch == 'n')
	{
		FILE* fp1;
		if ((fp1 = fopen("C:\\Users\\SOR\\Desktop\\zoo2.bin", "rb")) == NULL) exit(1);
		printf("\nName: ");
		while ((getchar()) != '\n');
		while ((name1[len - 1] = getchar()) != '\n')
		{
			len++;
			name1 = (char*)realloc(name1, len);
			name2 = (char*)realloc(name2, len);
		}
		name1[len - 1] = '\0';
		if (name2 != NULL)
		{
			while ((name2[i - 1] = getc(fp1)) != EOF)
			{
				if (name2[i - 1] == '\n')
				{
					r = ftell(fp1);
					i = 0;
					p = 0;
				}
				if (name2[i - 1] == ' ')p = 1;
				i++;
				if ((i >= len))
				{
					name2[i - 1] = '\0';
					if (!strcmp(name1, name2) && p < 1)
					{
						r2 = r;
						p = 0;
						fseek(fp1, r, SEEK_SET);
						while ((c = getc(fp1)) != '\n')
						{
							r = ftell(fp1);
						}
						break;
					}
					else i = 1;
				}
			}
			free(name1);
			free(name2);
			rewind(fp1);
			FILE* fp2;
			if ((fp2 = fopen("C:\\Users\\SOR\\Desktop\\zoo3.bin", "wb")) == NULL) exit(1);
			i = 0;
			int j = 0;
			while ((c = getc(fp1)) != EOF)
			{
				i++;
				putc(c, fp2);
				if (i == r2) fseek(fp1, r + 1, SEEK_SET);
			}
			fclose(fp1);
			remove("C:\\Users\\SOR\\Desktop\\zoo2.bin");
			fclose(fp2);
			rename("C:\\Users\\SOR\\Desktop\\zoo3.bin", "C:\\Users\\SOR\\Desktop\\zoo2.bin");
		}
	}
	else if (ch == 'A' || ch == 'a') fp1 = fopen("C:\\Users\\SOR\\Desktop\\zoo2.bin", "wb");
	else if (ch == 'R' || ch == 'r') remove("C:\\Users\\SOR\\Desktop\\zoo2.bin");
}