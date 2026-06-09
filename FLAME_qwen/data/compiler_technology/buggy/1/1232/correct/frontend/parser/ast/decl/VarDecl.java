package frontend.parser.ast.decl;

import frontend.lexer.Token;

import java.util.ArrayList;   

public class VarDecl implements Declaration {
    private String type = "<VarDecl>";
    private BType bType;
    private VarDef firstDef;
    private ArrayList<Token> commas;
    private ArrayList<VarDef> varDefs;
    private Token semicolon;
    private String error;

    public VarDecl(BType bType, VarDef firstDef, ArrayList<Token> commas, ArrayList<VarDef> varDefs, Token semicolon) {
        this.bType = bType;
        this.firstDef = firstDef;
        this.commas = commas;
        this.varDefs = varDefs;
        this.semicolon = semicolon;
        this.error = "";
        if (semicolon == null) {
            this.error = varDefs.get(varDefs.size() - 1).getLineno() + " i\n";
        }
    }

    public VarDecl(BType bType, VarDef firstDef, Token semicolon) {
        this.bType = bType;
        this.firstDef = firstDef;
        this.commas = null;
        this.varDefs = null;
        this.semicolon = semicolon;
        this.error = "";
        if (semicolon == null) {
            this.error = firstDef.getLineno() + " i\n";
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(bType.getOutput());
        out.append(firstDef.getOutput());
        if (varDefs!= null) {
            for (int i = 0; i < varDefs.size(); ++i) {
                out.append(commas.get(i).getOutput());
                out.append(varDefs.get(i).getOutput());
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
        if (varDefs != null) {
            for (VarDef varDef : varDefs) {
                out.append(varDef.getError());
            }
        }
        out.append(error);
        return out.toString();
    }

}
