#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	int *ptr;
	printf("Enter the Size of the Array: ");
	scanf("%d", &n);
	ptr = (int *) calloc(n, sizeof(int));
	if(ptr == NULL)
	{
		printf("Error!\n");
		return 1;
	}
	int i;
	printf("Enter %d Elements:\n", n);
	for(i=0; i<n; i++)
	{
		printf("Element %d = ", i+1);
		scanf("%d", &ptr[i]);
	}
	int oldSize = n;
	int newSize = n*2;
	int *temp = (int *) realloc(ptr, newSize * sizeof(int));
	if(temp == NULL)
	{
		printf("Error!\n");
		return 1;
	}
	ptr = temp;
	printf("Enter %d New Elements:\n", newSize - oldSize);
	for(i=oldSize; i<newSize; i++)
	{
		printf("Element %d = ", i+1);
		scanf("%d", &ptr[i]);
	}
	printf("Updated Array:\n");
	for(i=0; i<newSize; i++)
	{
		printf("%d\n", ptr[i]);
	}
	free(ptr);
	return 0;
}
