package frontend;

import java.util.ArrayList;

public class VarDef {
    // Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
    // 可能出现k错误，缺右中括号
    private ConstExp constExp;
    private InitVal initVal;
    private ArrayList<Word> words = new ArrayList<>();
    private int wrong = 0;

    public VarDef() {}

    public void addWord(Word word) {
        words.add(word);
    }

    public void setWrong() {
        this.wrong = 1;
        constExp.setWordWrong(-3);
    }

    public void setInitVal(InitVal initVal) {
        this.initVal = initVal;
    }

    public void setConstExp(ConstExp constExp) {
        this.constExp = constExp;
    }

    public void setWordWrong(int type) {
        if (words.size() == 4 || (words.size() == 3 && wrong == 1) ||
                (words.size() == 2 && wrong == 0)) {
            initVal.setWordWrong(type);
        } else {
            if (words.size() == 1) {
                words.get(0).setRight(type);
            } else {
                if (wrong == 0) {
                    words.get(2).setRight(type);
                } else {
                    constExp.setWordWrong(type);
                }
            }
        }
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
        if (words.size() == 2 && wrong == 0) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
            sb.append(initVal.toString());
        } else if (words.size() == 2 && wrong == 1) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
            sb.append(constExp.toString());
        } else if (words.size() == 3) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            sb.append(constExp.toString());
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
        } else if (words.size() != 1) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            sb.append(constExp.toString());
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
            sb.append(initVal.toString());
        }
        sb.append("<VarDef>");
        sb.append("\n");
        return sb.toString();
    }
}
