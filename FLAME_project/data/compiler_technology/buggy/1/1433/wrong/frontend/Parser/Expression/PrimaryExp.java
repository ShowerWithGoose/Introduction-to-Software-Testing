package frontend.Parser.Expression;

public class PrimaryExp implements unaryExpEle {
    private primaryExpEle primaryExpEle;

    public PrimaryExp(primaryExpEle primaryExpElement) {
        this.primaryExpEle = primaryExpElement;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(primaryExpEle.printString());
        sb.append("<" + "PrimaryExp" + ">\n");
        return sb.toString();
    }
}
