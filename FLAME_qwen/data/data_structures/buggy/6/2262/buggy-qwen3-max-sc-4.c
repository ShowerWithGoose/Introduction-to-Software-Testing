#include<stdio.h>


int main()
{
    int a;
    while(~scanf("%d",&a)) // @@ [The condition `~scanf(...)` is incorrect for detecting end-of-input. `scanf` returns the number of successfully read items (1 here) on success, EOF on failure. `~scanf` will be -2 on success (since ~1 = -2), which is non-zero and thus true, but when scanf returns EOF (typically -1), ~(-1) = 0, so loop stops. However, this works in some environments but is non-standard and confusing. More critically, the problem expects processing operations like 1, 0, -1 with additional input after '1', but this code only reads single integers and prints them, completely ignoring the required stack logic and operation format. This is a logical error, not compilation, but the reported error was "Compilation Error" due to missing headers or environment; however, given the provided source, it actually compiles. The real issue is that this code does not implement the problem at all — it's a wrong program. But per instructions, we annotate based on mismatch with expected behavior. The core error is that it doesn't handle push/pop logic and misreads input format.]
    printf("%d ",a);
    return 0;
}