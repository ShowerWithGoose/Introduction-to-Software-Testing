package parse;

import parse.Token;

import java.util.ArrayList;

public class ConstDecl implements DeclEle{
    private final String name = "<ConstDecl>";
    private Token constTk = null;
    private BType btype = null;
    private ConstDef firstword = null;
    private ArrayList<Token> departs = new ArrayList<Token>();
    private ArrayList<ConstDef> constDefs = new ArrayList<ConstDef>();
    private Token end = null;

    public String getName() {
        return name;
    }

    public Token getConstTk() {
        return constTk;
    }

    public void setConstTk(Token constTk) {
        this.constTk = constTk;
    }

    public BType getBtype() {
        return btype;
    }

    public void setBtype(BType btype) {
        this.btype = btype;
    }

    public ConstDef getFirstword() {
        return firstword;
    }

    public void setFirstword(ConstDef firstword) {
        this.firstword = firstword;
    }

    public ArrayList<Token> getDeparts() {
        return departs;
    }

    public void setDeparts(ArrayList<Token> departs) {
        this.departs = departs;
    }

    public ArrayList<ConstDef> getConstDefs() {
        return constDefs;
    }

    public void setConstDefs(ArrayList<ConstDef> constDefs) {
        this.constDefs = constDefs;
    }

    public Token getEnd() {
        return end;
    }

    public void setEnd(Token end) {
        this.end = end;
    }

    public ConstDecl(TokenList list,WrongList wrongs) {
        this.departs = new ArrayList<>();
        this.constDefs = new ArrayList<>();
        Token token = list.readNextToken();
        if (token.getType().equals("CONSTTK")) {
            constTk = token;
        }
        btype = new BType(list,wrongs);
        firstword = new ConstDef(list,wrongs);
        token = list.readNextToken();
        while (token.getType().equals("COMMA")) {
            this.departs.add(token);
            this.constDefs.add(new ConstDef(list,wrongs));
            token = list.readNextToken();
        }
        this.end = HandleError.handleI(token,list,wrongs);
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(constTk.printout());
        sb.append(btype.printout());
        sb.append(firstword.printout());
        if (departs != null && constDefs != null && departs.size() == constDefs.size()) {
            int len = departs.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.departs.get(i).printout());
                sb.append(this.constDefs.get(i).printout());
            }
        }
        sb.append(this.end.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
