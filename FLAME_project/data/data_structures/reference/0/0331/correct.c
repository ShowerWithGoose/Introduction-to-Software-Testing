//
//  main.c
//  data str
//
//  Created by  on 2022/3/3.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, const char * argv[]) {
    char str[1000],str2[2000];
    int i,j;
    char c;
    gets(str);
    for (i=j=0; str[i]!='\0'; i++,j++) {
        if (str[i]=='-') {
            if (str[i+1]>str[i-1]) {
                if (str[i-1]>='0'&&str[i]-1<='9'&&str[i+1]>='0'&&str[i+1]<='9') {
                    for (c=str[i-1]+1; c!=str[i+1]; c++) {
                        str2[j]=c;j++;
                    }
                    i++;
                }
                
                else if (str[i-1]>='a'&&str[i]-1<='z'&&str[i+1]>='a'&&str[i+1]<='z')
                {
                    for (c=str[i-1]+1; c!=str[i+1]; c++) {
                        str2[j]=c;j++;
                    }
                    i++;
                }
                else if (str[i-1]>='A'&&str[i]-1<='Z'&&str[i+1]>='A'&&str[i+1]<='Z')
                {
                    for (c=str[i-1]+1; c!=str[i+1]; c++) {
                        str2[j]=c;j++;
                    }
                    i++;
                }
            }
        }
        str2[j]=str[i];
    
    }
    str2[j]='\0';
    printf("%s",str2);
    
    return 0;
}



