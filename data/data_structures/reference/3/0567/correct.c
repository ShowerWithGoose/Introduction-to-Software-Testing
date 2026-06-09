#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
void efront(char a[],int);
void eafter(char a[],int);
// 0.02 
int main(){
    int i,j1,j2,len;
    char point[105]={0};
    scanf("%s",point);
    len = strlen(point);
    efront(point,len);
    printf("e");
    eafter(point,len);
}

void efront(char a[],int len){
    int i,j,rec[105]={0},lock = 0;
    for(i = 0,j = 0;i < len;i++){
        if((a[i]<='9'&&a[i]>'0'&&lock == 0)||(a[i]<='9'&&a[i]>='0'&&lock == 1)){
            rec[j] = a[i]-'0';
            j++;
            lock = 1;
        }
    }
    if(j == 1) printf("%d",rec[0]);
    else{
        printf("%d",rec[0]);
        printf(".");
        for(i = 1;i<j;i++) printf("%d",rec[i]);
    }
}
//43.51   0.0455
void eafter(char a[],int len){
    int i = 0,indpoint,indbe,br = 0;
    for(i = 0;i < len;i++){
        if(a[i] == '.')
        indpoint = i;
        else if(a[i]<='9'&&a[i]>'0'&&br == 0){
            br++;
            indbe = i;
        }
    }
    printf("%d\n",indpoint > indbe?indpoint-indbe-1:indpoint-indbe);
}
