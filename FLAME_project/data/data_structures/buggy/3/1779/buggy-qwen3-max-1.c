#include<stdio.h>
 #include<string.h>

 int main()
 {
     char s[100];
     gets(s);
     int n=strlen(s);
     int q=0,i=0,p=0;
    while(s[i]!='.') @@ // This loop assumes there is always a '.' in the input, but if the input has no decimal point (though problem says it does), it would cause undefined behavior. However, more critically, for input "0.9", q becomes 1 (since '0' is before '.'), so q==1 and s[0]=='0', so it goes to the else block.
    {
        q++;
        i++;
    }
     if(q>1)
     {
         printf("%c.",s[0]);
     for(int i=1;i<n;i++)
     {
         if(s[i]!='.')
         {
         printf("%c",s[i]);    
        }
     }
         printf("e");
         printf("%d",q-1);
     }
     else if(q==1&&s[0]!='0') @@ // For input "0.9", q==1 but s[0]=='0', so this condition fails and it goes to else block. This is correct logic-wise, but the else block is flawed.
     {
         printf("%s",s);
         printf("e0");
     }

     else
     for(int i=3;i<n;i++) @@ // Error: assumes the first non-zero digit is at position >=3 (i.e., "0.0..."), but for "0.9", the first digit after '.' is at index 2 (s[2]=='9'), so i starts at 3 which skips it. Also, p counts leading zeros after '.', but starts checking from i=3, missing s[2].
     {
         if(s[i]=='0')
         {
         p++;    
        }
        else
        {
            if(i==n-1)
            printf("%c",s[p+3]); @@ // Error: uses p+3 as index, but p is count of zeros starting from i=3, not from after decimal. For "0.9", this block never executes because loop starts at i=3 and n=3 ("0.9" has indices 0:'0',1:'.',2:'9'), so loop doesn't run at all → no output.
            else
                printf("%c.",s[p+3]);
        printf("%s",s+p+4);
        printf("e-%d",p+2);
        break;
        }
     }
     return 0;
     
}