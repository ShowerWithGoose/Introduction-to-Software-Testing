package parse;

public class PrimaryExpp implements PrimaryExpEle {
    private Token leftBracks;
    private Exp exp;
    private Token rightBracks;

    public Token getLeftBracks() {
        return leftBracks;
    }

    public void setLeftBracks(Token leftBracks) {
        this.leftBracks = leftBracks;
    }

    public Exp getExp() {
        return exp;
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    public Token getRightBracks() {
        return rightBracks;
    }

    public void setRightBracks(Token rightBracks) {
        this.rightBracks = rightBracks;
    }

    public PrimaryExpp(TokenList list,WrongList wrongs) {
        this.leftBracks = list.readNextToken();
        this.exp = new Exp(list,wrongs);
        this.rightBracks = HandleError.handleJ(list.readNextToken(),list,wrongs);
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(leftBracks.printout());
        sb.append(exp.printout());
        sb.append(rightBracks.printout());
        return sb.toString();
    }
}
