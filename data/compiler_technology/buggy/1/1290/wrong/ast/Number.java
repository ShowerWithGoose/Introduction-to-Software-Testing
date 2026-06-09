package ast;

public class Number extends Symbol {

    public static Symbol of() {
        Symbol number = new Number();
        Symbol symbol;
        if ((symbol = IntConst.of()) == null) {
            return null;
        }
        number.add(symbol);
        return number;
    }

}
