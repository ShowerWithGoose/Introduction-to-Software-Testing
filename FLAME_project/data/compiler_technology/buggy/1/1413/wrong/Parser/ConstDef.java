package Parser;

import Lexer.Token;
import Parser.Exp.ConstExp;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/11
 */
public class ConstDef implements TreeNode{
    private final String value="<ConstDef>";
    private Token Ident;
    private ArrayList<Token> leftBrack;
    private ArrayList<ConstExp>  constExpArrayList;
    private ArrayList<Token> rightBrack;
    private Token equal;
    private ConstInitVal constInitVal;
    public ConstDef(Token ident,ArrayList<Token> leftBrack,ArrayList<ConstExp> constExpArrayList,ArrayList<Token> rightBrack,Token equal,ConstInitVal constInitVal){
        this.Ident=ident;
        this.leftBrack=leftBrack;
        this.constInitVal=constInitVal;
        this.rightBrack=rightBrack;
        this.equal=equal;
        this.constExpArrayList=constExpArrayList;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.Ident.getType()).append(" ").append(this.Ident.getValue()).append("\n");
        if(!leftBrack.isEmpty()){
            sb.append(leftBrack.get(0).getType()).append(" ").append(leftBrack.get(0).getValue()).append("\n");
            sb.append(this.constExpArrayList.get(0).print_tree());
            sb.append(rightBrack.get(0).getType()).append(" ").append(rightBrack.get(0).getValue()).append("\n");
        }
        sb.append(this.equal.getType()).append(" ").append(this.equal.getValue()).append("\n");
        sb.append(this.constInitVal.print_tree());
        sb.append(this.value).append("\n");
        return sb.toString();
    }
    //这个要输出的，所以要写输出
}
