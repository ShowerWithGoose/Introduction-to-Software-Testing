package parse;

public class Characte implements PrimaryExpEle{
    private final String name = "<Character>";
    private CharConst charConst;

    public String getName() {
        return name;
    }

    public CharConst getCharConst() {
        return charConst;
    }

    public void setCharConst(CharConst charConst) {
        this.charConst = charConst;
    }

    public Characte(TokenList list,WrongList wrongs) {
        this.charConst = new CharConst(list,wrongs);
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(charConst.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}