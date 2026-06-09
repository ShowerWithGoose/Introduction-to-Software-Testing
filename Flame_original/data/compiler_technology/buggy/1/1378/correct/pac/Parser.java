package pac;

import pac.tool.*;

import java.io.OutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.TreeMap;

public class Parser {
    private final Lex lexer;
    private Label top;
    private TreeMap<Integer, Character> error;

    public Parser(ArrayList<Pair<TOKEN, String>> lexer, ArrayList<Integer> line, TreeMap<Integer, Character> error) {
        this.lexer = new Lex(lexer, line);
        this.error = error;
    }

    public void work() {
        top = new CompUnit(lexer);
        error.putAll(top.getError());
    }

    public void print(OutputStream out, OutputStream err) {
        if (top.getError().isEmpty()) {
            top.print(new PrintStream(out));
        } else {
            PrintStream prt = new PrintStream(err);
            for (int t : error.keySet()) {
                prt.println(t + " " + error.get(t));
            }
        }
    }
}
