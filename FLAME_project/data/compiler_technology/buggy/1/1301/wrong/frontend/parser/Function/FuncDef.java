package frontend.parser.Function;

import error.ErrorHandling;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Block.Block;

public class FuncDef {
    private FuncType funcType;
    private Token ident;
    private Token lparent;
    private FuncFParams funcFParams; //可能没有
    private Token rparent;
    private Block block;
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "FuncDef";

    public FuncDef(TokenList tokens) {
        this.funcType = null;
        this.ident = null;
        this.lparent = null;
        this.funcFParams = null;
        this.rparent = null;
        this.block = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        funcType = new FuncType(tokens);
        errorNum += funcType.parse();
        ident = tokens.nextToken();
        lparent = tokens.nextToken();
        Token token = tokens.nextToken();
        if (token.equals(LexType.INTTK) || token.equals(LexType.CHARTK)) { //有funcFParams
            tokens.rollBack(1);
            funcFParams = new FuncFParams(tokens);
            errorNum += funcFParams.parse();
            token = tokens.nextToken();
        }
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
        sb.append(funcType.toSyntaxTree()).append(ident).append(lparent);
        if (funcFParams != null) {
            sb.append(funcFParams.toSyntaxTree());
        }
        if (rparent != null) {
            sb.append(rparent);
        }
        sb.append(block.toSyntaxTree());
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
