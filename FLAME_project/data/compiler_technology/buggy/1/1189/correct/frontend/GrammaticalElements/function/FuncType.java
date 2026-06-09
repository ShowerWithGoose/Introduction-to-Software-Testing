package frontend.GrammaticalElements.function;

import frontend.GrammaticalElements.statement.Block;
import frontend.Token;

public class FuncType {
    private final String  name = "<FuncType>";
    private Token v_i_c;

    public FuncType(Token v_i_c) {
        this.v_i_c = v_i_c;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(v_i_c.toString());
        sb.append(this.name).append('\n');
        return sb.toString();
    }
}
