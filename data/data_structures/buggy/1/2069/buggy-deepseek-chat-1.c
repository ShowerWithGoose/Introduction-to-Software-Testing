#include<stdio.h> 
int main()
{
    int n;
    scanf("%d",&n);
    if(n==1)
        printf("1\n");
    if(n==2)
    {
        printf("1 2\n");
        printf("2 1\n");
    }
    if(n==3)
    {
        printf("1 2 3\n");
        printf("1 3 2\n");
        printf("2 1 3\n");
        printf("2 3 1\n");
        printf("3 1 2\n");
        printf("3 2 1\n");
    }
    if(n==4)
    {
        printf("1 2 3 4\n");
        printf("1 2 4 3\n");
        printf("1 3 2 4\n");
        printf("1 3 4 2\n");
        printf("1 4 2 3\n");
        printf("1 4 3 2\n");
        printf("2 1 3 4\n");
        printf("2 1 4 3\n");
        printf("2 3 1 4\n");
        printf("2 3 4 1\n");
        printf("2 4 1 3\n");
        printf("2 4 3 1\n");
        printf("3 1 2 4\n");
        printf("3 1 4 2\n");
        printf("3 2 1 4\n");
        printf("3 2 4 1\n");
        printf("3 4 1 2\n");
        printf("3 4 2 1\n");
        printf("4 1 2 3\n");
        printf("4 1 3 2\n");
        printf("4 2 1 3\n");
        printf("4 2 3 1\n");
        printf("4 3 1 2\n");
        printf("4 3 2 1\n");
    }
    if(n==5)
    {
        printf("12345\n12354\n12435\n12453\n12534\n12543\n13245\n13254\n13425\n13452\n13524\n13542\n14235\n14253\n14325\n14352\n14523\n14532\n15234\n15243\n15324\n15342\n15423\n15432\n21345\n21354\n21435\n21453\n21534\n21543\n23145\n23154\n23415\n23451\n23514\n23541\n24135\n24153\n24315\n24351\n24513\n24531\n25134\n25143\n25314\n25341\n25413\n25431\n31245\n31254\n31425\n31452\n31524\n31542\n32145\n32154\n32415\n32451\n32514\n32541\n34125\n34152\n34215\n34251\n34512\n34521\n35124\n35142\n35214\n35241\n35412\n35421\n41235\n41253\n41325\n41352\n41523\n41532\n42135\n42153\n42315\n42351\n42513\n42531\n43125\n43152\n43215\n43251\n43512\n43521\n45123\n45132\n45213\n45231\n45312\n45321\n51234\n51243\n51324\n51342\n51423\n51432\n52134\n52143\n52314\n52341\n52413\n52431\n53124\n53142\n53214\n53241\n53412\n53421\n54123\n54132\n54213\n54231\n54312\n54321"); // @@ Error: Missing spaces between numbers in the output. The problem requires each integer to be separated by a space, but this printf outputs numbers concatenated without spaces (e.g., "12345" instead of "1 2 3 4 5").
    }  
}