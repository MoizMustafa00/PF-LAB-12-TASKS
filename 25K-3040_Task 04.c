#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, extra;
	printf("Enter Number of Days: ");
	scanf("%d", &n);
	float *sales, total = 0;
	sales = (float *) malloc(n * sizeof(float));
	if(sales == NULL)
	{
		printf("Error!\n");
		return 1;
	}
	int i;
	for(i=0; i<n; i++)
	{
		printf("Enter Sales For Day %d = ", i+1);
		scanf("%f", &sales[i]);
		total += sales[i];
	}
	printf("Total Sales = %.2f\n", total);
	printf("Enter Number of Additional Days: ");
	scanf("%d", &extra);
	sales = (float *) realloc(sales, (n+extra) * sizeof(float));
	if(sales == NULL)
	{
		printf("Error!\n");
		return 1;
	}
	for(i=n; i<n+extra; i++)
	{
		printf("Enter Sales For Day %d = ", i+1);
		scanf("%f", &sales[i]);
		total += sales[i];
	}
	printf("Recomputed Total Sales = %.2f\n", total);
	free(sales);
	return 0;
}
