package syntaxTree;

import token.Token;

import java.util.ArrayList;

public class FuncResult extends UnaryExp {
    private final Token Ident;
    private final ArrayList<FuncRParam> FuncRParams;

    public FuncResult(Token Ident, ArrayList<FuncRParam> FuncRParams) {
        this.Ident = Ident;
        this.FuncRParams = FuncRParams;
    }
}
