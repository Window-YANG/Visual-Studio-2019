#include <stdio.h>

char String1[] = "flow";
char String2[] = "flower";
char String3[] = "flight";

int StrSize1 = sizeof(String1) / (sizeof(*String1)) - 1;
int StrSize2 = sizeof(String2) / (sizeof(*String2)) - 1;
int StrSize3 = sizeof(String3) / (sizeof(*String3)) - 1;


void sort(int* a, int length)//a为数组地址，l为数组长度。
{
	int i, j;
	int v;
	//排序主体
	for (i = 0; i < length - 1; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if (a[i] > a[j])//如前面的比后面的大，则交换。
			{
				v = a[i];
				a[i] = a[j];
				a[j] = v;
			}
		}
	}
}

int MostCommonPlace(char* String)
{
	int result = 0;
	int counter = 0;
	//int Strnumber = 3;

	for (counter = 0; counter < StrSize1; counter++)
	{
		if (String[counter] == String1[counter])
		{
			result++;
		}
		else
		{
			break;
		}
	}
	return result;
}

int longestCommonPrefix(void)
{
	int common[5] = {0};
	int i = 0;
	common[0] = MostCommonPlace(String2);
	common[1] = MostCommonPlace(String3);
	sort(common, 2);
	printf("MostCommonString: ");
	for (i = 0; i < common[0]; i++)
	{
		printf("%c", String1[i]);
	}
	printf("\n");
	return 0;
}


