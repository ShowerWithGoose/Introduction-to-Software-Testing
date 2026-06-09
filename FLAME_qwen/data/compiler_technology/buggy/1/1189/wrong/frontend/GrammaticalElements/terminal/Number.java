package frontend.GrammaticalElements.terminal;

import frontend.Token;

public class Number {
    private final String name = "<Number>";
    private Token number;

    public Number(Token number) {
        this.number = number;
    }

    @Override
    public String toString() {
        return number.toString() + this.name + '\n';
    }
}
