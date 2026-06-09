#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define LL long long
#define DB double
#define FOR(X,Y,Z)  for(int X = Y;X<Z;X++)
LL a0[200],p0[200],a1[200],p1[200],a2[200],p2[200],a3[200],p3[200],eda[200],edp[200];  
void add(LL A1[],LL P1[],LL A2[],LL P2[],int l1,int l2){
    int i=0,j=0,k=0;
    while(i<l1||j<l2){
    if(P1[i]>P2[j]){
        eda[k] = A1[i];
        edp[k] = P1[i];
        i++; k++;
    }
    else if(P1[i]<P2[j]){
        eda[k] = A2[j];
        edp[k] = P2[j];
        j++; k++;
    }
    else{
        eda[k] = A2[j]+A1[i];
        edp[k] = P1[i];
        k++;i++;j++;
    }
    }
    
}   
char str1[200],str2[200];
int main(){
    //freopen(".in","r",stdin);
    int i = 0;
    gets(str1);
    gets(str2);
    int n1=0,n2=0;
    for(int i = 0;i<strlen(str1);i++){
        if(str1[i]==' ') n1++;
    }
    n1 = (n1+1)/2;
    int j = 0;
    for(int i = 0;i<n1;i++){
        while(str1[j]!=' '){
            a1[i]*=10;
            a1[i] += str1[j]-'0';
            j++;
        }
        j++;
        while(str1[j]!=' '&&str1[j]!='\0'){
            p1[i]*=10;
            p1[i] += str1[j]-'0';
            j++;
        }
        j++;
    }
//
    for(int i = 0;i<strlen(str2);i++){
        if(str2[i]==' ') n2++;
    }
    n2 = (n2+1)/2;
    int j2 = 0;
    for(int i = 0;i<n2;i++){
        while(str2[j2]!=' '){
            a2[i]*=10;
            a2[i] += str2[j2]-'0';
            j2++;
        }
        j2++;
        while(str2[j2]!=' '&&str2[j2]!='\0'){
            p2[i]*=10;
            p2[i] += str2[j2]-'0';
            j2++;
        }
        j2++;
    }
    /*for(int i = 0;i<n1;i++)
    printf("%d %d ",a1[i],p1[i]);
    putchar('\n');
    for(int i = 0;i<n2;i++)
    printf("%d %d ",a2[i],p2[i]);
    putchar('\n');*/
    memset(a0,0,sizeof(a0));
     memset(p0,0,sizeof(p0));
     for(int i = 0 ;i<n2;i++){
         for(int j = 0;j<n1;j++){
             a3[j] = a1[j]*a2[i];
             p3[j] = p1[j]+p2[i];
         }
         memset(eda,0,sizeof(a0));
         memset(edp,0,sizeof(p0));
         add(a0,p0,a3,p3,90,n1);
         //printf("%d\n",l);
         memcpy(a0,eda,sizeof(eda));
         memcpy(p0,edp,sizeof(edp));
         memset(a3,0,sizeof(a3));
         memset(p3,0,sizeof(p3));
     }
     for(int i = 0;i<90;i++){
         if(eda[i]==0)
         continue;
        printf("%lld %lld ",eda[i],edp[i]);
    }
    return 0;
}

