#include<stdio.h>

int main()
{
	/*
	char string[] = "I LOVE YOU!";

	int count = 0;

	for (int i = 0; i<string[i]; i++)
		count++;

	printf("%d", count);

	//count = strlen(string);
	//count = sizeof(string);


	return 0;*/

	/*//3 두 문자열을 합쳐서 출력
	char str1[100] = "I love you. ";
	char str2[100] = "Do you love me?";
	
	strcat(str1, str2, 6);

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	printf("%d\n", len1);
	printf("%d\n", len2);

	for (int i = 0; i < len2; i++)
		str1[len1 + i] = str2[i];

	printf("1.%s\n", str1); // "I love you. Do you love me?"
	printf("2.%s\n", str2); // "Do you love me?"*/

	//5 공백 제거

	/*char str1[100] = "I love you.";
	int len1 = strlen(str1);
	int j = 0;
	for (int i = 0; i < len1; i++)
	{
		if (str1[i] != ' ')
		{
			str1[j] = str1[i];
			j++;
		}
	}
	str1[j] = '\0';
	printf("%s\n", str1);*/


	/*char str1[100] = "I love you.";
	char str2[100] = "0";
	int len1 = strlen(str1);
	int j = 0;
	for (int i = 0; i < len1; i++)
	{
		if (str1[i] != ' ')
		{
			str2[j] = str1[i];
			j++;
		}
	}
	printf("%s\n", str2);*/

	//10. 단어 뒤집기
	/*char string[] = "I love you!";
	char string2[20] = { 0, };

	int len1 = strlen(string);
	int j = 0;
	for (int i = len1; i >= 0; i--)
	{
		if (string[i] != '\0')
			//if (string[i] != ' ')
			{
				string2[j] = string[i];
				j++;
			}
	}

	string2[j] = '\0';
	printf("%s", string2);*/

	//11. 대소문자 전환하기
	char str[] = "I am a Boy";

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		else if (str[i] >= 90 && str[i] <= 122)
			str[i] -= 32;
	}
	printf("%s ", str);

	return 0;
}