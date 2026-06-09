package parse;

import parse.Token;

import java.util.ArrayList;

public class ConstInitValMulti implements ConstInitValEle{
    private Token leftBrace;
    private Token rightBrace; 
    private ConstExp firstword;
    private ArrayList<Token> depart; 
    private ArrayList<ConstExp> constInitVals;

    public Token getLeftBrace() {
        return leftBrace;
    }

    public void setLeftBrace(Token leftBrace) {
        this.leftBrace = leftBrace;
    }

    public Token getRightBrace() {
        return rightBrace;
    }

    public void setRightBrace(Token rightBrace) {
        this.rightBrace = rightBrace;
    }

    public ConstExp getFirstword() {
        return firstword;
    }

    public void setFirstword(ConstExp firstword) {
        this.firstword = firstword;
    }

    public ArrayList<Token> getDepart() {
        return depart;
    }

    public void setDepart(ArrayList<Token> depart) {
        this.depart = depart;
    }

    public ArrayList<ConstExp> getConstInitVals() {
        return constInitVals;
    }

    public void setConstInitVals(ArrayList<ConstExp> constInitVals) {
        this.constInitVals = constInitVals;
    }

    public ConstInitValMulti(TokenList list,WrongList wrongs) {
        this.depart = new ArrayList<Token>();
        this.constInitVals = new ArrayList<>();
        this.leftBrace = list.readNextToken();
        Token token = list.readNextToken();
        if (!token.getType().equals("RBRACE")) {
            list.unReadToken(1);
            this.firstword = new ConstExp(list,wrongs);
            token = list.readNextToken();
            while (token.getType().equals("COMMA")) {
                this.depart.add(token);
                this.constInitVals.add(new ConstExp(list,wrongs));
                token = list.readNextToken();
            }
            list.unReadToken(1);
        } else {
            list.unReadToken(1);
        }
        this.rightBrace = list.readNextToken();
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.leftBrace.printout());
        if (this.firstword != null) {
            sb.append(this.firstword.printout());
            if (this.depart != null && this.constInitVals != null
                    && this.depart.size() == this.constInitVals.size()) {
                int len = this.depart.size();
                for (int i = 0; i < len; i++) {
                    sb.append(this.depart.get(i).printout());
                    sb.append(this.constInitVals.get(i).printout());
                }
            }
        }
        sb.append(this.rightBrace.printout());
        return sb.toString();
    }
}
