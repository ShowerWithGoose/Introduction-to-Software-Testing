package frontend.parser.expression;

public class Exp {
    private final String name = "<Exp>";
    private AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    public int getLineno() {
        return addExp.getLineno();
    }

    public String getOutPut() {
        return addExp.getOutPut() + name + "\n";
    }

    public String getError() {
        return addExp.getError();
    }
}
