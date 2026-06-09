package frontend.GrammaticalElements.declaration;

import frontend.Token;

public class BType {
    private Token int_char;

    public BType(Token int_char) {
        this.int_char = int_char;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(int_char.toString());
        return sb.toString();
    }
}
