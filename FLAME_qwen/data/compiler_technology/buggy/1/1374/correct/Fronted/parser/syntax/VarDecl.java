package Fronted.parser.syntax;

import Fronted.lexer.Token;

import java.util.ArrayList;

//  VarDecl â†’ BType VarDef { ',' VarDef } ';' // i
public class VarDecl {

    private static final String name = "<VarDecl>";

    private BType bType;

    private ArrayList<VarDef> varDefList;

    private ArrayList<Token> commaList;

    private Token semicn;

    public VarDecl(BType bType, ArrayList<VarDef> varDefList, ArrayList<Token> commaList, Token semicn) {
        this.bType = bType;
        this.varDefList = varDefList;
        this.commaList = commaList;
        this.semicn = semicn;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(bType);
        for (int i = 0; i < varDefList.size(); i++) {
            if (i > 0) {
                out.append(commaList.get(i - 1));
            }
            out.append(varDefList.get(i));
        }
        out.append(semicn);
        out.append(name).append("\n");
        return out.toString();
    }

    public BType getbType() {
        return bType;
    }

    public ArrayList<VarDef> getVarDefList() {
        return varDefList;
    }

    public ArrayList<Token> getCommaList() {
        return commaList;
    }

    public Token getSemicn() {
        return semicn;
    }

    public void setbType(){
        this.bType = bType;
    }

    public void setVarDefList(){
        this.varDefList = varDefList;
    }

    public void setCommaList(){
        this.commaList = commaList;
    }

    public void setSemicn(){
        this.semicn = semicn;
    }
}
