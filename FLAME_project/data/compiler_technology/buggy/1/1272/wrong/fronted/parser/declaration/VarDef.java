package fronted.parser.declaration;

import fronted.ErrorList;
import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.expression.ConstExp;

public class VarDef {
    //VarDef â†’ Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k

    private Token ident;

    private static final Token leftBrack = new Token(TokenType.Type.LBRACK,"[",1);

    private static final Token rightBrack = new Token(TokenType.Type.RBRACK,"]",1);

    private static final Token assign = new Token(TokenType.Type.ASSIGN,"=",1);

    private ConstExp constExp;

    private InitVal initVal;

    private static final String name = "<VarDef>\n";

    public VarDef(Token ident,ConstExp constExp,InitVal initVal) {
        this.ident = ident;
        this.constExp = constExp;
        this.initVal = initVal;
    }

    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(ident.toString());
        if (constExp != null) {
            sb.append(leftBrack.toString());
            sb.append(constExp.toString());
            sb.append(rightBrack.toString());
        }
        if (initVal != null) {
            sb.append(assign.toString());
            sb.append(initVal.toString());
        }
        sb.append(name);
        return sb.toString();
    }

    public static VarDef parse(TokenList list) {
        if (!list.now().getType().equals(TokenType.Type.IDENFR)) {
            System.err.println("Error:VarDef cannot find identifier");
            return null;
        } else {
            Token token = list.now();
            ConstExp constExp1 = null;
            InitVal initVal1 = null;
            list.next();
            if (list.now().getType().equals(TokenType.Type.LBRACK)) {
                list.next();
                constExp1 = ConstExp.parse(list);
                if (!list.now().getType().equals(TokenType.Type.RBRACK)) {
                    ErrorList.addError(list.before().getLine(),'k');
                } else {
                    list.next();
                }
            }
            if (list.now().getType().equals(TokenType.Type.ASSIGN)) {
                list.next();
                initVal1 = InitVal.parse(list);
            }
            return new VarDef(token,constExp1,initVal1);
        }
    }

}
