package frontend.parser.func;

import frontend.lexer.TokenType;

import java.util.HashSet;

public class FuncDef {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.VOIDTK);
        FIRST.add(TokenType.INTTK);
        FIRST.add(TokenType.CHARTK);
    }

    private TokenType FuncType;
    private String Ident;
    private FuncFParams funcFParams;
    private Block block;

    public FuncDef(TokenType FuncType, String Ident, FuncFParams funcFParams, Block block) {
        this.FuncType = FuncType;
        this.Ident = Ident;
        this.funcFParams = funcFParams;
        this.block = block;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.FuncType;
        if (this.FuncType == TokenType.CHARTK) {
            string += " char\n";
        } else if (this.FuncType == TokenType.INTTK){
            string += " int\n";
        } else {
            string += " void\n";
        }
        string += "<FuncType>\n";
        string += (TokenType.IDENFR + " " + this.Ident + "\n");
        string += (TokenType.LPARENT + " (\n");
        if (this.funcFParams != null) {
            string += this.funcFParams.toString();
        }
        string += (TokenType.RPARENT + " )\n");
        string += this.block.toString();
        string += "<FuncDef>\n";
        return string;
    }
}
