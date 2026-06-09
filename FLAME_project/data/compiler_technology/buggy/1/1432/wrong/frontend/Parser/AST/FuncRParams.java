package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class FuncRParams extends AstNode{

    public void parse() {
        Exp exp = new Exp();
        exp.parse();
        while (getNowTokenType() == TokenType.COMMA) {
            append(1);
            exp = new Exp();
            exp.parse();
        }
        if (print == 1) {
            stringBuilder.append("<FuncRParams>").append("\n");
        }
    }
}