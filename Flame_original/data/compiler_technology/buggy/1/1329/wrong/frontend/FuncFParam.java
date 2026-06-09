package frontend;
import java.util.ArrayList;

public class FuncFParam {
    // BType Ident ['[' ']']
    // 可能出现k错误，缺右中括号
    private BType bType;
    private ArrayList<Word> words = new ArrayList<>();
    private int wrong = 0;

    public FuncFParam() {}

    public void setbType(BType bType) {
        this.bType = bType;
    }

    public void addWord(Word word) {
        words.add(word);
    }

    public void setWrong() {
        this.wrong = 1;
        words.get(1).setRight(-3);
    }

    public void setWordWrong(int type) {
        words.get(words.size() - 1).setRight(type);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        sb.append(bType.toString());
        sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
        if (words.size() > 1) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            if (wrong == 0) {
                sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
            }
        }
        sb.append("<FuncFParam>");
        sb.append("\n");
        return sb.toString();
    }
}
