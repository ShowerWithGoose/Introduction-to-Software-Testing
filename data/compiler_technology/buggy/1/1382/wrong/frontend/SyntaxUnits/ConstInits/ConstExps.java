package frontend.SyntaxUnits.ConstInits;

import frontend.SyntaxUnits.Exps.ConstExp;

import java.util.ArrayList;

public class ConstExps implements ConstInitUnit{
    private final ArrayList<ConstExp> constExps;

    public ConstExps(ArrayList<ConstExp> constExps) {
        this.constExps = constExps;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("LBRACE" + " {" +  "\n");
        if (! constExps.isEmpty()) {
            for (ConstExp constExp :  constExps) {
                stringBuilder.append(constExp.toPrint());
                stringBuilder.append("COMMA" + " ," +  "\n");
            }
            stringBuilder.delete(stringBuilder.length() - 8, stringBuilder.length());
        }
        stringBuilder.append("RBRACE" + " }" +  "\n");
        return stringBuilder.toString();
    }
}
