#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10000];

int main()
{
    scanf("%s",&s);

    for(int i=0;i<strlen(s);i++){
        int a=0;
        if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z')a+=0;else a+=1; // @@ [Incorrect logic: 'a' is incremented even when condition is true due to flawed design; also, this line doesn't check s[i+1] == '-', and accesses s[i+2] without ensuring i+2 is within bounds]
        if(s[i]>='A'&&s[i+2]<='Z'&&s[i]>='A'&&s[i+2]<='Z')a+=0;else a+=1; // @@ [Condition is malformed: should be s[i] <= 'Z', not s[i+2] <= 'Z' twice; also missing bounds check for i+2]
        if(s[i]>='0'&&s[i+2]<='9'&&s[i]+2>='0'&&s[i+2]<='9')a+=0;else a+=1; // @@ [Nonsensical condition: s[i]+2 >= '0' is always true for digits; also missing proper digit range check for s[i]]
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){ // @@ [Bounds check i+2 < strlen(s) is placed too late—previous lines already accessed s[i+2] potentially out of bounds]
            
            char put=s[i];

            for(int j=0;j<=s[i+2]-s[i];j++){
                printf("%c",put+j);
            }i+=2;


        } else printf("%c",s[i]);

    }
    

    system("pause");
    return 0;
}