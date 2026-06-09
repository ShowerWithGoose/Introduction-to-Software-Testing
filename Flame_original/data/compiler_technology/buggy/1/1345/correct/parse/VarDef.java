package parse;

import parse.Token;

import java.util.ArrayList;

public class VarDef implements VarDefEle{
    private final String name = "<VarDef>";
    private Ident ident;
    private ArrayList<Token> leftBraces;
    private ArrayList<ConstExp> constExps;
    private ArrayList<Token> rightBraces; 
    private Token eq;
    private InitVal initVal;

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

    public InitVal getInitVal() {
        return initVal;
    }

    public void setInitVal(InitVal initVal) {
        this.initVal = initVal;
    }


    public VarDef(TokenList list,WrongList wrongs) {
        this.leftBraces = new ArrayList<>();
        this.constExps = new ArrayList<>();
        this.rightBraces = new ArrayList<>();
        this.ident = new Ident(list,wrongs);
        Token token = list.readNextToken();
        while (token.getType().equals("LBRACK")) {
            this.leftBraces.add(token);
            Token x = list.readNextToken();
            list.unReadToken(1);
            if(x.getType() != "ASSIGN"){
                this.constExps.add(new ConstExp(list,wrongs));
            }
            token = list.readNextToken();
            this.rightBraces.add(HandleError.handleK(token,list,wrongs));
            token = list.readNextToken();
        }
        if (token.getType().equals("ASSIGN")) {
            this.eq = token;
            this.initVal = new InitVal(list,wrongs);
        } else {
            this.eq = null;
            this.initVal = null;
            list.unReadToken(1);
        }
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.printout());
        if (leftBraces != null && constExps != null && rightBraces != null &&
                leftBraces.size() == constExps.size() && constExps.size() == rightBraces.size()) {
            int len = leftBraces.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.leftBraces.get(i).printout());
                sb.append(this.constExps.get(i).printout());
                sb.append(this.rightBraces.get(i).printout());
            }
        }
        if(eq != null){
            sb.append(this.eq.printout());
        }
        if(initVal != null){
            sb.append(this.initVal.printout());
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
