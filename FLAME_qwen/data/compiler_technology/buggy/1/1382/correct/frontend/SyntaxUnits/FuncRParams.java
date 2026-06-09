package frontend.SyntaxUnits;

import java.util.ArrayList;

public class FuncRParams implements SyntaxUnit {
    private final ArrayList<Exp> funcRParams;

    public FuncRParams(ArrayList<Exp> funcRParams) {
        this.funcRParams = funcRParams;
    }

    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        if (! funcRParams.isEmpty()) {
            for (Exp exp : funcRParams) {
                stringBuilder.append(exp.toPrint());
                stringBuilder.append("COMMA" + " ," +  "\n");
            }
            stringBuilder.delete(stringBuilder.length() - 8, stringBuilder.length());
        }
        stringBuilder.append("<FuncRParams>\n");
        return stringBuilder.toString();
    }
}
