#include<stdio.h>
#include <string.h>
char list[50];
void Swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void Perm(char* list, int k, int m)
{
    if (k == m)                                  
    {
        int i;
		for (i = 0; i <= m; ++i)             
        {
            printf("%d ", list[i]);
        }
        printf("\n");
        return;
    }
    else
    {
    	int i;
        for (i = k; i <= m; i++)
        {
        	if (i > k) {
				char list2[50];
            	strcpy(list2, list);
            	//Swap(&list[k], &list[i]);  
            	list[k] = list2[i];
            	list[k + 1] = list2[k];
            	strncpy(list + k + 2, list2 + k + 1, i - k - 1);
            	//list[m + 1] = 0;
            	Perm(list, k + 1, m);
            	//Swap(&list[k], &list[i]);
            	strcpy(list, list2);
        	}
        	else  Perm(list, k + 1, m);
        }
    }
}
int main()
{
    int n,i;
	scanf("%d",&n);
    list[0]=1;
    for(i=1;i<n;i++)
    {
    	list[i]=list[i-1]+1;
	}
    Perm(list, 0, n - 1);
    return 0;
}







