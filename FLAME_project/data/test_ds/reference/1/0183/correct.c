#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000000],a[50];
    //char before,behind;
    int i,j,n,x;
    gets(s);
    for ( i = 0; i < strlen(s); i++)
    {
    	if(s[i]!='-')
    	{
    		printf("%c",s[i]);
		}
		else
		
        {
            //before=s[i-1];
            //behind=s[i+1];
            if((s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<='z'&&s[i+1]>='a') || (s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<='Z'&&s[i+1]>='A') ||(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<='9'&&s[i+1]>='0'))
            {
            	n=i;
            for ( j= 1; j < s[i+1]-s[i-1]; j++)
            {
                a[j]=s[i-1]+j;
                printf("%c",a[j]);
            }
			}
			else 
			{
				printf("-");
				continue;
			}
            
            
        }
        
        
    }


    return 0;
    

    
}




