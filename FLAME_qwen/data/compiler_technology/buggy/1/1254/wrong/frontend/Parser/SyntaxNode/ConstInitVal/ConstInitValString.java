package frontend.Parser.SyntaxNode.ConstInitVal;

import frontend.Lexer.Token.Token;

public class ConstInitValString extends ConstInitVal {
    private Token stringConst;

    public ConstInitValString(Token stringConst) {
        this.stringConst = stringConst;
    }

    @Override
    public String toString() {
        return stringConst.toString() + name + "\n";
    }
}
