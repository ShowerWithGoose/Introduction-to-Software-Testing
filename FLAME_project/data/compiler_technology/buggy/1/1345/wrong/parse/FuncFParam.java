package parse;

import java.util.ArrayList;

public class FuncFParam {
    private final String name = "<FuncFParam>";
    private BType btype;
    private Ident ident;
    private ArrayList<Token> leftBraces = null;
    private ArrayList<Token> rightBraces = null;

    public String getName() {
        return name;
    }

    public BType getBtype() {
        return btype;
    }

    public void setBtype(BType btype) {
        this.btype = btype;
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

    public ArrayList<Token> getRightBraces() {
        return rightBraces;
    }

    public void setRightBraces(ArrayList<Token> rightBraces) {
        this.rightBraces = rightBraces;
    }


    public FuncFParam(TokenList list,WrongList wrongs) {
        this.leftBraces = new ArrayList<>();
        this.rightBraces = new ArrayList<>();
        this.btype = new BType(list,wrongs);
        this.ident = new Ident(list,wrongs);
        Token token = list.readNextToken();
        while (token.getType().equals("LBRACK")) {
            this.leftBraces.add(token);
            this.rightBraces.add(HandleError.handleK(list.readNextToken(),list,wrongs));
            token = list.readNextToken();
        }
        list.unReadToken(1);
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.btype.printout());
        sb.append(this.ident.printout());
        int len = this.leftBraces.size();
        for (int i = 0; i < len; i++) {
            sb.append(this.leftBraces.get(i).printout());
            sb.append(this.rightBraces.get(i).printout());
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
