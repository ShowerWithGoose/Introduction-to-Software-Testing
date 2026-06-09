package Parser;

/**
 * @Description:
 * @date 2024/10/7
 */
public class Decl implements TreeNode{
    private final String value = "<Decl>";
    private ConstDecl constDecl=null;
    private VarDecl varDecl=null;
    public Decl(ConstDecl constDecl,VarDecl varDecl)
    {
        this.constDecl=constDecl;
        this.varDecl=varDecl;
    }

    @Override
    public String print_tree() {
        StringBuilder sb = new StringBuilder();
        if(varDecl!=null&&constDecl==null)
        {
            sb.append(this.varDecl.print_tree());
        }else if(varDecl==null&&constDecl!=null){
            sb.append(this.constDecl.print_tree());
        }
        return sb.toString();
    }
    //这个不需要单独输出
}
