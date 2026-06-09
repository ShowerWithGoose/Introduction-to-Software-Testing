package pac.tool;

import java.util.ArrayList;

public class Lex {
    private final ArrayList<Pair<TOKEN, String>> list;
    private final ArrayList<Integer> line;
    private int p;

    public Lex(ArrayList<Pair<TOKEN, String>> in, ArrayList<Integer> line) {
        list = in;
        this.line = line;
        p = 0;
    }

    public void next() {
        ++p;
    }

    public void pre() {
        --p;
    }


    public Pair<TOKEN, String> get() {
        return list.get(p);
    }

    public TOKEN getFirst() {
        return list.get(p).first;
    }

    public TOKEN getFirst(int i) {
        if (p + i < list.size())
            return list.get(p + i).first;
        else return TOKEN.ZERO;
    }

    public int getLine() {
        return line.get(p);
    }

    public int getP() {
        return p;
    }

    public void returnTo(int p) {
        this.p = p;
    }
}
