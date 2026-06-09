package frontend;

import java.util.ArrayList;

public class LOrExp {
    // LAndExp | LOrExp '||' LAndExp
    private ArrayList<Word> words = new ArrayList<>();
    private ArrayList<LAndExp> lAndExps = new ArrayList<>();

    public void setWordWrong(int type) {
        lAndExps.get(lAndExps.size() - 1).setWordWrong(type);
    }

    public LOrExp() {}

    public void addWord(Word word) {
        words.add(word);
    }

    public void addLAndExp(LAndExp lAndExp) {
        lAndExps.add(lAndExp);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        sb.append(lAndExps.get(pos++).toString());
        sb.append("<LOrExp>");
        sb.append("\n");
        for (;pos < lAndExps.size();pos++) {
            sb.append(words.get(pos - 1).getLeiBie()).append(" ").append(words.get(pos - 1).getStr()).append("\n");
            sb.append(lAndExps.get(pos).toString());
            sb.append("<LOrExp>");
            sb.append("\n");
        }
        return sb.toString();
    }
}
