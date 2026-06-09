#include <stdio.h>
struct duo
{
	int a;
	int b;
}duo1[99999],duo2[99999],duo[99999],temp;
int main()
{
	int i=0,j,k,len1,len2,a=1,l[1000],p=0;
	while(a!=0)
	{
		scanf("%d%d",&duo1[i].a,&duo1[i].b);
		i++;
		if(getchar()=='\n')
            break;
	}
	len1=i+1;
	i=0;
	while(a!=0)
	{
		scanf("%d%d",&duo2[i].a,&duo2[i].b); 
		i++;
		if(getchar()=='\n')
            break;
	}
	len2=i+1;
	for(i=0,k=0;i<len1;i++)
    {
        for(j=0;j<len2;j++,k++)
        {
           duo[k].a=duo1[i].a*duo2[j].a;
        	duo[k].b=duo1[i].b+duo2[j].b;
        	l[p]=1;
			p++;
        }
    }
    for(i=0;i<p;i++)
    {
        for(j=i+1;j<p;j++)
        {
            if( duo[i].b< duo[j].b )
            {
                temp=duo[i];
                duo[i] = duo[j];
                duo[j] = temp;
            }
        }
    } 
    for(i=0;i<p;i++)
    {
        for(j=i+1;j<p;j++)
        {
        	if(duo[i].b==duo[j].b)
        	{
        		duo[i].a=duo[i].a+duo[j].a;
        		l[j]=2;
			}
		}
	}
	for(i=0;i<p;i++)
    {
    	if(l[i]==1&&duo[i].a!=0)
    	printf("%d %d ",duo[i].a,duo[i].b);
	}
     
     return 0;

	
}



