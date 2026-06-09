package frontend.parser.declaration;

import frontend.lexer.Token;

import java.util.ArrayList;

public class ConstDecl implements Declaration {
    private final String name = "<ConstDecl>";
    private Token constTK;
    private BType bType;
    private ConstDef firstDef;
    private ArrayList<Token> commas;
    private ArrayList<ConstDef> defs;
    private Token semi;
    private String errorLog;

    public ConstDecl(Token constTK, BType bType, ConstDef firstDef, Token semi) {
        this.constTK = constTK;
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

    public ConstDecl(Token constTK, BType bType, ConstDef firstDef
            , ArrayList<Token> commas, ArrayList<ConstDef> defs, Token semi) {
        this.constTK = constTK;
        this.bType = bType;
        this.firstDef = firstDef;
        this.commas = commas;
        this.defs = defs;
        this.semi = semi;
        if (semi == null) {
            ConstDef constDef1 = defs.get(defs.size() - 1);
            this.errorLog = constDef1.getLineno() + " i\n";
        } else {
            this.errorLog = "";
        }
    }

    @Override
    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(constTK.getOutPut());
        sb.append(bType.getOutPut());
        sb.append(firstDef.getOutPut());
        if (commas != null) {
            for (int i = 0; i < commas.size(); i++) {
                sb.append(commas.get(i).getOutPut());
                sb.append(defs.get(i).getOutPut());
            }
        }
        if (semi != null) {
            sb.append(semi.getOutPut());
        }
        sb.append(name + "\n");
        return sb.toString();
    }

    @Override
    public String getError() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstDef.getError());
        if (defs != null && !defs.isEmpty()) {
            for (ConstDef constDef : defs) {
                sb.append(constDef.getError());
            }
        }
        sb.append(errorLog);
        return sb.toString();
    }
}
