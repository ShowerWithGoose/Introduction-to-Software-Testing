package frontend.ast;

import frontend.TokenType;

import java.io.BufferedWriter;
import java.io.IOException;

public class ForStmt implements AstNode {
    private final LVal lval;
    private final Exp exp;

    public ForStmt(LVal lval, Exp exp) {
        this.lval = lval;
        this.exp = exp;
    }

    @Override
    public String getSymbol() {
        return "<ForStmt>";
    }

    @Override
    public void printToFile(BufferedWriter bw) throws IOException {
        lval.printToFile(bw);
        bw.write(TokenType.ASSIGN + " =\n");
        exp.printToFile(bw);
        bw.write(getSymbol() + "\n");
    }
}
