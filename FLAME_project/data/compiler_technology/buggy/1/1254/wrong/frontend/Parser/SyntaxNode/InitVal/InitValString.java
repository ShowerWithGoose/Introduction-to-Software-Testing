package frontend.Parser.SyntaxNode.InitVal;

import frontend.Lexer.Token.Token;
import frontend.Parser.SyntaxNode.ConstInitVal.ConstInitVal;

public class InitValString extends InitVal {
    private Token stringConst;

    public InitValString(Token stringConst) {
        this.stringConst = stringConst;
    }

    @Override
    public String toString() {
        return stringConst.toString() + name + "\n";
    }
}
