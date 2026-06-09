package frontend.parser.stmt;

import frontend.lexer.TokenType;
import frontend.parser.base.Lval;
import frontend.parser.exp.Exp;

import java.util.HashSet;

public class ForAssign {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(Lval.FIRST);
    }

    private Lval lval;
    private Exp exp;

    public ForAssign(Lval lval, Exp exp) {
        this.lval = lval;
        this.exp = exp;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.lval.toString();
        string += (TokenType.ASSIGN+ " =\n");
        string += this.exp.toString();
        string += "<ForStmt>\n";
        return string;
    }
}
