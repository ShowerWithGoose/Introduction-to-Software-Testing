package parse;

import java.util.ArrayList;

public class InitVal {
    private final String name = "<InitVal>";
    private Token leftBrace = null;
    private Exp firstword = null;
    private ArrayList<Token> depart = new ArrayList<>();
    private ArrayList<Exp> initVals = new ArrayList<>();
    private Token rightBrace; 
    private InitValEle initValEle = null;

    public String getName() {
        return name;
    }

    public Token getLeftBrace() {
        return leftBrace;
    }

    public void setLeftBrace(Token leftBrace) {
        this.leftBrace = leftBrace;
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

    public ArrayList<Exp> getInitVals() {
        return initVals;
    }

    public void setInitVals(ArrayList<Exp> initVals) {
        this.initVals = initVals;
    }

    public Token getRightBrace() {
        return rightBrace;
    }

    public void setRightBrace(Token rightBrace) {
        this.rightBrace = rightBrace;
    }

    public InitValEle getInitValEle() {
        return initValEle;
    }

    public void setInitValEle(InitValEle initValEle) {
        this.initValEle = initValEle;
    }

    public InitVal(TokenList list,WrongList wrongs) {
        this.depart = new ArrayList<>();
        this.initVals = new ArrayList<>();
        this.leftBrace = list.readNextToken();
        if (!this.leftBrace.getType().equals("LBRACE")) {
            list.unReadToken(1);
            this.leftBrace = null;
            Token token = list.readNextToken();
            list.unReadToken(1);
            if(token.getType().equals("STRCON")){
                this.initValEle = new StringConst(list,wrongs);
            }
            else {
                this.initValEle = new Exp(list,wrongs);
            }
        }  else {
            Token token = list.readNextToken();
            if (!token.getType().equals("RBRACE")) {
                list.unReadToken(1);
                this.firstword = new Exp(list,wrongs);
                token = list.readNextToken();
                while (token.getType().equals("COMMA")) {
                    this.depart.add(token);
                    this.initVals.add(new Exp(list,wrongs));
                    token = list.readNextToken();
                }
            }
            this.rightBrace = token;
        }
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        if(this.leftBrace == null){
            sb.append(this.initValEle.printout());
            sb.append(this.name + "\n");
            return sb.toString();
        }
        else{
            sb.append(this.leftBrace.printout());
            if (firstword != null) {
                sb.append(this.firstword.printout());
                if (this.depart != null && this.initVals != null &&
                        this.depart.size() == this.initVals.size()) {
                    int len = this.depart.size();
                    for (int i = 0; i < len; i++) {
                        sb.append(this.depart.get(i).printout());
                        sb.append(this.initVals.get(i).printout());
                    }
                }
            }
            sb.append(this.rightBrace.printout());
            sb.append(this.name + "\n");
            return sb.toString();
        }

    }

}
