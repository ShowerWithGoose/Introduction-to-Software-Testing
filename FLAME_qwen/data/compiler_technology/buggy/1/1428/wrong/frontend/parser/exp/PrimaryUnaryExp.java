package frontend.parser.exp;

import frontend.lexer.TokenType;

import java.util.ArrayList;
import java.util.HashSet;

public class PrimaryUnaryExp extends UnaryExp {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(PrimaryExp.FIRST);
    }

    private PrimaryExp primaryExp;

    public PrimaryUnaryExp(ArrayList<TokenType> signs, PrimaryExp primaryExp) {
        super(signs);
        this.primaryExp = primaryExp;
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
        string += this.primaryExp.toString();
        for (int i = 0; i < this.signs.size() + 1; i++) {
            string += "<UnaryExp>\n";
        }
        return string;
    }
}
