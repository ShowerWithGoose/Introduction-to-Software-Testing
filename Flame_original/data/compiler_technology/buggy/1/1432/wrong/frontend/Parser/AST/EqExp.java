package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class EqExp extends AstNode{

    public void parse() {
        RelExp relExp = new RelExp();
        relExp.parse();
        stringBuilder.append("<EqExp>").append("\n");
        while (getNowTokenType() == TokenType.EQL ||
        getNowTokenType() == TokenType.NEQ) {
            append(1);
            relExp = new RelExp();
            relExp.parse();
            stringBuilder.append("<EqExp>").append("\n");
        }
    }
}
