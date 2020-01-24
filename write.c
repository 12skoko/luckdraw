
#include<stdio.h>
int main()
{
	int a[100] = {0};
	FILE *fp;
	fp = fopen("D:\\date.dat", "wb");
	fwrite(a, sizeof(int), 100, fp);
	fclose(fp);
	getchar();
	return 0;
}