package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class Decl extends AstNode {

    public void parse() {
        if (getNowTokenType() == TokenType.CONSTTK) {
            ConstDecl constDecl = new ConstDecl();
            constDecl.parse();
        } else {
            VarDecl varDecl = new VarDecl();
            varDecl.parse();
        }
    }
}
