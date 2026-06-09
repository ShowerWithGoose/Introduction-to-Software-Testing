package parser_part;

import lexer_part.Token;
import parser_part.declaration.constance.ConstInitValComponent;
import parser_part.declaration.var.initVal.InitValComponent;

public class FormatString implements Node, ConstInitValComponent, InitValComponent {
    public Token strcon;

    public FormatString(Token strcon) {
        this.strcon = strcon;
    }

    @Override
    public String toString() {
        return strcon.toString();
    }

    public String getContent() {
        return strcon.getContent();
    }

    public int getLineIndex() {
        return strcon.getLineIndex();
    }
}
