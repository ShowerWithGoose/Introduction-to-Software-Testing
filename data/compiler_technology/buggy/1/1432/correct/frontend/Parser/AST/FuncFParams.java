package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class FuncFParams extends AstNode{

    public void parse() {
        FuncFParam funcFParam = new FuncFParam();
        funcFParam.parse();
        while (getNowTokenType() == TokenType.COMMA) {
            append(1);
            funcFParam = new FuncFParam();
            funcFParam.parse();
        }
        stringBuilder.append("<FuncFParams>").append("\n");
    }
}
