package Parser;

import Lexer.Token;
import Parser.Exp.ConstExp;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/12
 */
public class VarDef implements TreeNode{
    private String value="<VarDef>";
    private Token Ident;
    private ArrayList<Token> leftBrackets;
    private ArrayList<ConstExp> constExpArrayList;
    private ArrayList<Token> rightBrackets;
    private ArrayList<Token> equal;
    private ArrayList<InitVal> initValArrayList;

    public VarDef(Token ident, ArrayList<Token> leftBrackets, ArrayList<ConstExp> constExpArrayList, ArrayList<Token> rightBrackets, ArrayList<Token> equal, ArrayList<InitVal> initValArrayList) {
        Ident = ident;
        this.leftBrackets = leftBrackets;
        this.constExpArrayList = constExpArrayList;
        this.rightBrackets = rightBrackets;
        this.equal = equal;
        this.initValArrayList = initValArrayList;
    }

    @Override
    public String print_tree() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.Ident.toStringprint());
        if(!leftBrackets.isEmpty()){
            sb.append(leftBrackets.get(0).toStringprint());
            sb.append(constExpArrayList.get(0).print_tree());
            sb.append(rightBrackets.get(0).toStringprint());
        }
        if(!equal.isEmpty()){
            sb.append(this.equal.get(0).toStringprint());
            sb.append(this.initValArrayList.get(0).print_tree());
        }
        sb.append(this.value + "\n");
        return sb.toString();
    }
}
