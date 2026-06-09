package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class AddExp extends AstNode{

    public void parse() {
        MulExp mulExp = new MulExp();
        mulExp.parse();
        if (print == 1) {
            stringBuilder.append("<AddExp>").append("\n");
        }
        while (getNowTokenType() == TokenType.PLUS
                || getNowTokenType() == TokenType.MINU) {
            append(1);
            mulExp = new MulExp();
            mulExp.parse();
            if (print == 1) {
                stringBuilder.append("<AddExp>").append("\n");
            }
        }
    }
}
