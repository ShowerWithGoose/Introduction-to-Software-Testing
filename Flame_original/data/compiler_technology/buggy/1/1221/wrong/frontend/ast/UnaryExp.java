package frontend.ast;

import frontend.Token;
import frontend.TokenType;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;

public class UnaryExp implements AstNode {
    private final PrimaryExp primaryExp;
    private final Token ident;
    private final FuncRParams funcRParams;

    private final UnaryOp unaryOp;
    private final UnaryExp unaryExp;

    public UnaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
        ident = null;
        funcRParams = null;
        unaryExp = null;
        unaryOp = null;
    }

    public UnaryExp(Token ident) {
        primaryExp = null;
        this.ident = ident;
        funcRParams = null;
        unaryOp = null;
        unaryExp = null;
    }

    public UnaryExp(Token ident, FuncRParams funcRParams) {
        primaryExp = null;
        this.ident = ident;
        this.funcRParams = funcRParams;
        unaryExp = null;
        unaryOp = null;
    }

    public UnaryExp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
        ident = null;
        funcRParams = null;
        primaryExp = null;
    }

    @Override
    public String getSymbol() {
        return "<UnaryExp>";
    }

    @Override
    public void printToFile(BufferedWriter bw) throws IOException {
        if (primaryExp != null) {
            primaryExp.printToFile(bw);
        } else if (ident != null) {
            bw.write(ident + "\n");
            bw.write(TokenType.LPARENT + " (\n");
            if (funcRParams != null) {
                funcRParams.printToFile(bw);
            }
            bw.write(TokenType.RPARENT + " )\n");
        } else if (unaryOp != null && unaryExp != null) {
            unaryOp.printToFile(bw);
            unaryExp.printToFile(bw);
        }
        bw.write(getSymbol() + "\n");
    }
}
