#include <stdio.h>
#include <string.h>

void  expand(char s1[ ],char s2[ ]);

int main()
{
    char s1[1000],s2[1000];

    gets(s1);
    
    int a,i,j=0;
    
    a=strlen(s1);
    for(i=0;i<a;i++)
    {
    	if(s1[i] != ' ') s1[j]=s1[i];
    	j++;
	}
	s1[j]='\0';
    
    expand(s1,s2);
    puts(s2);
    
    return 0;
}

void  expand(char s1[], char s2[])
{
    int i,j,c,k;    //   k为标兵变量 
    i = j = 0;
    while(s1[i] != '\0'){
        s2[j++] = s1[i];
        
        k=0;
        if(s1[i]>='a' && s1[i+2]<='z') k=1;
        if(s1[i]>='A' && s1[i+2]<='Z') k=1;
        if(s1[i]>='0' && s1[i+2]<='9') k=1;
        
        if(s1[i+1] == '-' && s1[i] < s1[i+2] && k==1){
            for(c = s1[i]+1; c < s1[i+2]; c++,j++)
                s2[j] = c;
            i = i+2;
        }
        else i++;
     }
    s2[j] = '\0';
}




