package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class LVal extends AstNode{

    public void parse() {
        append(1);
        if (getNowTokenType() == TokenType.LBRACK) {
            append(1);
            Exp exp = new Exp();
            exp.parse();
            k_error();
        }
        if (print == 1) {
            stringBuilder.append("<LVal>").append("\n");
        }
    }
}
