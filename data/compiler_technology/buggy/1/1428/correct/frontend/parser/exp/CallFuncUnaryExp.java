package frontend.parser.exp;

import frontend.lexer.TokenType;
import frontend.parser.func.FuncRParams;

import java.util.ArrayList;
import java.util.HashSet;

public class CallFuncUnaryExp extends UnaryExp {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.IDENFR);
    }

    private String Ident;
    private FuncRParams funcRParams;

    public CallFuncUnaryExp(ArrayList<TokenType> signs, String Ident, FuncRParams funcRParams) {
        super(signs);
        this.Ident = Ident;
        this.funcRParams = funcRParams;
    }

    @Override
    public String toString() {
        String string = "";
        for (TokenType tokenType : this.signs) {
            string += tokenType;
            if (tokenType == TokenType.PLUS) {
                string += " +\n";
            } else if (tokenType == TokenType.MINU) {
                string += " -\n";
            } else {
                string += " !\n";
            }
            string += "<UnaryOp>\n";
        }
        string += (TokenType.IDENFR + " " + this.Ident + "\n");
        string += (TokenType.LPARENT + " (\n");
        if (this.funcRParams != null) {
            string += this.funcRParams.toString();
        }
        string += (TokenType.RPARENT + " )\n");
        for (int i = 0; i < this.signs.size() + 1; i++) {
            string += "<UnaryExp>\n";
        }
        return string;
    }
}
