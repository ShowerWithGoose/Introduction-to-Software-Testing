package frontend.parser.func;

import frontend.lexer.TokenType;
import frontend.parser.stmt.Stmt;

import java.util.ArrayList;
import java.util.HashSet;

public class Block {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.LBRACE);
    }

    private ArrayList<Stmt> stmts;

    public Block(ArrayList<Stmt> stmts) {
        this.stmts = stmts;
    }

    @Override
    public String toString() {
        String string = "";
        string += (TokenType.LBRACE + " {\n");
        for (Stmt stmt : this.stmts) {
            string += stmt.toString();
        }
        string += (TokenType.RBRACE + " }\n");
        string += "<Block>\n";
        return string;
    }
}
