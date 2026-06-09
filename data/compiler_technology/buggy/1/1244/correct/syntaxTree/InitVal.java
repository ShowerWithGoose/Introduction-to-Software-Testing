package syntaxTree;

import token.Token;

import java.util.ArrayList;

public class InitVal {
    private ArrayList<Exp> exps;
    private final Token stringConst;
    private final InitValType type;

    public InitVal(ArrayList<Exp> exps, Token stringConst, InitValType type) {
        this.exps = exps;
        this.stringConst = stringConst;
        this.type = type;
    }

    public InitVal(Token stringConst, InitValType type) {
        this.stringConst = stringConst;
        this.type = type;
    }
}
