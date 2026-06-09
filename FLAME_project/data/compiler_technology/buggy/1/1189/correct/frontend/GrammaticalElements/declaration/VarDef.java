package frontend.GrammaticalElements.declaration;

import frontend.GrammaticalElements.expression.ConstExp;
import frontend.Token;

public class VarDef {
    /*const string name = "<VarDef>";
    Token ident;
    Token leftSquare;
    ConstExp* constExp{};
    Token rightSquare;
    Token assign;
    ConstInitVal* constInitVal{};*/
    private final String name = "<VarDef>";
    private Token ident;
    private Token leftSquare;
    private ConstExp constExp;
    private Token rightSquare;
    private Token assign;
    private InitVal initVal;

    public VarDef(Token ident) {
        this.ident = ident;
    }

    public VarDef(Token ident, Token leftSquare, ConstExp constExp, Token rightSquare) {
        this.ident = ident;
        this.leftSquare = leftSquare;
        this.constExp = constExp;
        this.rightSquare = rightSquare;
    }

    public VarDef(Token ident, Token assign, InitVal initVal) {
        this.ident = ident;
        this.assign = assign;
        this.initVal = initVal;
    }

    public VarDef(Token ident, Token leftSquare, ConstExp constExp, Token rightSquare, Token assign, InitVal initVal) {
        this.ident = ident;
        this.leftSquare = leftSquare;
        this.constExp = constExp;
        this.rightSquare = rightSquare;
        this.assign = assign;
        this.initVal = initVal;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.toString());
        if (leftSquare != null) {
            sb.append(leftSquare.toString());
            sb.append(constExp.toString());
            sb.append(rightSquare.toString());
        }
        if (assign != null) {
            sb.append(assign.toString());
            sb.append(initVal.toString());
        }
        sb.append(this.name).append('\n');
        return sb.toString();
    }
}
