package frontend;
import java.util.ArrayList;

public class ConstInitVal {
    // ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private ArrayList<ConstExp> constExps = new ArrayList<>();

    private ArrayList<Word> words = new ArrayList<>();// 0 duo 1

    public ConstInitVal() {
    }

    public void addConstExp(ConstExp constExp) {
        constExps.add(constExp);
    }

    public void addWord(Word word) {
        words.add(word);
    }

    public void setWordWrong(int type) {
        if (!words.isEmpty()) {
            words.get(words.size() - 1).setRight(type);
        } else {
            constExps.get(0).setWordWrong(type);
        }
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        if (words.isEmpty()) {
            sb.append(constExps.get(pos).toString());
        } else if (words.size() == 1) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
        } else {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            if (!constExps.isEmpty()) {
                sb.append(constExps.get(0).toString());
                for (;pos < constExps.size();pos++) {
                    sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
                    sb.append(constExps.get(pos).toString());
                }
            }
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
        }
        sb.append("<ConstInitVal>");
        sb.append("\n");
        return sb.toString();
    }
}
