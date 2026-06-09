package frontend;

import java.util.ArrayList;

public class RelExp {
    // AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    private ArrayList<Word> words = new ArrayList<>();
    private ArrayList<AddExp> addExps = new ArrayList<>();

    public RelExp() {}

    public void setWordWrong(int type) {
        addExps.get(addExps.size() - 1).setWordWrong(type);
    }

    public void addWord(Word word) {
        words.add(word);
    }

    public void addAddExp(AddExp addExp) {
        addExps.add(addExp);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        sb.append(addExps.get(pos++).toString());
        sb.append("<RelExp>");
        sb.append("\n");
        for (;pos < addExps.size();pos++) {
            sb.append(words.get(pos - 1).getLeiBie()).append(" ").append(words.get(pos - 1).getStr()).append("\n");
            sb.append(addExps.get(pos).toString());
            sb.append("<RelExp>");
            sb.append("\n");
        }
        return sb.toString();
    }
}
