package frontend.Parser.Terminators;

import frontend.Lexer.Token;
import frontend.Parser.ASTNode;
import frontend.Parser.Declaration.ConstInitValEle;
import frontend.Parser.Declaration.InitValEle;

public class StringConst implements ASTNode, ConstInitValEle, InitValEle {
    private Token token;    // STRCON

    public StringConst(Token token) {
        this.token = token;
    }

    @Override
    public String printString() {
        return token.toString();
    }
}
