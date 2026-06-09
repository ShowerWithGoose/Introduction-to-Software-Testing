#include <stdio.h>
#include <string.h>
int f[10000][2],g[10000][2],c[10000]={-1},d[10000]={-1},multiply[10000][2],cnt=-1;
char s[100000],t[100000],*add1[10000],*add2[10000];
int assign(char *a){
	int num=0,i;
	for(i=0;a[i]!='\0';i++){
		num*=10;
		num+=a[i]-'0';
	}
	return num;
}
int comp(const void *a,const void *b){
	return *(int *)b - *(int *)a;
}
void clean(int x){
	int i;
	for(i=x;i<cnt;i++){
		multiply[i][0]=multiply[i+1][0];
		multiply[i][1]=multiply[i+1][1];
	}
	--cnt;
}
int main(){
	int i,j,len,num1=0,num2=0,count1=0,count2=0;
	gets(s);
	gets(t);
	add1[num1]=strtok(s," ");
	while(add1[num1]!=NULL){
		add1[++num1]=strtok(NULL," ");
	}
	add2[num2]=strtok(t," ");
	while(add2[num2]!=NULL){
		add2[++num2]=strtok(NULL," ");
	}	
	for(i=0;i<=num1-2;i+=2){
		f[++count1][0]=assign(add1[i]);
		f[count1][1]=assign(add1[i+1]);
	}
	for(i=0;i<=num2-2;i+=2){
		g[++count2][0]=assign(add2[i]);
		g[count2][1]=assign(add2[i+1]);
	}  
	for(i=1;i<=count1;i++){
		for(j=1;j<=count2;j++){
			multiply[++cnt][0]=f[i][1]+g[j][1];
			multiply[cnt][1]=f[i][0]*g[j][0];
		}
	}	
	qsort(multiply,cnt+1,sizeof(multiply[0]),comp);
	for(i=0;i<cnt;i++){
		for(j=i+1;j<=cnt;j++){
			if(multiply[i][0]==multiply[j][0]){
				multiply[i][1]+=multiply[j][1];
				clean(j);
				--j;
			}
		}
	}
	for(i=0;i<=cnt;i++)
	    if(multiply[i][1])
	        printf("%d %d ",multiply[i][1],multiply[i][0]);
    return 0;
}


