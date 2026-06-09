package frontend.parser.ast.decl;

import frontend.lexer.Token;

import java.util.ArrayList;

public class ConstDecl implements Declaration {
    private String type = "<ConstDecl>";
    private Token constTK;
    private BType bType;
    private ConstDef firstDef;
    private ArrayList<Token> commas;
    private ArrayList<ConstDef> defs;
    private Token semicolon;
    private String error;

    public ConstDecl(Token constTK, BType bType, ConstDef firstDef, Token semicolon) {
        this.constTK = constTK;
        this.bType = bType;
        this.firstDef = firstDef;
        this.commas = null;
        this.defs = null;
        this.semicolon = semicolon;
        this.error = "";

        if (semicolon == null) {
            this.error = firstDef.getLineno() + " i\n";
        }
    }
    
    public ConstDecl(Token constTK, BType bType, ConstDef firstDef, ArrayList<Token> commas, ArrayList<ConstDef> defs, Token semicolon) {
        this.constTK = constTK;
        this.bType = bType;
        this.firstDef = firstDef;
        this.commas = commas;
        this.defs = defs;
        this.semicolon = semicolon;
        this.error = "";

        if (semicolon == null) {
            this.error = firstDef.getLineno() + " i\n";
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(constTK.getOutput());
        out.append(bType.getOutput());
        out.append(firstDef.getOutput());
        if (commas != null) {
            for (int i = 0; i < commas.size(); ++i) {
                out.append(commas.get(i).getOutput());
                out.append(defs.get(i).getOutput());
            }
        }
        if (semicolon != null) {
            out.append(semicolon.getOutput());
        }
        out.append(type + "\n");
        return out.toString();
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        out.append(firstDef.getError());
        if (defs != null && !defs.isEmpty()) {
            for (ConstDef def : defs) {
                out.append(def.getError());
            }
        }
        out.append(error);
        return out.toString();
    }

}
