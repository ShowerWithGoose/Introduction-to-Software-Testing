package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class LAndExp extends AstNode{

    public void parse() {
        EqExp eqExp = new EqExp();
        eqExp.parse();
        stringBuilder.append("<LAndExp>").append("\n");
        while (getNowTokenType() == TokenType.AND) {
            append(1);
            eqExp = new EqExp();
            eqExp.parse();
            stringBuilder.append("<LAndExp>").append("\n");
        }
    }
}
