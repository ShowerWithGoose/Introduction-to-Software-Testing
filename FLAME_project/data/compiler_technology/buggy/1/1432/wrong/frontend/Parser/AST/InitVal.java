package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class InitVal extends AstNode{

    public void parse() {
        if (getNowTokenType() == TokenType.LBRACE) {
            append(1);
            if (getNowTokenType() != TokenType.LBRACE) {
                Exp exp = new Exp();
                exp.parse();
                while (getNowTokenType() == TokenType.COMMA) {
                    append(1);
                    exp = new Exp();
                    exp.parse();
                }
            }
            append(1);
        } else if (getNowTokenType() == TokenType.STRCON) {
            append(1);
        } else {
            Exp exp = new Exp();
            exp.parse();
        }
        stringBuilder.append("<InitVal>").append("\n");
    }
}
