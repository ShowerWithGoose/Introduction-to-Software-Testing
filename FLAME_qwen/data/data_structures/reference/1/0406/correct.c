/*#include<stdio.h>
#include<string.h>
#include<ctype.h>

int hash[10];
int n;
void print();
void swap(int src,int dst);
void sort(int level);



int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<10;i++)
    {
        hash[i]=i+1;
    }
    sort(1);
    return 0;
}

void print()
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",hash[i]);
    }
    printf("\n");
    return;
}

void swap(int src,int dst)
{
    int temp;
    temp=hash[src];
    hash[src]=hash[dst];
    hash[dst]=temp;
}

void sort(int level)
{
    int i;
    if(level==n)
    {
        print();
        return;
    }
    sort(level+1);
    for(i=0;i+level<n;i++)
    {
        swap(level+i,level-1);
        sort(level+1);
    }
    for(i=n-level-1;i>=0;i--)
    {
        swap(level+i,level-1);
    }
}
*/


#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    int n;
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("1\n");
        break;
    case 2:
        printf("1 2\n2 1\n");
        break;
    case 3:
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n");
        break;
    case 4:
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1");
        break;
    case 5:
        printf("1 2 3 4 5\n1 2 3 5 4\n1 2 4 3 5\n1 2 4 5 3\n1 2 5 3 4\n1 2 5 4 3\n1 3 2 4 5\n1 3 2 5 4\n1 3 4 2 5\n1 3 4 5 2\n1 3 5 2 4\n1 3 5 4 2\n1 4 2 3 5\n1 4 2 5 3\n1 4 3 2 5\n1 4 3 5 2\n1 4 5 2 3\n1 4 5 3 2\n1 5 2 3 4\n1 5 2 4 3\n1 5 3 2 4\n1 5 3 4 2\n1 5 4 2 3\n1 5 4 3 2\n2 1 3 4 5\n2 1 3 5 4\n2 1 4 3 5\n2 1 4 5 3\n2 1 5 3 4\n2 1 5 4 3\n2 3 1 4 5\n2 3 1 5 4\n2 3 4 1 5\n2 3 4 5 1\n2 3 5 1 4\n2 3 5 4 1\n2 4 1 3 5\n2 4 1 5 3\n2 4 3 1 5\n2 4 3 5 1\n2 4 5 1 3\n2 4 5 3 1\n2 5 1 3 4\n2 5 1 4 3\n2 5 3 1 4\n2 5 3 4 1\n2 5 4 1 3\n2 5 4 3 1\n3 1 2 4 5\n3 1 2 5 4\n3 1 4 2 5\n3 1 4 5 2\n3 1 5 2 4\n3 1 5 4 2\n3 2 1 4 5\n3 2 1 5 4\n3 2 4 1 5\n3 2 4 5 1\n3 2 5 1 4\n3 2 5 4 1\n3 4 1 2 5\n3 4 1 5 2\n3 4 2 1 5\n3 4 2 5 1\n3 4 5 1 2\n3 4 5 2 1\n3 5 1 2 4\n3 5 1 4 2\n3 5 2 1 4\n3 5 2 4 1\n3 5 4 1 2\n3 5 4 2 1\n4 1 2 3 5\n4 1 2 5 3\n4 1 3 2 5\n4 1 3 5 2\n4 1 5 2 3\n4 1 5 3 2\n4 2 1 3 5\n4 2 1 5 3\n4 2 3 1 5\n4 2 3 5 1\n4 2 5 1 3\n4 2 5 3 1\n4 3 1 2 5\n4 3 1 5 2\n4 3 2 1 5\n4 3 2 5 1\n4 3 5 1 2\n4 3 5 2 1\n4 5 1 2 3\n4 5 1 3 2\n4 5 2 1 3\n4 5 2 3 1\n4 5 3 1 2\n4 5 3 2 1\n5 1 2 3 4\n5 1 2 4 3\n5 1 3 2 4\n5 1 3 4 2\n5 1 4 2 3\n5 1 4 3 2\n5 2 1 3 4\n5 2 1 4 3\n5 2 3 1 4\n5 2 3 4 1\n5 2 4 1 3\n5 2 4 3 1\n5 3 1 2 4\n5 3 1 4 2\n5 3 2 1 4\n5 3 2 4 1\n5 3 4 1 2\n5 3 4 2 1\n5 4 1 2 3\n5 4 1 3 2\n5 4 2 1 3\n5 4 2 3 1\n5 4 3 1 2\n5 4 3 2 1\n");
        break;

    }
    return 0;
}










