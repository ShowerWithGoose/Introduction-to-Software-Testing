package fronted.parser.declaration;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.expression.ConstExp;
import fronted.parser.expression.Exp;

import java.util.ArrayList;

public class InitVal {
    //InitVal â†’ Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst

    private Exp exp;

    private ArrayList<Exp> exps;

    private Token StringConst;

    private static final Token leftBrace = new Token(TokenType.Type.LBRACE,"{",1);

    private static final Token rightBrace = new Token(TokenType.Type.RBRACE,"}",1);

    private static final Token comma = new Token(TokenType.Type.COMMA,",",1);

    private int type;

    private static final String name = "<InitVal>\n";

    public InitVal(Exp exp) {
        this.exp = exp;
        this.exps = null;
        this.StringConst = null;
        this.type = 1;
    }

    public InitVal(ArrayList<Exp> exps) {
        this.exp = null;
        this.exps = exps;
        this.StringConst = null;
        type = 2;
    }

    public InitVal(Token token) {
        this.exp = null;
        this.exps = null;
        this.StringConst = token;
        type = 3;
    }

    @Override
    public String toString() {
        if (type == 1) {
            return exp.toString() + name;
        } else if (type == 2) {
            StringBuilder sb = new StringBuilder();
            sb.append(leftBrace);
            int num = exps.size();
            if (num != 0) {
                sb.append(exps.get(0).toString());
            }
            for (int i = 1 ;i < num;i = i + 1) {
                sb.append(comma);
                sb.append(exps.get(i).toString());
            }
            sb.append(rightBrace);
            sb.append(name);
            return sb.toString();
        } else {
            return StringConst.toString() + name;
        }
    }

    public static InitVal parse(TokenList list){
        if (list.now().getType().equals(TokenType.Type.STRCON)) {
            InitVal initVal = new InitVal(list.now());
            list.next();
            return initVal;
        } else if (list.now().getType().equals(TokenType.Type.LBRACE)) {
            list.next();
            ArrayList<Exp> exps = new ArrayList<>();
            while (!list.now().getType().equals(TokenType.Type.RBRACE)) {
                exps.add(Exp.parse(list));
                if (list.now().getType().equals(TokenType.Type.COMMA)) {
                    list.next();
                }
            }
            list.next();
            return new InitVal(exps);
        } else {
            return new InitVal(Exp.parse(list));
        }
    }

}
