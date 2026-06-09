package Fronted.parser.syntax;

import Fronted.lexer.Token;

import java.util.ArrayList;

//  ConstInitVal â†’ ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
public class ConstInitVal {
    private static final String name = "<ConstInitVal>";

    private Token lbrace = null;

    private ArrayList<ConstExp> constExpList = null;

    private ArrayList<Token> commaList = null;

    private Token rbrace = null;

    private Token strcon = null;

    public ConstInitVal(ArrayList<ConstExp> constExpList) {
        this.constExpList = constExpList;
    }

    public ConstInitVal(Token lbrace, ArrayList<ConstExp> constExpList, ArrayList<Token> commaList, Token rbrace) {
        this.lbrace = lbrace;
        this.constExpList = constExpList;
        this.commaList = commaList;
        this.rbrace = rbrace;
    }

    public ConstInitVal(Token strcon) {
        this.strcon = strcon;
    }

    @Override
    public String toString(){
        StringBuilder out = new StringBuilder();
        if(lbrace!= null){
            out.append(lbrace);
            for(int i = 0; i < constExpList.size(); i++){
                if(i > 0) out.append(commaList.get(i-1));
                out.append(constExpList.get(i));
            }
            out.append(rbrace);
        } else if(strcon!= null){
            out.append(strcon);
        } else {
            out.append(constExpList.get(0));
        }
        out.append(name).append("\n");
        return out.toString();
    }

    public Token getLbrace() {
        return lbrace;
    }

    public ArrayList<ConstExp> getConstExpList() {
        return constExpList;
    }

    public ArrayList<Token> getCommaList() {
        return commaList;
    }

    public Token getRbrace() {
        return rbrace;
    }

    public Token getStrcon() {
        return strcon;
    }

    public void setLbrace(Token lbrace) {
        this.lbrace = lbrace;
    }

    public void setConstExpList(ArrayList<ConstExp> constExpList) {
        this.constExpList = constExpList;
    }

    public void setCommaList(ArrayList<Token> commaList) {
        this.commaList = commaList;
    }

    public void setRbrace(Token rbrace) {
        this.rbrace = rbrace;
    }

    public void setStrcon(Token strcon) {
        this.strcon = strcon;
    }
}
