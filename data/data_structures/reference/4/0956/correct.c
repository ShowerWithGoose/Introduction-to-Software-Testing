 #include<stdio.h>
 #include<string.h>
 #include<math.h>
 #include<stdlib.h>
 #include<ctype.h>
 int cmp(const void *a,const void *b);
 struct worlds{
 	char s[100];
 	int flow;
 };
 int main()
 {
 	struct worlds word[1000];
 	char ch[100],q[10000];
 	int i,j,k,t,num=0;
 	FILE *in;
 	in=fopen("article.txt","r");
 	t=0;
 	while(fgets(q,10000,in)!=NULL)
 	{
 		for(i=0;i<strlen(q);i++)
 		{
 			if(q[i]>='A'&&q[i]<='Z')
 			q[i]=q[i]-'A'+'a';
		 }
		for(i=0;i<strlen(q);i++)
		{	
			num=0;
			if(q[i]>='a'&&q[i]<='z')
			{
				for(j=0;;j++)
				{
					if(q[i+j]>='a'&&q[i+j]<='z')
					{
						ch[j]=q[i+j];
					}
					else
					{
						ch[j]='\0';
						break;
					}
				}
				for(k=0;k<=t;k++)
				{
					if(strcmp(word[k].s,ch)==0)
					{
						word[k].flow++;
						break;
					}
					else
					{
						num++;
					}
				}
				if(num==t+1)
				{
					for(k=0;k<strlen(ch);k++)
					{
						word[t].s[k]=ch[k];
					}
					word[t].s[k]='\0';
					t++;
				}
				i=i+j;
			}
		}
	 }
	qsort(word,t,sizeof(word[0]),cmp);
		for(i=0;i<t;i++)
		{
			printf("%s %d\n",word[i].s,word[i].flow+1);
		}
		return 0;
 }
 int cmp(const void *p1,const void *p2)
{
	struct worlds *a=(struct worlds*)p1;
	struct worlds *b=(struct worlds*)p2;
	return strcmp(a->s,b->s);
}
 



