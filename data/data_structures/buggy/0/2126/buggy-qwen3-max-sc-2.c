#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int  main()
{   
    char ch[1000],a,b,n;
    gets(ch); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, 'gets' is not available, leading to compilation errors.]
    int i;
    for(i=0;i!=strlen(ch);i++)
    {
        if(ch[i]=='-')
        {
        a=ch[i-1],b=ch[i+1];
        if(((a>='a'&&a<='z')&&(b>='a'&&b<='z'))||((a>='A'&&a<='Z')&&(b>='A'&&b<='Z'))||((a>=0&&a<=9)&&(b>=0&&b<=9))) // @@ [The conditions (a>=0&&a<=9) and (b>=0&&b<=9) are incorrect because 'a' and 'b' are characters; they should be compared with '0' and '9', e.g., (a>='0' && a<='9'). This logical error causes digit ranges to never match, but the immediate compilation error is due to 'gets'.]
        {
            if(a<b)
            for(n=a+1;n>a&&n<b;n++){
            printf("%c",n);
            }
        }    
        else printf("-");    
        }
        else{
              n=ch[i];
              printf("%c",n);
        }
    }
    return 0;
}