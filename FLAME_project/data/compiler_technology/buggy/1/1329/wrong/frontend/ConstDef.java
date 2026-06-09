package frontend;
import java.util.ArrayList;

public class ConstDef {
    // Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    // 可能出现k错误，缺右中括号
    private ArrayList<Word> words = new ArrayList<>();
    private ConstExp constExp;
    private ConstInitVal constInitVal;
    private int wrong = 0;

    public ConstDef() {}

    public void setConstExp(ConstExp constExp) {
        this.constExp = constExp;
    }

    public void setConstInitVal(ConstInitVal constInitVal) {
        this.constInitVal = constInitVal;
    }

    public void addWord(Word word) {
        words.add(word);
    }

    public void setWrong() {
        this.wrong = 1;
        constExp.setWordWrong(-3);
    }

    public void setWordWrong(int type) {
        constInitVal.setWordWrong(type);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
        if (words.size() > 2) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            sb.append(constExp.toString());
            if (wrong == 0) {
                sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            }
        }
        sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
        sb.append(constInitVal.toString());
        sb.append("<ConstDef>");
        sb.append("\n");
        return sb.toString();
    }
}
