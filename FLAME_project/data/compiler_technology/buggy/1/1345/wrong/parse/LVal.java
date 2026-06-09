package parse;

import parse.Token;

import java.util.ArrayList;

public class LVal implements PrimaryExpEle {
    private final String name = "<LVal>";
    private Ident ident;
    private ArrayList<Token> leftBraces;
    private ArrayList<Exp> exps;
    private ArrayList<Token> rightBraces;

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

    public ArrayList<Exp> getExps() {
        return exps;
    }

    public void setExps(ArrayList<Exp> exps) {
        this.exps = exps;
    }

    public ArrayList<Token> getRightBraces() {
        return rightBraces;
    }

    public void setRightBraces(ArrayList<Token> rightBraces) {
        this.rightBraces = rightBraces;
    }

    public LVal(TokenList list,WrongList wrongs) {
        this.leftBraces = new ArrayList<>();
        this.exps = new ArrayList<>();
        this.rightBraces = new ArrayList<>();
        this.ident = new Ident(list,wrongs);
        Token token = list.readNextToken();
        while (token.getType().equals("LBRACK")) {
            this.leftBraces.add(token);
            Token x = list.readNextToken();
            list.unReadToken(1);
            if(x.getType() != "ASSIGN"){
                this.exps.add(new Exp(list,wrongs));
            }
            token = list.readNextToken();
            this.rightBraces.add(HandleError.handleK(token,list,wrongs));
            token = list.readNextToken();
        }
        list.unReadToken(1);
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.printout());
        if (leftBraces != null && exps != null && rightBraces != null &&
                leftBraces.size() == exps.size() && exps.size() == rightBraces.size()) {
            int len = leftBraces.size();
            for (int i = 0; i < len; i++) {
                sb.append(leftBraces.get(i).printout());
                sb.append(exps.get(i).printout());
                sb.append(rightBraces.get(i).printout());
            }
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
