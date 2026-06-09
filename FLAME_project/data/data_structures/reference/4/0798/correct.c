#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct word
{
    char wo[1000];
    int n;
}a[1000];
int cmp(const void*p1,const void *p2)
{
	struct word *a=(struct word *)p1;struct word *b=(struct word *)p2;
	return strcmp(a->wo,b->wo);
}
int main()
{
    int z=0, x=0;
    FILE *in;
    in=fopen("article.txt", "r");
    char temp;
    if(in == NULL){
        printf("dw");
    }

    while(fscanf(in, "%c", &temp)!=EOF)
    {
        //printf("a\n");
        if((temp>='a'&&temp<='z')||(temp<='Z'&&temp>='A'))
        {
            if(temp<='Z')
                temp=temp-'A'+'a';
            a[x].wo[z++]=temp;
        }
        else if(strlen(a[x].wo))
        {

            a[x].n=1;
            x++;
            z=0;
        }
    }
    //printf("Y");
    qsort(a, x, sizeof(a[0]), cmp);
    //printf("%d\n",x);
    for(int i=0;i<x;i++)
	{
	    //printf("A\n");
		if(strcmp(a[i].wo,a[i+1].wo)==0)
		a[i+1].n+=a[i].n;
		else if(strlen(a[i].wo))
		printf("%s %d\n",a[i].wo,a[i].n);
	}
	fclose(in);
    return 0;
}

