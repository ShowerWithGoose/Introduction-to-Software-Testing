package frontend.Parser.Del.Type;

import frontend.Lexer.LexType;

public class Def {
    // ConstDef → Var '=' ConstInitVal
    // VarDef → Var | Var '=' InitVal
    private final Var var;
    private final LexType assign;
    private final InitVal initVal;
    private final boolean ifConst;

    public Def(Var var) {
        this.var = var;
        this.assign = null;
        this.initVal = null;
        this.ifConst = false;
    }

    public Def(Var var, LexType assign, InitVal initVal, boolean ifConst) {
        this.var = var;
        this.initVal = initVal;
        this.assign = assign;
        this.ifConst = ifConst;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(var);
        if (assign != null && initVal != null) {
            sb.append(assign);
            sb.append(initVal);
        }
        if (ifConst) {
            sb.append("<ConstDef>\n");
        } else {
            sb.append("<VarDef>\n");
        }
        return sb.toString();
    }
}
