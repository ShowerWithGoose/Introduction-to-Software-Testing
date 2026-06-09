#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct node{
	char c[100];
	 int x;	
};
int main(){
	struct node a[100];
	struct node temp;
	char b[1000];
	int i,num=0,k=0,h=0,l;
	int sin=1;
	FILE *fi;
	fi = fopen("article.txt", "r");
	char s;
	while(fscanf(fi,"%c",&s)!=EOF){
		if('A'<=s && s<='Z')
		{
			a[num].c[h]=s+32;
			h++;
		}
		else if('a'<=s && s<='z')
		{
			a[num].c[h]=s;
			h++; 
		}
		else
		{
			a[num].c[h]=' ';
			a[num].c[h++]='\0';
			num++;
			h=0;
		}
	}
	
/*	for(i=0 ;i<j;i++)
	{
		printf("%s\n",a[i].c);
	}*/
	int j;
	for(i=0;i<num;i++){
		 for(j=0;j<num-i-1;j++)
        {
            if(strcmp(a[j].c,a[j+1].c)>0 )
            {
                char hold[100];
                strcpy(hold,a[j].c);
                strcpy(a[j].c,a[j+1].c);
                strcpy(a[j+1].c,hold);
            }
        }
		
	}
	
/*	for(i=0 ;i<num;i++)
	{
		printf("%s\n",a[i].c);
	}*/
	
		 for(i=0;i<num;i++)
    {
    	a[i].x=1;
        for(j=i+1;j<num;j++)
        {
			if(strcmp(a[i].c,a[j].c)==0)
			{
				a[i].x++;
				strcpy(a[j].c, "\0");
			}
		}
		}
			for(i=0;i<num;i++)
	{
		if(strlen(a[i].c)!=0)
		{
			printf("%s %d\n",a[i].c,a[i].x);
		}
	}		
	
	
}

