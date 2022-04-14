#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
	int i, n, j;
	char arr[10][20], temp[20];
	
	printf("How many munber you want to enter\n");
	scanf("%d", &n);
	printf("Enter %d names\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%sf", &arr[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (strcmp(arr[j], arr[j + 1]) > 0)
			{
				strcpy(temp, arr[j]);
				strcpy(arr[j], arr[j + 1]);
				strcpy(arr[j + 1], temp);
			}
		}
	}
	printf("_________Sorted Names_________\n");
	for (i = 0; i < n; i++)
	{
		printf("%s \n", arr[i]);
	}
	return 0;
}