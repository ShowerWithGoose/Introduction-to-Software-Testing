package parse;

import java.util.ArrayList;

public class StmtPrint implements StmtEle {
    private Token printf; 
    private Token leftParent; 
    private StringConst stringConst;
    private ArrayList<Token> depart; 
    private ArrayList<Exp> exps;
    private Token rightParent; 
    private Token end;

    public Token getPrintf() {
        return printf;
    }

    public void setPrintf(Token printf) {
        this.printf = printf;
    }

    public Token getLeftParent() {
        return leftParent;
    }

    public void setLeftParent(Token leftParent) {
        this.leftParent = leftParent;
    }

    public StringConst getStringConst() {
        return stringConst;
    }

    public void setStringConst(StringConst stringConst) {
        this.stringConst = stringConst;
    }

    public ArrayList<Token> getDepart() {
        return depart;
    }

    public void setDepart(ArrayList<Token> depart) {
        this.depart = depart;
    }

    public ArrayList<Exp> getExps() {
        return exps;
    }

    public void setExps(ArrayList<Exp> exps) {
        this.exps = exps;
    }

    public Token getRightParent() {
        return rightParent;
    }

    public void setRightParent(Token rightParent) {
        this.rightParent = rightParent;
    }

    public Token getEnd() {
        return end;
    }

    public void setEnd(Token end) {
        this.end = end;
    }

    public StmtPrint(TokenList list,WrongList wrongs) {
        this.depart = new ArrayList<>();
        this.exps = new ArrayList<>();
        this.printf = list.readNextToken();
        this.leftParent = list.readNextToken();
        this.stringConst = new StringConst(list,wrongs);
        Token token = list.readNextToken();
        while (token.getType().equals("COMMA")) {
            this.depart.add(token);
            this.exps.add(new Exp(list,wrongs));
            token = list.readNextToken();
        }
        this.rightParent = HandleError.handleJ(token,list,wrongs);
        this.end = HandleError.handleI(list.readNextToken(),list,wrongs);
    }

    @Override
    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.printf.printout());
        sb.append(this.leftParent.printout());
        sb.append(this.stringConst.printout());
        if (this.depart != null && this.exps != null &&
                this.depart.size() == this.exps.size()) {
            int len = this.depart.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.depart.get(i).printout());
                sb.append(this.exps.get(i).printout());
            }
        }
        sb.append(this.rightParent.printout());
        sb.append(this.end.printout());
        return sb.toString();
    }
}
