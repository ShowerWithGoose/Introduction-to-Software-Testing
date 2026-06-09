package parse;

public class Number implements PrimaryExpEle {
    private final String name = "<Number>";
    private IntConst intConst;

    public String getName() {
        return name;
    }

    public IntConst getIntConst() {
        return intConst;
    }

    public void setIntConst(IntConst intConst) {
        this.intConst = intConst;
    }

    public Number(TokenList list,WrongList wrongs) {
            this.intConst = new IntConst(list,wrongs);
        }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(intConst.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
