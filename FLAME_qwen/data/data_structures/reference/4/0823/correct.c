#include<stdio.h>
#include<string.h>
#include<math.h>
char a[100][1000];
char b[1000][20];
int rec[1000];
char c[20];
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	int i=0,num,j,i1,j1,tmp,l;
	while(fgets(a[i],1000,in)!=NULL)
	i++;
	num=i;
	for(i=0,i1=0;i<=num-1;i++){
		l=strlen(a[i]);
		if(a[i][0]<='z'&&a[i][0]>='a')
		    i1+=0;
		else if(a[i][0]<='Z'&&a[i][0]>='A')
		    i1+=0;
		else 
		    i1--;
		for(j=0,j1=0;j<l;j++){
			if(a[i][j]<='Z'&&a[i][j]>='A'){
				a[i][j]-='A'-'a';
				b[i1][j1]=a[i][j];
				j1++;
			}
			else if(a[i][j]<='z'&&a[i][j]>='a'){
				b[i1][j1]=a[i][j];
				j1++;
			}
			else{
				if((a[i][j+1]<='z'&&a[i][j+1]>='a')||(a[i][j+1]<='Z'&&a[i][j+1]>='A')){
					i1++;
					j1=0;
				}
			}
		}
		i1++;
	}
	for(i=0;i<=i1;i++)
	rec[i]=1;
	for(i=0;i<=i1;i++){
		if(b[i][0]=='0')
		continue;
		for(j=0;j<=i1;j++){
			if(strcmp(b[i],b[j])==0&&i!=j){
			    rec[i]++;
			    b[j][0]='0';
			}
		}
	}
	for(i=0;i<=i1;i++){
		if(b[i][0]=='0')
		continue;
		for(j=0;j<=i1;j++){
			if(b[j][0]=='0')
		    continue;
			if(strcmp(b[i],b[j])<0){
				strcpy(c,b[j]);
				strcpy(b[j],b[i]);
				strcpy(b[i],c);
				tmp=rec[i];
				rec[i]=rec[j];
				rec[j]=tmp;
			}
		}
	}//problem
	for(i=0;i<=i1;i++){
		if(b[i][0]!='0'&&b[i][0]!='\0')
		printf("%s %d\n",b[i],rec[i]);
	}
	fclose(in);
	return 0;
}


