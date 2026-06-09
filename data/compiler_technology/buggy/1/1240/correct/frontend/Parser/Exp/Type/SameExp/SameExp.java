package frontend.Parser.Exp.Type.SameExp;

import frontend.Lexer.LexType;

import java.util.ArrayList;

public abstract class SameExp<T> {
    protected final ArrayList<T> subExps;
    protected final ArrayList<LexType> ops;

    public SameExp(ArrayList<T> subExps, ArrayList<LexType> ops) {
        this.subExps = subExps;
        this.ops = ops;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(subExps.get(0).toString()).append("<").append(getClass().getSimpleName()).append(">\n");
        for (int index = 1; index < subExps.size(); index++) {
            sb.append(ops.get(index - 1).toString()).append(subExps.get(index).toString()).append("<").append(getClass().getSimpleName()).append(">\n");
        }
        return sb.toString();
    }
}
