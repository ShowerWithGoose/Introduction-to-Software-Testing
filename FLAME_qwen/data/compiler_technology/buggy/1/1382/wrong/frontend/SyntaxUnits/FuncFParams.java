package frontend.SyntaxUnits;

import java.util.ArrayList;

public class FuncFParams implements SyntaxUnit{
    private final ArrayList<FuncFParam> funcFParams;

    public FuncFParams(ArrayList<FuncFParam> funcFParams) {
        this.funcFParams = funcFParams;
    }

    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        if (! funcFParams.isEmpty()) {
            for (FuncFParam funcFParam : funcFParams) {
                stringBuilder.append(funcFParam.toPrint());
                stringBuilder.append("COMMA" + " ," +  "\n");
            }
            stringBuilder.delete(stringBuilder.length() - 8, stringBuilder.length());
        }
        stringBuilder.append("<FuncFParams>\n");
        return stringBuilder.toString();
    }
}
