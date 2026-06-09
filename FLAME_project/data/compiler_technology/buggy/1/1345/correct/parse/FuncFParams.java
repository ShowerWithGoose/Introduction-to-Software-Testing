package parse;

import java.util.ArrayList;

public class FuncFParams {
    private final String name = "<FuncFParams>";
    private FuncFParam firstword;
    private ArrayList<Token> depart = null; 
    private ArrayList<FuncFParam> funcFParams = null;

    public String getName() {
        return name;
    }

    public FuncFParam getFirstword() {
        return firstword;
    }

    public void setFirstword(FuncFParam firstword) {
        this.firstword = firstword;
    }

    public ArrayList<Token> getDepart() {
        return depart;
    }

    public void setDepart(ArrayList<Token> depart) {
        this.depart = depart;
    }

    public ArrayList<FuncFParam> getFuncFParams() {
        return funcFParams;
    }

    public void setFuncFParams(ArrayList<FuncFParam> funcFParams) {
        this.funcFParams = funcFParams;
    }

    public FuncFParams(TokenList list,WrongList wrongs) {
        this.depart = new ArrayList<>();
        this.funcFParams = new ArrayList<>();
        this.firstword = new FuncFParam(list,wrongs);
        Token token = list.readNextToken();
        while (token.getType().equals("COMMA")) {
            this.depart.add(token);
            this.funcFParams.add(new FuncFParam(list,wrongs));
            token = list.readNextToken();
        }
        list.unReadToken(1);
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.firstword.printout());
        if (this.depart != null && this.funcFParams != null &&
                this.depart.size() == this.funcFParams.size()) {
            int len = this.depart.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.depart.get(i).printout());
                sb.append(this.funcFParams.get(i).printout());
            }
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
