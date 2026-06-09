package frontend.parser.decl.types;

import frontend.lexer.Token;
import frontend.parser.expr.types.Exp;

import java.util.ArrayList;

//InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
//ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
public class InitVal {
    private Token stringConst;
    private ArrayList<Token> seps;
    private ArrayList<Exp> exps;
    private Exp exp;
    private final boolean isConst;
    private Token rBrace, lBrace;
    public InitVal(Exp exp, boolean isConst) {
        this.exp = exp;
        this.isConst = isConst;
    }
    public InitVal(Token lBrace, Exp exp, ArrayList<Token> seps, ArrayList<Exp> exps, Token rBrace, boolean isConst) {
        this.exp = exp;
        this.lBrace = lBrace;
        this.seps = seps;
        this.exps = exps;
        this.rBrace = rBrace;
        this.isConst = isConst;
    }
    public InitVal(Token stringConst, boolean isConst) {
        this.stringConst = stringConst;
        this.isConst = isConst;
    }

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        if (this.stringConst != null) {
            res.append(stringConst);
        } else if (this.lBrace != null) {
            res.append(lBrace);
            if (exp != null) {
                res.append(exp);
                for (int i = 0; i < seps.size(); i++) {
                    res.append(seps.get(i)).append(exps.get(i));
                }
            }
            if (rBrace != null) res.append(rBrace);
        } else {
            res.append(exp);
        }
        res.append(this.isConst?"<ConstInitVal>\n":"<InitVal>\n");
        return res.toString();
    }
}
