#include<stdio.h>
#include<string.h>

#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32

char word[20];
char word2[20];
char round;
char enter_word();

void check_letters(char* word, char* word2) {
	for (int i = 0; i < strlen(word); i++) {
		if (word[i] == word2[i]) {
			printf("%c", word[i]);
		}
		else
			printf("_");
	}

}

int main()
{
	printf("Podaj ilosc prob:\n");
	//gets(round);
	scanf_s("%c", &round);
	//getch();
	int n = (int)round - 48;
	enter_word();

	for (int i = 0; i < n; i++)
	{
		printf("\nGRACZ 2: odgadnij slowo:\n");
		gets(word2);
		int result = strcmp(word, word2);

		if (result == 0) {
			printf("\n Jestes zwyciezca");
			break;

		}
		else
		{
			check_letters(word, word2);
			printf("\n Sprobuj jeszcze raz ");
		}

	}

	getch();

	return 0;
}

char enter_word()
{
	int i = 0;
	char ch;
	printf("GRACZ 1: wpisz slowo:");
	while (1)
	{
		ch = getch();
		if (ch == ENTER)
		{
			word[i] = '\0';
			break;
		}
		else if (ch == BKSP)
		{
			if (i > 0)
			{
				i--;
				printf("\b \b");

			}
		}
		else if (ch == TAB || ch == SPACE)
		{
			continue;
		}
		else
		{
			word[i] = ch;
			i++;
			printf("*");
		}

	}
	char word2[10];

	gets(word2);

	printf("\nLength:%u", strlen(word));
}