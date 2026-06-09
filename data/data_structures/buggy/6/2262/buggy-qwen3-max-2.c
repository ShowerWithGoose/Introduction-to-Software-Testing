#include<stdio.h>


int main()
{
    int a;
    while(~scanf("%d",&a)) // @@ [The condition `~scanf(...)` is incorrect for detecting end-of-input. `scanf` returns the number of successfully read items (1 here) on success, EOF on failure. `~EOF` is not 0, so the loop may not terminate properly. Also, problem requires processing stack operations (1, 0, -1), but this code just echoes all input integers without implementing stack logic.]
    printf("%d ",a); // @@ [This blindly prints every input integer, which does not match the problem's requirement to only print popped elements or "error". The entire logic for handling push/pop operations and maintaining a stack is missing.]
    return 0;
}