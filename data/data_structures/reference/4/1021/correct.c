#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,j=0,k,ran;
	char stra[1000],strb[100][1000],c;
	FILE *in;
	in=fopen("article.txt","r");
	while((c=fgetc(in))!=EOF)
	{
	  if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
	  {if(c>='a'&&c<='z')
	  strb[j][i]=c;
	  else strb[j][i]=c+32;
	  i++;}
	  else
	{
	       if(i>0)
	        j++;
	        i=0;
	  }
	}
	ran=j;
	for(i=0;i<ran;i++)
	{
		for(j=0;j<ran-i-1;j++)
		{
			if(strcmp(strb[j],strb[j+1])>0)
			{
				strcpy(stra,strb[j]);
				strcpy(strb[j],strb[j+1]);
				strcpy(strb[j+1],stra);
			}
		}
	}
	for(i=0;i<ran;i++)
	{
		k=0;
		for(j=i;j<ran;j++)
		{
			if(strcmp(strb[i],strb[j])!=0)
			break;
			else k++;
		}
		printf("%s %d\n",strb[i],k);
		i=j-1;
	}
	fclose(in);
	return 0;
}

