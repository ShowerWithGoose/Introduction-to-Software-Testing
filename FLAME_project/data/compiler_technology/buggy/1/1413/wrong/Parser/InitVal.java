package Parser;

import Lexer.Token;
import Parser.Exp.Exp;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/13
 */
public class InitVal implements TreeNode{
    private final String value="<InitVal>";
    private int flag;
    private Exp exp;
    private Token leftBrace;
    private Exp exp2;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    private Token rightBrace;
    private Token stringConst;

    public InitVal(int flag, Exp exp, Token leftBrace, Exp exp2, ArrayList<Token> commas, ArrayList<Exp> exps, Token rightBrace, Token stringConst) {
        this.flag = flag;
        this.exp = exp;
        this.leftBrace = leftBrace;
        this.exp2 = exp2;
        this.commas = commas;
        this.exps = exps;
        this.rightBrace = rightBrace;
        this.stringConst = stringConst;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        if(this.flag==1){
            sb.append(this.exp.print_tree());
        }else if(flag==2){
            sb.append(this.leftBrace.toStringprint());
            if(exp2!=null){
                sb.append(exp2.print_tree());
                for(int i=0;i<commas.size();i++)
                {
                    sb.append(this.commas.get(i).toStringprint());
                    sb.append(this.exps.get(i).print_tree());
                }
                sb.append(this.rightBrace.toStringprint());
            }else {
                sb.append(rightBrace.toStringprint());
            }
        }else if(flag==3){
            sb.append(this.stringConst.toStringprint());
        }
        sb.append(this.value).append("\n");
        return sb.toString();
    }
}
