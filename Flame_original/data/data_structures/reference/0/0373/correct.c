#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main()
{
    char original[114];
    char begin,end;
    gets(original);
    int scan=0,oriLen=strlen(original),gen;
    while(scan<oriLen)
    {
        if(original[scan]=='-')
        {
            begin=original[scan-1];
            end=original[scan+1];
            if(begin<='z' && begin>='a' && end<='z' && end>='a')
            {
                gen=begin+1;
                while(gen<end)
                {
                    printf("%c",gen);
                    gen++;
                }
                scan++;
            }
            if(begin<='Z' && begin>='A' && end<='Z' && end>='A')
            {
                gen=begin+1;
                while(gen<end)
                {
                    printf("%c",gen);
                    gen++;
                }
                scan++;
            }
            if(begin<='9' && begin>='0' && end<='9' && end>='0')
            {
                gen=begin+1;
                while(gen<end)
                {
                    printf("%c",gen);
                    gen++;
                }
                scan++;
            }
            
        }
        printf("%c",original[scan]);
        scan++;
    }
    return 0;
}


