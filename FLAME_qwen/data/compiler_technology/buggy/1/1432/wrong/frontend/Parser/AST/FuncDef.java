package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class FuncDef extends AstNode{

    public void parse() {
        FuncType funcType = new FuncType();
        funcType.parse();
        append(2);
        if (getNowTokenType() != TokenType.RPARENT) {
            FuncFParams funcFParams = new FuncFParams();
            funcFParams.parse();
        }
        j_error();
        Block block = new Block();
        block.parse();
        stringBuilder.append("<FuncDef>").append("\n");
    }
}
