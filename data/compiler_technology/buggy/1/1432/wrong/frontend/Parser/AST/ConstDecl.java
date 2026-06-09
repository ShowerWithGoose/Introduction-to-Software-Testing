package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class ConstDecl extends AstNode {

    public void parse() {
        append(1);
        BType bType = new BType();
        bType.parse();
        ConstDef constDef = new ConstDef();
        constDef.parse();
        while (getNowTokenType() == TokenType.COMMA) {
            append(1);
            constDef = new ConstDef();
            constDef.parse();
        }
        i_error();
        stringBuilder.append("<ConstDecl>").append("\n");
    }
}