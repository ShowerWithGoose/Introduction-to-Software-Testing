#include<stdio.h>
#include<string.h>
char c[100000000];
int main()
{
    int o=0,i=0,t=0,l;
    while(scanf("%c",&c[i])!=EOF) // @@ [This loop incorrectly increments i only when the character is not '.', causing '.' to be overwritten in the next iteration and leading to incorrect storage of input. Also, it reads newline as part of input which breaks logic.]
    {
        if(c[i]=='.')
        t=i;
        else
        i++;
    }
    i--; // @@ [This decrements i after reading EOF, but since the loop condition uses !=EOF and scanf returns number of items matched, this logic is flawed; also newline remains in buffer and affects i.]
    if(c[0]=='0')
    {
        for(l=1;c[l]=='0';l++); // @@ [If input is "0.0...", this skips zeros after decimal, but l may go out of bounds if all are zeros or if string ends unexpectedly.]
        if(i==(l+1)) // @@ [Comparison assumes i points to last valid digit, but due to incorrect input reading (including newline), i is off-by-one.]
        printf("%ce-%d",c[l],l);
        else
        {
            int k=l;
            printf("%c.",c[l]);
            for(l++;l<i;l++) // @@ [Loop condition l<i excludes the last character, which may be a significant digit if newline was stored at i.]
            printf("%c",c[l]);
            printf("e-%d",k);
        }
    }
    else
    {
        printf("%c.",c[0]);
        for(l=1;l<i;l++) // @@ [Again, l<i skips the last character; also, digits after '.' are printed without skipping the '.' itself, but '.' was stored at position t and may still be in the array.]
        printf("%c",c[l]);
        printf("e%d",t-1); // @@ [t stores index of '.', but if input reading included newline or extra characters, t may be incorrect. Also, if there's no decimal point (though problem says there is), this fails.]
    }
    return 0;
}