package frontend;
import java.util.ArrayList;

public class InitVal {
    // Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    private ArrayList<Exp> exps = new ArrayList<>();
    private ArrayList<Word> words = new ArrayList<>();// 0 duo 1

    public InitVal() {}

    public void addExp(Exp exp) {
        exps.add(exp);
    }

    public void addWord(Word word) {
        words.add(word);
    }

    public void setWordWrong(int type) {
        if (!words.isEmpty()) {
            words.get(words.size() - 1).setRight(type);
        } else {
            exps.get(0).setWordWrong(type);
        }
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        if (words.isEmpty()) {
            sb.append(exps.get(pos).toString());
        } else if (words.size() == 1) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
        } else {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            if (!exps.isEmpty()) {
                sb.append(exps.get(0).toString());
                for (;pos < exps.size();pos++) {
                    sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
                    sb.append(exps.get(pos).toString());
                }
            }
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
        }
        sb.append("<InitVal>");
        sb.append("\n");
        return sb.toString();
    }
}
