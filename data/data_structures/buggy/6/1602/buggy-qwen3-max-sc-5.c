#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0};
    memset(st,0,sizeof(st));
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++); @@ [This loop assumes that the stack is stored contiguously from index 0 and uses 0 to mean "empty", but after popping (setting an element to 0), gaps can appear. Thus, this method of finding the next free slot is incorrect—it may overwrite existing elements or skip valid empty slots in the middle.]
            
            if(i==100)printf("error ");
            else
            scanf("%lld ",&st[i]); @@ [Using "%lld " with trailing space can cause input parsing issues; the space consumes any whitespace including newlines, potentially interfering with subsequent reads. Also, storing at index i found by the flawed loop above leads to incorrect push behavior.]
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); @@ [This attempts to find the top by scanning from the end for a non-zero value, but the stack isn't necessarily filled from the end—it's being managed as if it grows from the front. This logic contradicts the push logic and will fail to find the actual top after mixed operations.]
            
            if(j==-1)printf("error ");
                else{
                printf("%lld ",st[j]);
                st[j]=0;} @@ [Setting st[j]=0 marks it as empty, but this creates holes. Combined with the push logic that scans from index 0 for first zero, future pushes may insert in the middle, breaking stack order (LIFO).]
            
        }
        else if(a==-1){
            return 0;
        }
        
    }
return 0;
}