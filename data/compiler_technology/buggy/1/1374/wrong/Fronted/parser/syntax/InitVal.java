package Fronted.parser.syntax;

import Fronted.lexer.Token;

import java.util.ArrayList;

// InitVal â†’ Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
public class InitVal {

    private final String name = "<InitVal>";

    private Token lbrace = null;

    private ArrayList<Exp> expList = null;

    private ArrayList<Token> commaList = null;

    private Token rbrace = null;

    private Token strcon = null;

    public InitVal(ArrayList<Exp> expList) {
        this.expList = expList;
    }

    public InitVal(Token lbrace, ArrayList<Exp> expList, ArrayList<Token> commaList, Token rbrace) {
        this.lbrace = lbrace;
        this.expList = expList;
        this.commaList = commaList;
        this.rbrace = rbrace;
    }

    public InitVal(Token strcon) {
        this.strcon = strcon;
    }

    @Override
    public String toString(){
        StringBuilder out = new StringBuilder();
        if(lbrace!= null){
            out.append(lbrace);
            for(int i = 0; i < expList.size(); i++){
                if(i > 0) out.append(commaList.get(i-1));
                out.append(expList.get(i));
            }
            out.append(rbrace);
        }
        else if(strcon!= null){
            out.append(strcon);
        } else {
            out.append(expList.get(0));
        }
        out.append(name).append("\n");
        return out.toString();
    }

    public Token getLbrace() {
        return lbrace;
    }

    public void setLbrace(Token lbrace) {
        this.lbrace = lbrace;
    }

    public ArrayList<Exp> getExpList() {
        return expList;
    }

    public void setExpList(ArrayList<Exp> expList) {
        this.expList = expList;
    }

    public ArrayList<Token> getCommaList() {
        return commaList;
    }

    public void setCommaList(ArrayList<Token> commaList) {
        this.commaList = commaList;
    }

    public Token getRbrace() {
        return rbrace;
    }

    public void setRbrace(Token rbrace) {
        this.rbrace = rbrace;
    }

    public Token getStrcon() {
        return strcon;
    }

    public void setStrcon(Token strcon) {
        this.strcon = strcon;
    }
}

