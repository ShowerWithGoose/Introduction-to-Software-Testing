package parse;

import parse.Token;

import java.util.ArrayList;

public class VarDecl implements DeclEle{
    private final String name = "<VarDecl>";
    private BType btype;
    private VarDef firstword;
    private ArrayList<Token> depart;
    private ArrayList<VarDef> varDefs;
    private Token end;

    public String getName() {
        return name;
    }

    public BType getBtype() {
        return btype;
    }

    public void setBtype(BType btype) {
        this.btype = btype;
    }

    public VarDef getFirstword() {
        return firstword;
    }

    public void setFirstword(VarDef firstword) {
        this.firstword = firstword;
    }

    public ArrayList<Token> getDepart() {
        return depart;
    }

    public void setDepart(ArrayList<Token> depart) {
        this.depart = depart;
    }

    public ArrayList<VarDef> getVarDefs() {
        return varDefs;
    }

    public void setVarDefs(ArrayList<VarDef> varDefs) {
        this.varDefs = varDefs;
    }

    public Token getEnd() {
        return end;
    }

    public void setEnd(Token end) {
        this.end = end;
    }

    public VarDecl(TokenList list,WrongList wrongs) {
        this.depart = new ArrayList<>();
        this.varDefs = new ArrayList<>();
        this.btype =  new BType(list,wrongs);
        this.firstword = new VarDef(list,wrongs);
        Token token = list.readNextToken();
        while (token.getType().equals("COMMA")) {
            this.depart.add(token);
            this.varDefs.add(new VarDef(list,wrongs));
            token = list.readNextToken();
        }
        this.end = HandleError.handleI(token,list,wrongs);
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.btype.printout());
        sb.append(this.firstword.printout());
        if (this.depart != null && this.varDefs != null &&
                this.depart.size() == this.varDefs.size()) {
            int len = this.depart.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.depart.get(i).printout());
                sb.append(this.varDefs.get(i).printout());
            }
        }
        sb.append(this.end.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
