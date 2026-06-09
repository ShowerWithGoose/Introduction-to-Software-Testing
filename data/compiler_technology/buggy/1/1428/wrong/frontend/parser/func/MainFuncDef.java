package frontend.parser.func;

import frontend.lexer.TokenType;

import java.util.HashSet;

public class MainFuncDef {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.INTTK);
    }

    private Block block;
    public MainFuncDef(Block block) {
        this.block = block;
    }

    @Override
    public String toString() {
        String string = "";
        string += (TokenType.INTTK + " int\n");
        string += (TokenType.MAINTK + " main\n");
        string += (TokenType.LPARENT + " (\n");
        string += (TokenType.RPARENT + " )\n");
        string += this.block.toString();
        string += "<MainFuncDef>\n";
        return string;
    }
}
