package Parser;

import Lexer.Token;
import Parser.Exp.Exp;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/13
 */
public class LVal implements TreeNode{
    private final String name = "<LVal>";
    private Token ident;
    private ArrayList<Token> leftBrackets;
    private ArrayList<Exp> exps;
    private ArrayList<Token> rightBrackets;

    public LVal(Token ident,
                ArrayList<Token> leftBrackets,
                ArrayList<Exp> exps,
                ArrayList<Token> rightBrackets) {
        this.ident = ident;
        this.leftBrackets = leftBrackets;
        this.exps = exps;
        this.rightBrackets = rightBrackets;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.ident.toStringprint());
        if(!leftBrackets.isEmpty()){
            sb.append(this.leftBrackets.get(0).toStringprint());
            sb.append(this.exps.get(0).print_tree());
            sb.append(this.rightBrackets.get(0).toStringprint());
        }
        sb.append(this.name).append("\n");
        return sb.toString();
    }
}
