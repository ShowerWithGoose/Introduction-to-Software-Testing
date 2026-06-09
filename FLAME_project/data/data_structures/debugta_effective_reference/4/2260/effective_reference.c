#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	int i=0;
	int k=0;
	int j;
	int sig=0;
	char cmp[15];
	char ss[1000][15];
	char ww[1000][15];
	int cc[1000];
	char hold[15];
	int hh;
	char c;
	int cnt=0;
	FILE *in;
	for(i=0;i<1000;i++){
		for(k=0;k<15;k++){
			ss[i][k]='\0';
			ww[i][k]='\0';
		}
		cc[i]=0;
	}
	for(i=0;i<15;i++){
		hold[i]='\0';
		cmp[i]='\0';
	}
	i=k=0;
	in=fopen("article.txt","r");
	while((c=fgetc(in))!=EOF){
		if((c<='z'&&c>='a')||(c<='Z'&&c>='A')){
			if(c<='Z'&&c>='A')
				c=c+32;
			ss[i][k]=c;
			k++;
			sig=0;
		}
		else if(((c>=' '&&c<'A')||c=='\n'||c>'z'||(c>'Z'&&c<'a'))&&sig==0){
			i++;
			k=0;
			sig=1;
		}
	}
	fclose(in);
	j=i+1;
	sig=0;
	for(i=0;i<j;i++){
		for(k=0;k<cnt;k++){
			if(strcmp(ss[i],ww[k])==0&&strcmp(ww[k],cmp)!=0){
				sig=1;
				break;
			}
		}
		cc[k]++;
		if(sig==0){
			cnt++;
			strcpy(ww[k],ss[i]);
		}
		sig=0;
		
	}
	//for(i=0;i<nn;i++)
	//	printf("%s",ww[i]);
	for(i=0;i<cnt-1;i++)
	{
		sig=0;
		for(k=0;k<cnt-1-i;k++)
			if(ww[k][0]>ww[k+1][0])
			{
				strcpy(hold,ww[k]);
				strcpy(ww[k],ww[k+1]);
				strcpy(ww[k+1],hold);
				hh=cc[k];
				cc[k]=cc[k+1];
				cc[k+1]=hh;
				sig=1;
			}
			else if(ww[k][0]==ww[k+1][0])
				if(ww[k][1]>ww[k+1][1])
				{
					strcpy(hold,ww[k]);
					strcpy(ww[k],ww[k+1]);
					strcpy(ww[k+1],hold);
					hh=cc[k];
					cc[k]=cc[k+1];
					cc[k+1]=hh;
					sig=1;
				}
				else if(ww[k][1]==ww[k+1][1])
					if(ww[k][2]>ww[k+1][2])
					{
						strcpy(hold,ww[k]);
						strcpy(ww[k],ww[k+1]);
						strcpy(ww[k+1],hold);
						hh=cc[k];
						cc[k]=cc[k+1];
						cc[k+1]=hh;
						sig=1;
					}
		if(sig==0)
		break; 
	}
	for(i=0;i<cnt;i++){
		if(ww[i][0]=='\0')
		i++;
		printf("%s %d\n",ww[i],cc[i]);
	}
	return 0;
}

