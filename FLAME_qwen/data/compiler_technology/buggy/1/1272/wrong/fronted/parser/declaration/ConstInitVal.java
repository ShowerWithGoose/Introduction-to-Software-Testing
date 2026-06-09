package fronted.parser.declaration;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.expression.ConstExp;

import java.util.ArrayList;

public class ConstInitVal {
    //ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst

    private ConstExp constExp;

    private static final Token leftBrace = new Token(TokenType.Type.LBRACE,"{",1);

    private static final Token rightBrace = new Token(TokenType.Type.RBRACE,"}",1);

    private static final Token comma = new Token(TokenType.Type.COMMA,",",1);

    private ArrayList<ConstExp> expArrayList;

    private Token StringConst;

    private int type; //表示选择了哪一种情况

    private static final String name = "<ConstInitVal>\n";

    public ConstInitVal(ConstExp constExp) {
        this.constExp = constExp;
        this.expArrayList = null;
        this.StringConst = null;
        type = 1;
    }

    public ConstInitVal(ArrayList<ConstExp> arrayList) {
        this.constExp = null;
        this.expArrayList = arrayList;
        this.StringConst = null;
        type = 2;
    }

    public ConstInitVal(Token token) {
        this.constExp = null;
        this.expArrayList = null;
        this.StringConst = token;
        type = 3;
    }

    @Override
    public String toString() {
        if (type == 1) {
            return constExp.toString() + name;
        } else if (type == 2) {
            StringBuilder sb = new StringBuilder();
            sb.append(leftBrace);
            int num = expArrayList.size();
            if (num != 0) {
                sb.append(expArrayList.get(0).toString());
            }
            for (int i = 1 ;i < num;i = i + 1) {
                sb.append(comma);
                sb.append(expArrayList.get(i).toString());
            }
            sb.append(rightBrace);
            sb.append(name);
            return sb.toString();
        } else {
            return StringConst.toString() + name;
        }
    }

    public static ConstInitVal parse(TokenList list) {
        if (list.now().getType().equals(TokenType.Type.STRCON)) {
            ConstInitVal constInitVal = new ConstInitVal(list.now());
            list.next();
            return constInitVal;
        } else if (list.now().getType().equals(TokenType.Type.LBRACE)) {
            list.next();
            ArrayList<ConstExp> exps = new ArrayList<>();
            while (!list.now().getType().equals(TokenType.Type.RBRACE)) {
                exps.add(ConstExp.parse(list));
                if (list.now().getType().equals(TokenType.Type.COMMA)) {
                    list.next();
                }
            }
            list.next();
            return new ConstInitVal(exps);
        } else {
            return new ConstInitVal(ConstExp.parse(list));
        }
    }
}
