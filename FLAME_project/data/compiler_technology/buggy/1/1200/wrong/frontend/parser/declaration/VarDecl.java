package frontend.parser.declaration;

import frontend.lexer.Token;

import java.util.ArrayList;

public class VarDecl implements Declaration {
    private final String name = "<VarDecl>";
    private BType bType;
    private VarDef firstDef;
    private ArrayList<Token> commas;
    private ArrayList<VarDef> defs;
    private Token semi;
    private String errorLog;

    public VarDecl(BType bType, VarDef firstDef, Token semi) {
        this.bType = bType;
        this.firstDef = firstDef;
        this.commas = null;
        this.defs = null;
        this.semi = semi;
        if (semi == null) {
            this.errorLog = firstDef.getLineno() + " i\n";
        } else {
            this.errorLog = "";
        }
    }

    public VarDecl(BType bType, VarDef firstDef
            , ArrayList<Token> commas, ArrayList<VarDef> defs, Token semi) {
        this.bType = bType;
        this.firstDef = firstDef;
        this.commas = commas;
        this.defs = defs;
        this.semi = semi;
        if (semi == null) {
            VarDef constDef1 = defs.get(defs.size() - 1);
            this.errorLog = constDef1.getLineno() + " i\n";
        } else {
            this.errorLog = "";
        }
    }

    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(bType.getOutPut());
        sb.append(firstDef.getOutPut());
        if (commas != null) {
            for (int i = 0; i < commas.size(); i++) {
                sb.append(commas.get(i).getOutPut());
                sb.append(defs.get(i).getOutPut());
            }
        }
        sb.append(semi.getOutPut());
        sb.append(name + "\n");
        return sb.toString();
    }

    public String getError() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstDef.getError());
        if (defs != null) {
            for (VarDef varDef : defs) {
                sb.append(varDef.getError());
            }
        }
        sb.append(errorLog);
        return sb.toString();
    }
}
