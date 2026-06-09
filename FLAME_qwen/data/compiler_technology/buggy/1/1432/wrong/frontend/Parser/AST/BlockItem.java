package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class BlockItem extends AstNode{
    public void parse() {
        if (getNowTokenType() == TokenType.CONSTTK ||
        getNowTokenType() == TokenType.INTTK ||
        getNowTokenType() == TokenType.CHARTK) {
            Decl decl = new Decl();
            decl.parse();
        } else {
            Stmt stmt = new Stmt();
            stmt.parse();
        }
    }
}
