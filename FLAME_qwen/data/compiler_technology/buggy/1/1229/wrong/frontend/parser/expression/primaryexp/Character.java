package frontend.parser.expression.primaryexp;

import frontend.lexer.TokenList;
import frontend.parser.terminal.CharConst;
import frontend.parser.terminal.IntConst;

public class Character implements PrimaryExpIFace{
    private final String name = "<Character>";
    private CharConst charConst;

    private TokenList tokenList;

    public Character(TokenList tokenList) {
        this.tokenList = tokenList;
    }
    public void parseCharacter(){
        this.charConst = new CharConst(tokenList);
        this.charConst.parseCharConst();
    }
    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(charConst.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
