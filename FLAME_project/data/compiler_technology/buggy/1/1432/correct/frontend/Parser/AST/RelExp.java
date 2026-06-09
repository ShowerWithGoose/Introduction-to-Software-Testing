package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class RelExp extends AstNode{

    public void parse() {
        AddExp addExp = new AddExp();
        addExp.parse();
        stringBuilder.append("<RelExp>").append("\n");
        while (getNowTokenType() == TokenType.LSS ||
        getNowTokenType() == TokenType.LEQ ||
        getNowTokenType() == TokenType.GEQ ||
        getNowTokenType() == TokenType.GRE) {
            append(1);
            addExp = new AddExp();
            addExp.parse();
            stringBuilder.append("<RelExp>").append("\n");
        }
    }
}
