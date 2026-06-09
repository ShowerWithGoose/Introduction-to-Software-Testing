#include <stdio.h>
#include <string.h>
struct lnode {
    char word[32];
    int count;
};
int i,j=0,k,m,n,temp=0,temp1;
char ch,p[32];
struct lnode s[10000];
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	while((ch=fgetc(in))!=EOF)
	{
		if(ch>='A'&&ch<='Z')
			ch=ch+32;
		if(ch>='a'&&ch<='z'){
			p[j]=ch;
			j++;temp=1;}
		else if(temp==1 && (ch<'a' || ch>'z'))
		{
			temp=0;temp1=0;
			for(i=0;i<k;i++)
			{
				if(strcmp(s[i].word, p )==0)
				{
					s[i].count +=1;
					for(n=0;n<32;n++)
						p[n]='\0';
					temp1=1;j=0;break;
				}
			}
			if(temp1==0)
			{
				i=0;
				for(i=0;i<k;i++)
				{
					if(strcmp(s[i].word ,p)>0)
					{
						for(m=k;m>i;m--)
						{
							strcpy(s[m].word,s[m-1].word );
							s[m].count =s[m-1].count ;
						}
						strcpy(s[i].word ,p) ;
						s[i].count =1;
						for(n=0;n<32;n++)
							p[n]='\0';
						j=0;k++;
						break;
					}
			    }
			    if(i==k)
			    {
			    	strcpy(s[i].word ,p);
			    	s[i].count =1;
			    	for(n=0;n<32;n++)
						p[n]='\0';
					j=0;k++;
				}
			}
		}
	}
	for(i=0;i<k;i++)
		printf("%s %d\n",s[i].word ,s[i].count );
	return 0;
}

