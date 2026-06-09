package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class MulExp extends AstNode{

    public void parse() {
        UnaryExp unaryExp = new UnaryExp();
        unaryExp.parse();
        if (print == 1) {
            stringBuilder.append("<MulExp>").append("\n");
        }
        while (getNowTokenType() == TokenType.MULT ||
        getNowTokenType() == TokenType.DIV ||
        getNowTokenType() == TokenType.MOD) {
            append(1);
            unaryExp = new UnaryExp();
            unaryExp.parse();
            if (print == 1) {
                stringBuilder.append("<MulExp>").append("\n");
            }
        }
    }
}
