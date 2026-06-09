package fronted.parser.expression;

import fronted.ErrorList;
import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.function.FuncRParams;

public class UnaryExp {
    //UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j

    private PrimaryExp primaryExp;

    private Token ident;

    private FuncRParams funcRParams;

    private UnaryOp unaryOp;

    private UnaryExp unaryExp;

    private static final Token leftParent = new Token(TokenType.Type.LPARENT,"(",1);

    private static final Token rightParent = new Token(TokenType.Type.RPARENT,")",1);

    private static final String name = "<UnaryExp>\n";

    public UnaryExp(PrimaryExp primaryExp,
                    Token ident,FuncRParams funcRParams,
                    UnaryOp unaryOp,UnaryExp unaryExp) {
        this.primaryExp = primaryExp;
        this.ident = ident;
        this.funcRParams = funcRParams;
        this.unaryExp = unaryExp;
        this.unaryOp = unaryOp;
    }

    @Override
    public String toString(){
        if (primaryExp != null) {
            return primaryExp.toString() + name;
        } else if (ident != null) {
            StringBuilder sb = new StringBuilder();
            sb.append(ident.toString());
            sb.append(leftParent);
            if (funcRParams != null) {
                sb.append(funcRParams.toString());
            }
            sb.append(rightParent);
            sb.append(name);
            return sb.toString();
        } else {
            StringBuilder sb = new StringBuilder();
            sb.append(unaryOp.toString());
            sb.append(unaryExp.toString());
            sb.append(name);
            return sb.toString();
        }
    }

    public static UnaryExp parse(TokenList list){
        PrimaryExp primaryExp = null;
        Token ident = null;
        FuncRParams funcRParams = null;
        UnaryOp unaryOp = null;
        UnaryExp unaryExp = null;
        if (list.now().getType().equals(TokenType.Type.IDENFR)
                && list.getAheadOne(1).getType().equals(TokenType.Type.LPARENT)) {
            ident = list.now();
            list.next();
            if (list.now().getType().equals(TokenType.Type.LPARENT)) {
                list.next(); //(
                Token first = list.now();
                if (list.now().getType().equals(TokenType.Type.RPARENT)) {
                    list.next();
                } else if (first.getType().equals(TokenType.Type.LPARENT) ||
                        first.getType().equals(TokenType.Type.INTCON) ||
                        first.getType().equals(TokenType.Type.CHRCON) ||
                        (first.getType().equals(TokenType.Type.IDENFR)) ||
                        first.getType().equals(TokenType.Type.PLUS) ||
                        first.getType().equals(TokenType.Type.MINU) ||
                        first.getType().equals(TokenType.Type.NOT)){
                    //不需要考虑可能出现assignStmt & getIntCharStmt
                    funcRParams = FuncRParams.parse(list);
                    if (list.now().getType().equals(TokenType.Type.RPARENT)) {
                        list.next();
                    } else {
                        ErrorList.addError(list.before().getLine(),'j');
                    }
                }
            } else {
                System.err.println("Error:UnaryExp cannot find (");
            }
        } else if (list.now().getType().equals(TokenType.Type.PLUS)
                || list.now().getType().equals(TokenType.Type.MINU)
                || list.now().getType().equals(TokenType.Type.NOT)) {
            unaryOp = UnaryOp.parse(list);
            unaryExp = parse(list);
        } else {
            primaryExp = PrimaryExp.parse(list);
        }
        return new UnaryExp(primaryExp,ident,funcRParams,unaryOp,unaryExp);
    }
}
