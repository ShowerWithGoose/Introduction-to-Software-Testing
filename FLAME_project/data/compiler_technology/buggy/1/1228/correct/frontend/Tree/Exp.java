package frontend.Tree;

public class Exp {
    private AddExp addExp;
    private int type; //0是char，1是charArray，2是int，3是intArray

    public Exp(AddExp addExp, int type) {
        this.addExp = addExp;
        this.type = type;
    }

    public int getType() {
        return type;
    }
}
