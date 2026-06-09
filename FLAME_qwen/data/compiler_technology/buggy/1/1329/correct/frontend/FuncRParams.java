package frontend;
import java.util.ArrayList;

public class FuncRParams {
    // Exp { ',' Exp }
    private ArrayList<Exp> exps = new ArrayList<>();
    private ArrayList<Word> words = new ArrayList<>();

    public FuncRParams() {}

    public void addWord(Word word) {
        words.add(word);
    }

    public void addExp(Exp exp) {
        exps.add(exp);
    }

    public void setWordWrong(int type) {
        exps.get(exps.size() - 1).setWordWrong(type);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        sb.append(exps.get(pos++).toString());
        for (;pos < exps.size();pos++) {
            sb.append(words.get(pos - 1).getLeiBie()).append(" ").append(words.get(pos - 1).getStr()).append("\n");
            sb.append(exps.get(pos).toString());
        }
        sb.append("<FuncRParams>");
        sb.append("\n");
        return sb.toString();
    }
}
