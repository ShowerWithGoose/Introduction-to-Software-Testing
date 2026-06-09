#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[105],s1[105]="0";
    int e=0,i,j,a=1;
    gets(s);
    if(s[0]=='0'){
        a=-1;
        for(i=2;s[i]=='0';i++){
            e++;
        }
        e++;
        s1[0]=s[i];
        i++;
        if(s[i]!=0){
           s1[1]='.';
           for(j=2;s[i]!=0;i++){
               s1[j]=s[i];
               j++;
        }}
    }
    else{
        s1[0]=s[0];
        s1[1]='.';
        for(i=1;s[i]!='.';i++){
            e++;
            s1[i+1]=s[i];
        }
        for(i=i+1,j=i;s[i]!=0;i++){
                s1[j]=s[i];
                j++;}
    }
    printf("%s",s1);
    printf("e");
    printf("%d",e*a);
    return 0;
}



