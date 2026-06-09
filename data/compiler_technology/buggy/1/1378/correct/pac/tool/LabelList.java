package pac.tool;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.TreeMap;

public class LabelList {
    protected ArrayList<Label> list = new ArrayList<>();
    protected ArrayList<Integer> line = new ArrayList<>();
    protected TreeMap<Integer, Character> error=new TreeMap<>();
    protected boolean err;

    protected void addList(Label tmp) {
        list.add(tmp);
        line.add(tmp.getLine());
        if(tmp.getError()!=null)
            error.putAll(tmp.getError());
    }

    public TreeMap<Integer, Character> getError() {
        return error;
    }

    public boolean isErr() {
        return err;
    }

    public int getLine() {
        return line.get(line.size() - 1);
    }
}
