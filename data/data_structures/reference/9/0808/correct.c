#include<stdio.h>
#include<string.h>
struct zb
{
	int x1;
	int y1;
	int x2;
	int y2;
	int hash;
	int a;
	int b;
}s[100];
void sortbyName(struct zb s[], int n)
{
    int i,j;
    struct zb tmp;
    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
		{
            if(s[i].x2>s[j].x2)
			{
                tmp=s[i];
	            s[i]=s[j];
                s[j]=tmp;
            }
        }
}
int main()
{
	int n,i,j,hash2,a2,b2;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
	}
	sortbyName(s,n);
	for(i=0;i<n;i++)
	{
		s[i].hash=1;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((s[j].x1==s[i].x2)&&(s[j].y1==s[i].y2))
			{
				if(s[i].hash==1)
				{
				    s[j].hash++;
				    s[j].a=s[i].x1;
					s[j].b=s[i].y1;
				    
				}
				else if(s[i].hash==2)
				{
					s[j].hash=1+s[i].hash;
					s[j].a=s[i].a;
					s[j].b=s[i].b;
				}
				else if(s[i].hash>2)
				{
					s[j].hash=1+s[i].hash;
					s[j].a=s[i].a;
					s[j].b=s[i].b;
				}
			    break; 
			}
		}
	}
	hash2=0;
	for(i=0;i<n;i++)
	{
        if(s[i].hash>hash2)
		{
            hash2=s[i].hash;
	        a2=s[i].a;
            b2=s[i].b;
        }
    }
    printf("%d %d %d",hash2,a2,b2);
	return 0;
}

