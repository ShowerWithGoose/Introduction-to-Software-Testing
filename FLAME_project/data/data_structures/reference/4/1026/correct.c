#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	int i=0;
	int j=0;
	int n;
	int flag=0;
	char cmp[15];
	char word[1000][15];
	char ww[1000][15];
	int cc[1000];
	char hold[15];
	int hh;
	char c;
	int nn=0;
	FILE *in;
	for(i=0;i<1000;i++){
		for(j=0;j<15;j++){
			word[i][j]='\0';
			ww[i][j]='\0';
		}
		cc[i]=0;
	}
	for(i=0;i<15;i++){
		hold[i]='\0';
		cmp[i]='\0';
	}
	i=j=0;
	in=fopen("article.txt","r");
	while((c=fgetc(in))!=EOF){
		if((c<='z'&&c>='a')||(c<='Z'&&c>='A')){
			if(c<='Z'&&c>='A')
				c=c+32;
			word[i][j]=c;
			j++;
			flag=0;
		}
		else if(((c>=' '&&c<'A')||c=='\n'||c>'z'||(c>'Z'&&c<'a'))&&flag==0){
			i++;
			j=0;
			flag=1;
		}
	}
	fclose(in);
	n=i+1;
	flag=0;
	for(i=0;i<n;i++){
		for(j=0;j<nn;j++){
			if(strcmp(word[i],ww[j])==0&&strcmp(ww[j],cmp)!=0){
				flag=1;
				break;
			}
		}
		cc[j]++;
		if(flag==0){
			nn++;
			strcpy(ww[j],word[i]);
		}
		flag=0;
		
	}
	//for(i=0;i<nn;i++)
	//	printf("%s",ww[i]);
	for(i=0;i<nn-1;i++)
	{
		flag=0;
		for(j=0;j<nn-1-i;j++)
			if(ww[j][0]>ww[j+1][0])
			{
				strcpy(hold,ww[j]);
				strcpy(ww[j],ww[j+1]);
				strcpy(ww[j+1],hold);
				hh=cc[j];
				cc[j]=cc[j+1];
				cc[j+1]=hh;
				flag=1;
			}
			else if(ww[j][0]==ww[j+1][0])
				if(ww[j][1]>ww[j+1][1])
				{
					strcpy(hold,ww[j]);
					strcpy(ww[j],ww[j+1]);
					strcpy(ww[j+1],hold);
					hh=cc[j];
					cc[j]=cc[j+1];
					cc[j+1]=hh;
					flag=1;
				}
				else if(ww[j][1]==ww[j+1][1])
					if(ww[j][2]>ww[j+1][2])
					{
						strcpy(hold,ww[j]);
						strcpy(ww[j],ww[j+1]);
						strcpy(ww[j+1],hold);
						hh=cc[j];
						cc[j]=cc[j+1];
						cc[j+1]=hh;
						flag=1;
					}
		if(flag==0)
		break; 
	}
	for(i=0;i<nn;i++){
		if(ww[i][0]=='\0')
		i++;
		printf("%s %d\n",ww[i],cc[i]);
	}
	return 0;
}

