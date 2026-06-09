package frontend.SyntaxTree;

public class PrimaryExp {
    private Exp exp;
    private LVal lVal;
    private String number;
    private char character;

    public PrimaryExp() {
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    public void setLVal(LVal lVal) {
        this.lVal = lVal;
    }

    public void setNumber(String number) {
        this.number = number;
    }

    public void setCharacter(char character) {
        this.character = character;
    }
}
