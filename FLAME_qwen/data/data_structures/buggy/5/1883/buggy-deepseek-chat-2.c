#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct {
    int a,b;
    
}mult[1000],mult1[100],mult2[100],z;
int main(){
    char temp[1000];char num[27];int m1,m2;
    gets(temp);
    int sum=0;
    for(int i=0,key=1;;i++){
        if(temp[i]==' '||temp[i]=='\0'){
            if(key%2==1) mult1[(key+1)/2].a=sum;
            else mult1[(key+1)/2].b=sum;
            key++;
            sum=0;
        }
        else sum=sum*10+temp[i]-'0';
        
        if(temp[i]=='\0') {
            m1=(key-1)/2;
            break;
        }
    }
    gets(temp);
    for(int i=0,key=1;;i++){
        if(temp[i]==' '||temp[i]=='\0'){
            if(key%2==1) mult2[(key+1)/2].a=sum;
            else mult2[(key+1)/2].b=sum;
            key++;
            sum=0;
        }
        else sum=sum*10+temp[i]-'0';
        
        if(temp[i]=='\0') {
            m2=(key-1)/2;
            break;
        }
    }
    int key; // @@ [Error: 'key' is declared again, shadowing the previous 'key' in the for loops, and it is uninitialized, leading to undefined behavior when used as an array index]
    for(int i=1;i<=m1;i++){
        for(int t=1;t<=m2;t++){
            mult[key].a=mult1[i].a*mult2[t].a; // @@ [Error: 'key' is uninitialized, causing undefined behavior]
            mult[key].b=mult1[i].b+mult2[t].b; // @@ [Error: same as above]
            key++;
        }
    }
    key--;
    for(int i=1;i<=key;i++){
        for(int t=i+1;t<=key;t++){
            if(mult[i].b==mult[t].b){
                mult[i].a+=mult[t].a;
                mult[t].a=0;
            }
        }
    }
    for(int i=1;i<=key;i++){
        for(int t=1;t<key;t++){
            if(mult[t].b<mult[t+1].b){
                z=mult[t];
                mult[t]=mult[t+1];
                mult[t+1]=z;
            }
        }
    }
    for(int i=1;i<=key;i++){
        if(mult[i].a!=0){
            printf("%d %d ",mult[i].a,mult[i].b);
        }
    }
}