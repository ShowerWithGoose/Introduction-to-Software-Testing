package frontend;

import java.util.ArrayList;

public class LVal {
    // Ident ['[' Exp ']']
    // 可能出现k错误，缺右中括号
    private ArrayList<Word> words = new ArrayList<>();
    private Exp exp;
    private int wrong = 0;

    public LVal() {}

    public void addWord(Word word) {
        words.add(word);
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    public void setWrong() {
        this.wrong = 1;
        exp.setWordWrong(-3);
    }

    public void setWordWrong(int type) {
        if (wrong == 0) {
            words.get(words.size() - 1).setRight(type);
        } else {
            exp.setWordWrong(type);
        }
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
        if (words.size() > 1) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            sb.append(exp.toString());
            if (wrong == 0) {
                sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            }
        }
        sb.append("<LVal>");
        sb.append("\n");
        return sb.toString();
    }
}
