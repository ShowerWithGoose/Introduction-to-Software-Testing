#include <stdio.h>
#include <string.h>

int main()
{
    char sl[999]={};
    char sc[999]={};
    int cd,dian,j,i=0,m=0;
    gets(sl);
    cd=strlen(sl);
    for(i=0;i<cd;i++)
    {
        if(sl[i]=='.')
        {
            dian=i;
            break;
        }
    }
	if(dian>=2)
    {
        sc[0]=sl[0];
        sc[1]='.';
        for(i=1,m=2;i<cd;i++)
        {
            if(sl[i]!='.')
            {
                sc[m]=sl[i];
                m++;
            }
        }
        for(i=0;i<cd;i++){
        	printf("%c",sc[i]);
		}
        printf("e%d",dian-1);
    }
    else
    {
        if(sl[0]=='0')
        {
            for(i=2;i<cd;i++)
            {
                j=i;
				if(sl[i]!='0') break;
            }
            sc[0]=sl[j];
            if(j!=(cd-1))
            {
                sc[1]='.';
                for(i=j+1,m=2;i<cd;i++,m++)
                    sc[m]=sl[i];
                    printf("%se-%d",sc,j-1);
            }
            else{
            for(i=0,m=1;i<m;i++){
			   printf("%c",sc[i]);
			 }
                
                printf("e-%d",j-1);
			}
                
        }
        else
        {
            printf("%se0",sl);
        }
    }
    
}

