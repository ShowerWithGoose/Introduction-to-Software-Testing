#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10000];
int main()
{
    scanf("%s",&s);

    for(int i=0;i<strlen(s);i++){
        int a=0;
        if(s[i]=='-'&&s[i-2]=='-')i--;
        if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z')a+=0;else a+=1;
        if(s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z')a+=0;else a+=1;
        if(s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9')a+=0;else a+=1;
       
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){

            int k=i;
            
            for(int j=0;j<=(s[i+2]-s[i]);j++){
                
                if(s[k-1]=='-'){
                    j++;
                    k++;
                }

                printf("%c",s[i]+j);
            }i+=2;

        } else printf("%c",s[i]);

    }
    

    system("pause");
    return 0;
}



