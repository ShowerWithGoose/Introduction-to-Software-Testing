package frontend.Parser.Exp.Type;

import frontend.Lexer.LexType;

import java.util.ArrayList;

public class FuncExp implements UEinterface{
    // FuncExp --> Ident '(' [FuncRParams] ')'
    private final LexType ident;
    private final LexType left;
    private final LexType right;
    private final FuncRParams params;

    public FuncExp(LexType ident, LexType left, FuncRParams params, LexType right) {
        this.ident = ident;
        this.left = left;
        this.params = params;
        this.right = right;
    }

    public int getLine() {
        return ident.getLine();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.toString()).append(left.toString());
        if (params != null) sb.append(params);
        if (right != null) sb.append(right);
        return sb.toString();
    }
}
