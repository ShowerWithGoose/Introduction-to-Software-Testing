package parse;

import parse.Token;

import java.util.ArrayList;

public class ConstDef {
    private final String name = "<ConstDef>";
    private Ident ident;
    private ArrayList<Token> leftBraces;
    private ArrayList<ConstExp> constExps;
    private ArrayList<Token> rightBraces;
    private Token eq;
    private ConstInitVal constInitVal;

    public String getName() {
        return name;
    }

    public Ident getIdent() {
        return ident;
    }

    public void setIdent(Ident ident) {
        this.ident = ident;
    }

    public ArrayList<Token> getLeftBraces() {
        return leftBraces;
    }

    public void setLeftBraces(ArrayList<Token> leftBraces) {
        this.leftBraces = leftBraces;
    }

    public ArrayList<ConstExp> getConstExps() {
        return constExps;
    }

    public void setConstExps(ArrayList<ConstExp> constExps) {
        this.constExps = constExps;
    }

    public ArrayList<Token> getRightBraces() {
        return rightBraces;
    }

    public void setRightBraces(ArrayList<Token> rightBraces) {
        this.rightBraces = rightBraces;
    }

    public Token getEq() {
        return eq;
    }

    public void setEq(Token eq) {
        this.eq = eq;
    }

    public ConstInitVal getConstInitVal() {
        return constInitVal;
    }

    public void setConstInitVal(ConstInitVal constInitVal) {
        this.constInitVal = constInitVal;
    }

    public ConstDef (TokenList list,WrongList wrongs) {
        this.leftBraces = new ArrayList<>();
        this.constExps = new ArrayList<>();
        this.rightBraces = new ArrayList<>();
        ident = new Ident(list,wrongs);
        Token token = list.readNextToken();
        while (token.getType().equals("LBRACK")) {
            this.leftBraces.add(token);
            Token x = list.readNextToken();
            list.unReadToken(1);
            if(x.getType() != "ASSIGN"){
                ConstExp constExp =new ConstExp(list,wrongs);
                this.constExps.add(constExp);
            }
            token = list.readNextToken();
            this.rightBraces.add(HandleError.handleK(token,list,wrongs));
            token = list.readNextToken();
        }
        this.eq = token;
        this.constInitVal = new ConstInitVal(list,wrongs);
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ident.printout());
        if (this.leftBraces != null && this.rightBraces != null && this.constExps != null &&
            this.leftBraces.size() == this.constExps.size() &&
            this.constExps.size() == this.rightBraces.size()) {
            int len = leftBraces.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.leftBraces.get(i).printout());
                sb.append(this.constExps.get(i).printout());
                sb.append(this.rightBraces.get(i).printout());
            }
        }
        sb.append(this.eq.printout());
        sb.append(this.constInitVal.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
