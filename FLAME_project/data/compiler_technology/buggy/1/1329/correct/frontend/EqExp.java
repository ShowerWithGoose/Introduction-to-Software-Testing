package frontend;

import java.util.ArrayList;

public class EqExp {
    // RelExp | EqExp ('==' | '!=') RelExp
    private ArrayList<RelExp> relExps = new ArrayList<>();
    private ArrayList<Word> words = new ArrayList<>();

    public EqExp() {
    }

    public void addWord(Word word) {
        words.add(word);
    }

    public void setWordWrong(int type) {
        relExps.get(relExps.size() - 1).setWordWrong(type);
    }

    public void addRelExp(RelExp relExp) {
        relExps.add(relExp);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        sb.append(relExps.get(pos++).toString());
        sb.append("<EqExp>");
        sb.append("\n");
        for (;pos < relExps.size();pos++) {
            sb.append(words.get(pos - 1).getLeiBie()).append(" ").append(words.get(pos - 1).getStr()).append("\n");
            sb.append(relExps.get(pos).toString());
            sb.append("<EqExp>");
            sb.append("\n");
        }
        return sb.toString();
    }
}
