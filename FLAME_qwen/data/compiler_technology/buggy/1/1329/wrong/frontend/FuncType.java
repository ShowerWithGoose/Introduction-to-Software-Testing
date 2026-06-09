package frontend;

public class FuncType {
    //  'void' | 'int' | 'char'
    private Word funcType;

    public FuncType(Word word) {
        this.funcType = word;
    }

    public String toString() {
        return funcType.getLeiBie() + " " + funcType.getStr() + "\n" + "<FuncType>" + "\n";
    }
}
