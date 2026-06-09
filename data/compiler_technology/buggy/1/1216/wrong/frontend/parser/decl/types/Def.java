package frontend.parser.decl.types;

import frontend.lexer.Token;
import frontend.lexer.TokenType;
import frontend.parser.expr.types.Exp;
import frontend.symbol.SymbolType;

//VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
//ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
public class Def {
    private final boolean isConst;
    private final Token ident;
    private final InitVal initVal;
    private final Token assign;
    private final Token lBrack;
    private final Token rBrack;
    private final Exp constExp;

    public Def(Token ident, Token lBrack, Exp constExp, Token rBrack, Token assign, InitVal initVal, boolean isConst) {
        this.ident = ident;
        this.lBrack = lBrack;
        this.constExp = constExp;
        this.rBrack = rBrack;
        this.assign = assign;
        this.initVal = initVal;
        this.isConst = isConst;
    }
    public boolean isConst() {
        return this.isConst;
    }
    public Token getIdent() {
        return this.ident;
    }
    @Override
    public String toString() {
        StringBuilder result = new StringBuilder();
        result.append(ident);
        if (lBrack != null) {
            result.append(lBrack);
            result.append(constExp);
            if (rBrack != null) result.append(rBrack);
        }
        if (assign != null) {
            result.append(assign);
            result.append(initVal);
        }
        result.append(isConst?"<ConstDef>\n":"<VarDef>\n");
        return result.toString();
    }
    public boolean isArray() {
        return lBrack != null;
    }
}
