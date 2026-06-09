package frontend;

import java.util.ArrayList;

public class LAndExp {
    // EqExp | LAndExp '&&' EqExp
    private ArrayList<EqExp> eqExps = new ArrayList<>();
    private ArrayList<Word> words = new ArrayList<>();

    public LAndExp() {}

    public void addWord(Word word) {
        words.add(word);
    }

    public void setWordWrong(int type) {
        eqExps.get(eqExps.size() - 1).setWordWrong(type);
    }

    public void addEqExp(EqExp eqExp) {
        eqExps.add(eqExp);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        sb.append(eqExps.get(pos++).toString());
        sb.append("<LAndExp>");
        sb.append("\n");
        for (;pos < eqExps.size();pos++) {
            sb.append(words.get(pos - 1).getLeiBie()).append(" ").append(words.get(pos - 1).getStr()).append("\n");
            sb.append(eqExps.get(pos).toString());
            sb.append("<LAndExp>");
            sb.append("\n");
        }
        return sb.toString();
    }
}
