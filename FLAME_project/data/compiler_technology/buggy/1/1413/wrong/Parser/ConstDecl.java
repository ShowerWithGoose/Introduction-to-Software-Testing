package Parser;

import Lexer.Token;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/10
 */
public class ConstDecl implements TreeNode{
    private final String value = "<ConstDecl>";
    private Token Const;
    private BType bType;
    private ConstDef constDef;
    private ArrayList<Token> comma;
    private ArrayList<ConstDef> constDefArrayList;
    private Token semicolon;
    public ConstDecl(Token conststring,BType bType,ConstDef constDef,ArrayList<Token> comma,ArrayList<ConstDef> constDefArrayList,Token semicolon)
    {
        this.Const=conststring;
        this.bType=bType;
        this.constDef=constDef;
        this.comma=comma;
        this.constDefArrayList=constDefArrayList;
        this.semicolon=semicolon;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.Const.getType()).append(" ").append(this.Const.getValue()).append("\n");
        sb.append(this.bType.print_tree());
        sb.append(this.constDef.print_tree());
        int len = this.comma.size();
        for (int i = 0; i < len; i++) {
            sb.append(this.comma.get(i).toStringprint());
            sb.append(this.constDefArrayList.get(i).print_tree());
        }
        sb.append(this.semicolon.getType()).append(" ").append(this.semicolon.getValue()).append("\n");
        sb.append(this.value).append("\n");
        return sb.toString();
    }
}
