package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class ConstInitVal extends AstNode {
    public void parse() {
        if (getNowTokenType() == TokenType.STRCON) {
            append(1);
        } else if (getNowTokenType() == TokenType.LBRACE) {
            append(1);
            if (getNowTokenType() != TokenType.RBRACE) {
                ConstExp constExp = new ConstExp();
                constExp.parse();
                while (getNowTokenType() == TokenType.COMMA) {
                    append(1);
                    constExp = new ConstExp();
                    constExp.parse();
                }
            }
            append(1);
        } else {
            ConstExp constExp = new ConstExp();
            constExp.parse();
        }
        stringBuilder.append("<ConstInitVal>").append("\n");
    }
}
