package frontend;
import java.util.ArrayList;

public class FuncFParams {
    // FuncFParam { ',' FuncFParam }
    private ArrayList<FuncFParam> funcFParams = new ArrayList<>();
    private ArrayList<Word> words = new ArrayList<>();

    public FuncFParams() {}

    public void addWord(Word word) {
        words.add(word);
    }

    public void addFuncFParam(FuncFParam funcFParam) {
        funcFParams.add(funcFParam);
    }

    public void setWordWrong(int type) {
        funcFParams.get(funcFParams.size() - 1).setWordWrong(type);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        sb.append(funcFParams.get(pos++).toString());
        for (;pos < funcFParams.size();pos++) {
            sb.append(words.get(pos - 1).getLeiBie()).append(" ").append(words.get(pos - 1).getStr()).append("\n");
            sb.append(funcFParams.get(pos).toString());
        }
        sb.append("<FuncFParams>");
        sb.append("\n");
        return sb.toString();
    }
}
