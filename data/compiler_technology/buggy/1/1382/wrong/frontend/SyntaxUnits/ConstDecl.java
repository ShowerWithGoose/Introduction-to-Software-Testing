package frontend.SyntaxUnits;

import java.util.ArrayList;

public class ConstDecl implements DeclUnit {
    private final BType bType;
    private final ArrayList<ConstDef> constDefs;

    public ConstDecl(ArrayList<ConstDef> constDefs, BType bType) {
        this.bType =bType;
        this.constDefs = constDefs;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("CONSTTK" + " const" + "\n");
        stringBuilder.append(bType.toPrint());
        if (! constDefs.isEmpty()) {
            for (ConstDef constDef : constDefs) {
                stringBuilder.append(constDef.toPrint());
                stringBuilder.append("COMMA" + " ," +  "\n");
            }
            stringBuilder.delete(stringBuilder.length() - 8, stringBuilder.length());
        }
        stringBuilder.append("SEMICN" + " ;" +  "\n");
        stringBuilder.append("<ConstDecl>\n");
        return stringBuilder.toString();
    }
}
