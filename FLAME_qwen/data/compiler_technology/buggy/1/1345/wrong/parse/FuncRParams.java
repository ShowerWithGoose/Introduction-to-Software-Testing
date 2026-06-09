package parse;

import parse.Token;

import java.util.ArrayList;

public class FuncRParams {
    private final String name = "<FuncRParams>";
    private Exp firstword;
    private ArrayList<Token> depart;
    private ArrayList<Exp> exps;

    public String getName() {
        return name;
    }

    public Exp getFirstword() {
        return firstword;
    }

    public void setFirstword(Exp firstword) {
        this.firstword = firstword;
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

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstword.printout());
        if (depart != null && exps != null && depart.size() == exps.size()) {
            int len = depart.size();
            for (int i = 0; i < len; i++) {
                sb.append(depart.get(i).printout());
                sb.append(exps.get(i).printout());
            }
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }

    public FuncRParams(TokenList list,WrongList wrongs) {
        this.depart = new ArrayList<>();
        this.exps = new ArrayList<>();
        firstword = new Exp(list,wrongs);
        Token token = list.readNextToken();
        while (token.getType().equals("COMMA")) {
            this.depart.add(token);
            this.exps.add(new Exp(list,wrongs));
            token = list.readNextToken();
        }
        list.unReadToken(1);
    }
}
