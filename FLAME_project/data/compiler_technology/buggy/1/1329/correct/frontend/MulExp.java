package frontend;

import java.util.ArrayList;

public class MulExp {
    // UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    private ArrayList<Word> words = new ArrayList<>();
    private ArrayList<UnaryExp> unaryExps = new ArrayList<>();

    public MulExp() {}

    public void addWord(Word word) {
        words.add(word);
    }

    public void setWordWrong(int type) {
        unaryExps.get(unaryExps.size() - 1).setWordWrong(type);
    }

    public void addUnaryExp(UnaryExp unaryExp) {
        unaryExps.add(unaryExp);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        sb.append(unaryExps.get(pos++).toString());
        sb.append("<MulExp>");
        sb.append("\n");
        for (;pos < unaryExps.size();pos++) {
            sb.append(words.get(pos - 1).getLeiBie()).append(" ").append(words.get(pos - 1).getStr()).append("\n");
            sb.append(unaryExps.get(pos).toString());
            sb.append("<MulExp>");
            sb.append("\n");
        }
        return sb.toString();
    }
}
