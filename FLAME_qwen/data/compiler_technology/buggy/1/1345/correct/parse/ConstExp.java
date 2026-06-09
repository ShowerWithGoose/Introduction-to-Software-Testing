package parse;

public class ConstExp implements ConstInitValEle{
    private final String name = "<ConstExp>";
    private AddExp addExp;

    public ConstExp(TokenList list,WrongList wrongs) {
        this.addExp = new AddExp(list,wrongs);
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
