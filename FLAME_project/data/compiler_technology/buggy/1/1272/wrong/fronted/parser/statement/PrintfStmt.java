package fronted.parser.statement;

import fronted.ErrorList;
import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.expression.Exp;
import fronted.parser.others.Block;

import java.util.ArrayList;

public class PrintfStmt {
    //自定义
    //'printf''('StringConst {','Exp}')'';' // i j

    private Token print;

    private static final Token leftParent = new Token(TokenType.Type.LPARENT,"(",1);

    private static final Token rightParent = new Token(TokenType.Type.RPARENT,")",1);

    private static final Token semicn = new Token(TokenType.Type.SEMICN,";",1);

    private static final Token comma = new Token(TokenType.Type.COMMA,",",1);

    private Token string;

    private ArrayList<Exp> exps;

    public PrintfStmt(Token print,Token string,ArrayList<Exp> exps) {
        this.print = print;
        this.string = string;
        this.exps = exps;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(print.toString());
        sb.append(leftParent);
        sb.append(string.toString());
        int num = exps.size();
        for (int i = 0;i < num; i=i+1) {
            sb.append(comma);
            sb.append(exps.get(i).toString());
        }
        sb.append(rightParent);
        sb.append(semicn);
        return sb.toString();
    }
    //'printf''('StringConst {','Exp}')'';' // i j

    public static PrintfStmt parse(TokenList list) {
        if (list.now().getType().equals(TokenType.Type.PRINTFTK)) {
            Token p = list.now();
            list.next();
            list.next();//(
            Token string = list.now();
            list.next();
            ArrayList<Exp> exps = new ArrayList<>();
            while (list.now().getType().equals(TokenType.Type.COMMA)) {
                list.next();
                exps.add(Exp.parse(list));
            }
            if (list.now().getType().equals(TokenType.Type.RPARENT)) {
                list.next();
            } else {
                ErrorList.addError(list.before().getLine(),'j');
            }
            if (list.now().getType().equals(TokenType.Type.SEMICN)) {
                list.next();
            } else {
                ErrorList.addError(list.before().getLine(),'i');
            }
            return new PrintfStmt(p,string,exps);
        } else {
            System.err.println("Error:PrintfStmt cannot find printf");
            return null;
        }
    }
}
