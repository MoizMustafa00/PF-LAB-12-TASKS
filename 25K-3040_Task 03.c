#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    int i, j, k;
    char **strings;
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar();
    strings = (char **)malloc(n * sizeof(char *));
    if (strings == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for(i=0; i<n; i++)
    {
        char buffer[1000];
        printf("Enter string %d: ", i+1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strings[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        if (strings[i] == NULL)
        {
            printf("Memory allocation failed for string %d!\n", i + 1);
            return 1;
        }
        strcpy(strings[i], buffer);
    }
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(strcmp(strings[j], strings[j + 1]) > 0)
            {
                char *temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = temp;
            }
        }
    }
    printf("\nSorted strings:\n");
    for(i=0; i<n; i++)
    {
        printf("%s\n", strings[i]);
    }
    for(i=0; i<n; i++)
    {
        free(strings[i]);
    }
    free(strings);
    return 0;
}
