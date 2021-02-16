#include <stdio.h>

int main(void)
{
	int example[10] = { 1,2,3,4,5,6,7,8,9,12 };
	int ii = 0, temp[1] = { 0 };
	int reversize = 3;
	for (ii = 0; ii < (int)((sizeof(example) / sizeof(example[0]) - 1)/2) + 1 ; ii++)
	{
		temp[0] = example[ii];
		example[ii] = example[(sizeof(example) / sizeof(example[0]) - 1) - ii];
		example[(sizeof(example) / sizeof(example[0]) - 1) - ii] = temp[0];
	}
	
	for (ii = 0; ii < (int)(reversize / 2); ii++)
	{
		temp[0] = example[ii];
		example[ii] = example[reversize - ii];
		example[reversize - ii] = temp[0];
	}

	for (ii = 0; ii < (int)((sizeof(example) / sizeof(example[0]) - reversize) / 2) + 1; ii++)
	{
		temp[0] = example[ii + reversize + 1];
		example[ii + reversize + 1] = example[(sizeof(example) / sizeof(example[0]) - 1) - ii];
		example[(sizeof(example) / sizeof(example[0]) - 1) - ii] = temp[0];
	}


	for (ii = 0; ii < (sizeof(example) / sizeof(example[0])); ii++)
	{
		printf("%d ", example[ii]);
	}

	return 0;

}