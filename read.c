
#include<stdio.h>
int main()
{
	int a[100],i;
	FILE *fp;
	fp = fopen("D:\\date.dat", "rb");
	fread_s(a, sizeof(int), sizeof(int), 100, fp);
	for (i = 0; i < 100; i++)
	{
		printf("%03d\n", a[i]);
		if (i % 8 == 0)
			printf("\n");
	}
	fclose(fp);
}