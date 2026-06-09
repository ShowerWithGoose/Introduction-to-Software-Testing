package frontend;

public class BType {
    //  'int' | 'char'
    // 不输出
    private Word btype;

    public BType(Word btype) {
        this.btype = btype;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(btype.getLeiBie()).append(" ").append(btype.getStr()).append("\n");
        return sb.toString();
    }
}
