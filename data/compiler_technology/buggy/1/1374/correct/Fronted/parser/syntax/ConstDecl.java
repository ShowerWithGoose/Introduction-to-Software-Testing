package Fronted.parser.syntax;

import Fronted.lexer.Token;

import java.util.ArrayList;

//ConstDecl â†’ 'const' BType ConstDef { ',' ConstDef } ';' // i
public class ConstDecl {
    private static final String name = "<ConstDecl>";

    private Token constToken = null;

    private BType bType;

    private ArrayList<ConstDef> constDefList;

    private ArrayList<Token> commaList;

    private Token semicn;

    public ConstDecl(Token constToken, BType bType, ArrayList<ConstDef> constDefList, ArrayList<Token> commaList, Token semicn) {
        this.constToken = constToken;
        this.bType = bType;
        this.constDefList = constDefList;
        this.commaList = commaList;
        this.semicn = semicn;
    }

    @Override
    public String toString(){
        StringBuilder out = new StringBuilder();
        out.append(constToken.toString());
        out.append(bType.toString());
        for(int i = 0; i < constDefList.size(); i++){
            if(i > 0) out.append(commaList.get(i-1).toString());
            out.append(constDefList.get(i).toString());
        }
        if (semicn != null) out.append(semicn.toString());
        out.append(name).append("\n");
        return out.toString();
    }

    public Token getConstToken() {
        return constToken;
    }

    public BType getbType() {
        return bType;
    }

    public ArrayList<ConstDef> getConstDefList() {
        return constDefList;
    }

    public ArrayList<Token> getCommaList() {
        return commaList;
    }

    public Token getSemicn() {
        return semicn;
    }

    public void setConstToken(Token constToken) {
        this.constToken = constToken;
    }

    public void setbType(BType bType) {
        this.bType = bType;
    }

    public void setConstDefList(ArrayList<ConstDef> constDefList) {
        this.constDefList = constDefList;
    }

    public void setCommaList(ArrayList<Token> commaList) {
        this.commaList = commaList;
    }

    public void setSemicn(Token semicn) {
        this.semicn = semicn;
    }

}
