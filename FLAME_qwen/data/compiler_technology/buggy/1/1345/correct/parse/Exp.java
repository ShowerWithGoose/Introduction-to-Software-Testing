package parse;

public class Exp implements InitValEle{
    private final String name = "<Exp>";
    private AddExp addExp;

    public String getName() {
        return name;
    }

    public AddExp getAddExp() {
        return addExp;
    }

    public void setAddExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public Exp(TokenList list,WrongList wrongs) {
        addExp = new AddExp(list,wrongs);
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.addExp.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }

}
