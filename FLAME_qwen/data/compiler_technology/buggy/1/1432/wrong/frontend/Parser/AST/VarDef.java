package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class VarDef extends AstNode {

    public void parse() {
        append(1);
        if (getNowTokenType() == TokenType.LBRACK) {
            append(1);
            ConstExp constExp = new ConstExp();
            constExp.parse();
            k_error();
        }
        if (getNowTokenType() == TokenType.ASSIGN) {
            append(1);
            InitVal initVal = new InitVal();
            initVal.parse();
        }
        stringBuilder.append("<VarDef>").append("\n");
    }
}
