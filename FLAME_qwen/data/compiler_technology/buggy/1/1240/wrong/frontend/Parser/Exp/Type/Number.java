package frontend.Parser.Exp.Type;

import frontend.Lexer.LexType;

public class Number implements PEinterface {
    private final LexType number;

    public Number(LexType number) {
        this.number = number;
    }

    public int getLine() {
        return this.number.getLine();
    }

    @Override
    public String toString() {
        return number.toString() + "<Number>\n";
    }
}
