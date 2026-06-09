package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.declaration.constant.constinitval.ConstInitValIFace;
import frontend.parser.declaration.variable.initval.InitValIFace;

public class StringConst implements ConstInitValIFace, InitValIFace {
    private Token token; // STRCON
    private TokenList tokenList;

    public StringConst(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseStringConst(){
        token = tokenList.getNextToken();
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.token.syntaxOutput());
        return sb.toString();
    }
}
