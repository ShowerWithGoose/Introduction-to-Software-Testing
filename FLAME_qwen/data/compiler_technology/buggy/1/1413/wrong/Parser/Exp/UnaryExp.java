package Parser.Exp;

import Lexer.Token;
import Parser.Func.FuncRParams;
import Parser.TreeNode;
import Parser.UnaryOp;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/12
 */
public class UnaryExp implements TreeNode {
    private final String value="<UnaryExp>";
    private int flag;
    private PrimaryExp primaryExp;
    private Token ident;
    private Token leftParenthesis;
    private FuncRParams funcRParams;
    private Token rightParenthesis;
    private ArrayList<UnaryOp> unaryOpArrayList;
    private UnaryExp unaryExp;

    public UnaryExp(int flag, PrimaryExp primaryExp, Token ident, Token leftParenthesis, FuncRParams funcRParams, Token rightParenthesis, ArrayList<UnaryOp> unaryOpArrayList, UnaryExp unaryExp) {
        this.flag = flag;
        this.primaryExp = primaryExp;
        this.ident = ident;
        this.leftParenthesis = leftParenthesis;
        this.funcRParams = funcRParams;
        this.rightParenthesis = rightParenthesis;
        this.unaryOpArrayList = unaryOpArrayList;
        this.unaryExp = unaryExp;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        if(this.flag==1){
            sb.append(this.primaryExp.print_tree());
        }else if(flag==2){
            sb.append(this.ident.toStringprint());
            sb.append(this.leftParenthesis.toStringprint());
            if(this.funcRParams!=null){
                sb.append(this.funcRParams.print_tree());
            }
            sb.append(this.rightParenthesis.toStringprint());
        }else if(flag==3){
            int cnt=unaryOpArrayList.size();
            for(int i=0;i<cnt;i++){
                sb.append(unaryOpArrayList.get(i).print_tree());
            }
            sb.append(unaryExp.print_tree());
        }
        sb.append(this.value).append("\n");
        return sb.toString();
    }
}
