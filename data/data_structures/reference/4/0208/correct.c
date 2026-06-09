#include<stdio.h>
#include<string.h>
#include <ctype.h> 
char s[1000][100];
int cmp(const void *p1,const void *p2){
	return strcmp((char*)p1,(char*)p2);
}
int main(){
	int i,j=0;
	int n=0;
	char cc;
	FILE *fp=fopen("article.txt","r");
	if(fp==NULL){
		return 0;
	}
	cc=fgetc(fp);
	while(cc!=EOF){
		if((cc>='a'&&cc<='z')||(cc>='A'&&cc<='Z')){
			s[i][j]=cc;
			j++;
		}
		else if(ispunct(cc) || isspace(cc)){
			s[i][j]='\0';
			j=0;
			i++;
		}
		cc=fgetc(fp);
	}
	n=i;
	for(i=0;i<n;i++){
		for(j=0;j<strlen(s[i]);j++){
			if(s[i][j]>='A'&&s[i][j]<='Z'){
				s[i][j]=s[i][j]+('a'-'A');
			}
		}
	}
	qsort(s,n,sizeof(char)*100,cmp);
	int num[100] = {0}, flag = 0;
    for (i = 0; i < n; i++)
    {
        flag = 0;
        num[i] = 1;
        for(j = i + 1; j < n; j++)
        {
            if (strcmp(s[i],s[j])==0)
            {
                num[i]++;
                s[j][0]='\0';
                flag=1;
            }

            if (s[j][0]=='\0')
            {
                continue;
            }

            else
            {
                if (flag == 1)
                {
                    i = j - 1;
                }
                break;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (s[i][0] != '\0')
        {
            printf("%s %d\n", s[i], num[i]);
        }
    }
	fclose(fp);
	return 0;
} 

