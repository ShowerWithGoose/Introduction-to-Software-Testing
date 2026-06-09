package syntaxTree;

import token.Token;

import java.util.ArrayList;

public class PrintfStmt extends Stmt {
    private final Token stringConst;
    private final ArrayList<Exp> exps;

    public PrintfStmt(Token stringConst, ArrayList<Exp> exps) {
        this.stringConst = stringConst;
        this.exps = exps;
    }
}
