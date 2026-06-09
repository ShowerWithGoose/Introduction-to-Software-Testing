package frontend.parser.ast.exp;

public class Exp {
    private String type = "<Exp>";
    private AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    public int getLineno() {
        return addExp.getLineno();
    }


    public String getOutput() {
        return addExp.getOutput() + type + "\n";
    }

    public String getError() {
        return addExp.getError();
    }
}
