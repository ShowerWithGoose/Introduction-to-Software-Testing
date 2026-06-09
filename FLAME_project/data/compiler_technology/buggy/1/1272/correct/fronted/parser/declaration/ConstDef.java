package fronted.parser.declaration;

import fronted.ErrorList;
import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.Node;
import fronted.parser.expression.ConstExp;

public class ConstDef{
    //ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
    private Token ident;

    private ConstExp constExp; //有可能为null

    private static final Token leftBrack = new Token(TokenType.Type.LBRACK,"[",1);

    private static final Token rightBrack = new Token(TokenType.Type.RBRACK,"]",1);

    private static final Token assign = new Token(TokenType.Type.ASSIGN,"=",1);

    private ConstInitVal constInitVal;

    private static final String name = "<ConstDef>\n";

    public ConstDef(Token ident,ConstInitVal initVal) {
        this.ident = ident;
        this.constExp = null;
        this.constInitVal = initVal;
    }

    public ConstDef(Token ident,ConstExp constExp,ConstInitVal initVal) {
        this.ident = ident;
        this.constExp = constExp;
        this.constInitVal = initVal;
    }

    public ConstExp getConstExp() {
        return constExp;
    }

    public Token getIdent() {
        return ident;
    }

    public ConstInitVal getConstInitVal() {
        return constInitVal;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.toString());
        if (constExp != null) {
            sb.append(leftBrack.toString());
            sb.append(constExp.toString());
            sb.append(rightBrack.toString());
        }
        sb.append(assign.toString());
        sb.append(constInitVal.toString());
        sb.append(name);
        return sb.toString();
    }

    public static ConstDef parse(TokenList list) {
        Token token = list.now();
        if (token.getType() == TokenType.Type.IDENFR) {
            list.next();
            ConstExp constExp1 = null;
            if (list.now().getType().equals(TokenType.Type.LBRACK)) {
                list.next();
                constExp1 = ConstExp.parse(list);
                if (list.now().getType().equals(TokenType.Type.RBRACK)) {
                    list.next();
                } else {
                    ErrorList.addError(list.before().getLine(),'k');
                }
            }
            if (!list.now().getType().equals(TokenType.Type.ASSIGN)) {
                System.err.println("Error:ConstDef cannot find =");
                return null;
            } else {
                list.next();
                ConstInitVal initVal = ConstInitVal.parse(list);
                return new ConstDef(token,constExp1,initVal);
            }
        } else {
            System.err.println("Error:ConstDef cannot find ident");
            return null;
        }
    }

}
