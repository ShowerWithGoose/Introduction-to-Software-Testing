package frontend;

import java.util.ArrayList;

public class AddExp {
    // MulExp | AddExp ('+' | 'âˆ’') MulExp
    private ArrayList<MulExp> mulExps = new ArrayList<>();
    private ArrayList<Word> words = new ArrayList<>();

    public AddExp() {}

    public void addWord(Word word) {
        words.add(word);
    }

    public void addMulExp(MulExp mulExp) {
        mulExps.add(mulExp);
    }

    public void setWordWrong(int type) {
        mulExps.get(mulExps.size() - 1).setWordWrong(type);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        sb.append(mulExps.get(pos++).toString());
        sb.append("<AddExp>");
        sb.append("\n");
        for (;pos < mulExps.size();pos++) {
            sb.append(words.get(pos - 1).getLeiBie()).append(" ").append(words.get(pos - 1).getStr()).append("\n");
            sb.append(mulExps.get(pos).toString());
            sb.append("<AddExp>");
            sb.append("\n");
        }
        return sb.toString();
    }
}
