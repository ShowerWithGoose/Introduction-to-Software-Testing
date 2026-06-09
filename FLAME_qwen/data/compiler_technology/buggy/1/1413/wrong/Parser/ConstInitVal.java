package Parser;

import Lexer.Token;
import Parser.Exp.ConstExp;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/11
 */
public class ConstInitVal implements TreeNode{
    private String value="<ConstInitVal>";
    private ConstExp constExp1;
    private int flag;
    private Token leftBrace;
    private ConstExp constExp2;
    private ArrayList<Token> commas;
    private ArrayList<ConstExp> constExpArrayList;
    private Token rightBrace;
    private Token StringConst;
    public ConstInitVal(ConstExp constExp1, int flag, Token leftBrace, ConstExp constExp2, ArrayList<Token> commas, ArrayList<ConstExp> constExpArrayList, Token rightBrace, Token stringConst) {
        this.constExp1 = constExp1;
        this.flag = flag;
        this.leftBrace = leftBrace;
        this.constExp2 = constExp2;
        this.commas = commas;
        this.constExpArrayList = constExpArrayList;
        this.rightBrace = rightBrace;
        StringConst = stringConst;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        if(this.flag==1){
            sb.append(this.constExp1.print_tree());
        }else if(this.flag==2){
            sb.append(this.leftBrace.toStringprint());
            if(constExp2!=null)
            {
                sb.append(this.constExp2.print_tree());
                int cnt=this.commas.size();
                for(int i=0;i<cnt;i++){
                    sb.append(this.commas.get(i).toStringprint());
                    sb.append(this.constExpArrayList.get(i).print_tree());
                }
                sb.append(this.rightBrace.toStringprint());
            }else {
                sb.append(this.rightBrace.toStringprint());
            }
        }else if(flag==3){
            sb.append(this.StringConst.toStringprint());
        }
        sb.append(this.value).append("\n");
        return sb.toString();
    }
}
