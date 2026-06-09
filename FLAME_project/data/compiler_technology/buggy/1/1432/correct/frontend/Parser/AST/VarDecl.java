package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class VarDecl extends AstNode {
    public void parse() {
        BType bType = new BType();
        bType.parse();
        VarDef varDef = new VarDef();
        varDef.parse();
        while (getNowTokenType() == TokenType.COMMA) {
            append(1);
            varDef = new VarDef();
            varDef.parse();
        }
        i_error();
        stringBuilder.append("<VarDecl>").append("\n");
    }
}
