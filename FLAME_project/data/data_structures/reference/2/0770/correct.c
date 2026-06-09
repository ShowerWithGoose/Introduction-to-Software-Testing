#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
char in[999999]="", sym[999999]="";
int num[9999999]={0}; 
void Sdel(char *);
int main(){
    gets(in);
    Sdel(in);
	int j=0, k=0;	
	for(int i=0; i<strlen(in); i++){
		if('0'<=in[i]&&in[i]<='9'){
			int wei=1;
			while('0'<=in[i+wei] && in[i+wei]<='9')
				wei++;
			sscanf(in+i,"%d", &num[j++]);
			i+=wei-1;
		}
		else if('0'>in[i] || '9'<in[i])
			sym[k++] = in[i];
	}
	for(int i=0; i<k; i++){
		if(sym[i] == '-'){
			num[i+1] = 0-num[i+1];
			sym[i] = '+';
		}
	}
	for(int i=0; i<k; i++){
		if(sym[i] == '*'){
			num[i+1] = num[i] * num[i+1];
			num[i] = 0;
		}
		else if(sym[i] == '/'){
			num[i+1] = num[i] / num[i+1];
			num[i] = 0;
		}
	}
	int sum=0;
	for(int i=0; i<=j; i++)
		sum += num[i];
	printf("%d", sum);
    return 0;
}
void Sdel(char *a){
    int j=0;
    char *p= NULL;
    p = (char *)malloc(sizeof(char)*strlen(a)+1);
    for(int i=0; i<strlen(a); i++){
        if(*(a+i) == ' ' || *(a+i)=='=')    continue;
        *(p+j) = *(a+i);
        j++;
    }
    *(p+j) = '\0';
    strcpy(a,p);
    free(p);
}

