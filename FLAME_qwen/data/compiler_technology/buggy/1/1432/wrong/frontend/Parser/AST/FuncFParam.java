package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class FuncFParam extends AstNode{
    public void parse() {
        BType bType = new BType();
        bType.parse();
        append(1);
        if (getNowTokenType() == TokenType.LBRACK) {
            append(1);
            k_error();
        }
        stringBuilder.append("<FuncFParam>").append("\n");
    }
}
