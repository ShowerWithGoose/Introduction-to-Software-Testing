package frontend;

public class UnaryOp {
    // '+' | '−' | '!' 注：'!'仅出现在条件表达式中
    private Word op;

    public UnaryOp(Word op) {
        this.op = op;
    }

    public String toString() {
        return op.getLeiBie() + " " + op.getStr() + "\n" + "<UnaryOp>" + "\n";
    }
}
