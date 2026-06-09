package frontend.parser.expression;

public class ConstExp {
    private final String name = "<ConstExp>";
    private AddExp addExp;

    public ConstExp(AddExp addExp) {
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
