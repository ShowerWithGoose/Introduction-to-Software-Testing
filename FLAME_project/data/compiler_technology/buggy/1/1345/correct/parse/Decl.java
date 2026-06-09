package parse;

import parse.Token;

public class Decl implements BlockItemEle {
    private final String name = "<Decl>";
    private DeclEle declEle;

    public String getName() {
        return name;
    }

    public DeclEle getDeclEle() {
        return declEle;
    }

    public void setDeclEle(DeclEle declEle) {
        this.declEle = declEle;
    }

    public Decl(TokenList list,WrongList wrongs) {
        Token x = list.readNextToken();
        list.unReadToken(1);
        declEle = null;
        if (x.getType().equals("CONSTTK")) {
            declEle = new ConstDecl(list,wrongs);
        } else if (x.getType().equals("INTTK")||x.getType().equals("CHARTK")) {
            declEle = new VarDecl(list,wrongs);
        }
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.declEle.printout());
        return sb.toString();
    }

}