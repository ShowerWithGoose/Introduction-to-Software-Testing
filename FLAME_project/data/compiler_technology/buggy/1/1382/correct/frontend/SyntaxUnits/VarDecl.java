package frontend.SyntaxUnits;

import java.util.ArrayList;

public class VarDecl implements DeclUnit {
    private final BType bType;
    private final ArrayList<VarDef> varDefs;

    public VarDecl(ArrayList<VarDef> varDefs, BType bType) {
        this.bType =bType;
        this.varDefs = varDefs;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(bType.toPrint());
        if (! varDefs.isEmpty()) {
            for (VarDef varDef : varDefs) {
                stringBuilder.append(varDef.toPrint());
                stringBuilder.append("COMMA" + " ," +  "\n");
            }
            stringBuilder.delete(stringBuilder.length() - 8, stringBuilder.length());
        }
        stringBuilder.append("SEMICN" + " ;" +  "\n");
        stringBuilder.append("<VarDecl>\n");
        return stringBuilder.toString();
    }
}
