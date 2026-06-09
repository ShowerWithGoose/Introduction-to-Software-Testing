package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class ConstDef extends AstNode {
    public void parse() {
        append(1);
        if (getNowTokenType() == TokenType.LBRACK) {
            append(1);
            ConstExp constExp = new ConstExp();
            constExp.parse();
            k_error();
        }
        append(1);
        ConstInitVal constInitVal = new ConstInitVal();
        constInitVal.parse();
        stringBuilder.append("<ConstDef>").append("\n");
    }
}
