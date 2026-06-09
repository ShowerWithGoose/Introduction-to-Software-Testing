package syntaxTree;

import token.Token;

import java.util.ArrayList;

public class ConstInitVal extends InitVal {
    private final ArrayList<ConstExp> exps;

    public ConstInitVal(ArrayList<ConstExp> exps, Token stringConst, InitValType type) {
        super(stringConst, type);
        this.exps = exps;
    }
}
