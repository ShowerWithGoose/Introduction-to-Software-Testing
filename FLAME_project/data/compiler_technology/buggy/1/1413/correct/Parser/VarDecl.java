package Parser;

import Lexer.Token;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/7
 */
public class VarDecl implements TreeNode{
    private String value="<VarDecl>";
    private BType bType;
    private VarDef varDef;
    private ArrayList<Token> commas;
    private ArrayList<VarDef> varDefArrayList;
    private Token semicolon;
    public VarDecl(BType bType,VarDef varDef,ArrayList<Token> commas,ArrayList<VarDef> varDefArrayList,Token semicolon){
        this.bType=bType;
        this.varDef=varDef;
        this.commas=commas;
        this.varDefArrayList=varDefArrayList;
        this.semicolon=semicolon;
    }

    @Override
    public String print_tree() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.bType.print_tree());
        sb.append(varDef.print_tree());
        for(int i=0;i<this.commas.size();i++){
            sb.append(commas.get(i).toStringprint());
            sb.append(varDefArrayList.get(i).print_tree());
        }
        sb.append(this.semicolon.toStringprint());
        sb.append(this.value + "\n");
        return sb.toString();
    }
}
