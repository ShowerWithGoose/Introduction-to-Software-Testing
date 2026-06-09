package frontend.parser.Function;

import error.ErrorHandling;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Block.Block;

public class MainFuncDef {
    private Token intTk;
    private Token mainTk;
    private Token lparent;
    private Token rparent;
    private Block block;
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "MainFuncDef";

    public MainFuncDef(TokenList tokens) {
        this.intTk = null;
        this.mainTk = null;
        this.lparent = null;
        this.rparent = null;
        this.block = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        intTk = tokens.nextToken();
        mainTk = tokens.nextToken();
        lparent = tokens.nextToken();
        Token token = tokens.nextToken();
        if (token.equals(LexType.RPARENT)) {
            rparent = token;
        } else {
            ErrorHandling.printError(tokens.preNonTerminalLineNum(),'j');
            errorNum++;
            tokens.rollBack(1);
        }
        block = new Block(tokens);
        errorNum += block.parse();
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(intTk).append(mainTk).append(lparent);
        if (rparent != null) {
            sb.append(rparent);
        }
        sb.append(block.toSyntaxTree());
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
