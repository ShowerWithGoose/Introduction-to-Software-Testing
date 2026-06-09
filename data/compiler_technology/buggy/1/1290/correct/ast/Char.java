package ast;

public class Char extends Symbol {

    public static Symbol of() {
        Symbol character = new Char();
        Symbol symbol;
        if ((symbol = CharConst.of()) == null) {
            return null;
        }
        character.add(symbol);
        return character;
    }

    public String toString() {
        return "<Character>\n";
    }

}
