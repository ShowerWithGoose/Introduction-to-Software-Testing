package Parser.Exp;

import Lexer.Token;
import Parser.CharacterClass;
import Parser.Exp.Exp;
import Parser.LVal;
import Parser.NumberClass;
import Parser.TreeNode;

/**
 * @Description:
 * @date 2024/10/13
 */
public class PrimaryExp implements TreeNode {
    private final String value="<PrimaryExp>";

    private int flag;
    private Token leftParentheses;
    private Exp exp;
    private Token rightParentheses;
    private LVal lVal;
    private NumberClass number;
    private CharacterClass character;

    public PrimaryExp(int flag, Token leftParentheses, Exp exp, Token rightParentheses, LVal lVal, NumberClass number, CharacterClass character) {
        this.flag = flag;
        this.leftParentheses = leftParentheses;
        this.exp = exp;
        this.rightParentheses = rightParentheses;
        this.lVal = lVal;
        this.number = number;
        this.character = character;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        if(flag==1){
            sb.append(this.leftParentheses.toStringprint());
            sb.append(this.exp.print_tree());
            sb.append(this.rightParentheses.toStringprint());
        }else if(flag==2){
            sb.append(this.lVal.print_tree());
        }else if(flag==3){
            sb.append(this.number.print_tree());
        }else if(flag==4){
            sb.append(this.character.print_tree());
        }
        sb.append(this.value).append("\n");
        return sb.toString();
    }
}
