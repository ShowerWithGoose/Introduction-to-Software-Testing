package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class LOrExp extends AstNode{

    public void parse() {
        LAndExp lAndExp = new LAndExp();
        lAndExp.parse();
        stringBuilder.append("<LOrExp>").append("\n");
        while (getNowTokenType() == TokenType.OR) {
            append(1);
            lAndExp = new LAndExp();
            lAndExp.parse();
            stringBuilder.append("<LOrExp>").append("\n");
        }
    }
}
