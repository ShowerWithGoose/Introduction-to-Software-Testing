package frontend;
import java.util.ArrayList;

public class ConstDecl implements Decl {
    // 'const' BType ConstDef { ',' ConstDef } ';'
    // 可能出现i错误，缺分号
    private BType bType;
    private ArrayList<ConstDef> constDefs = new ArrayList<>();
    private ArrayList<Word> words = new ArrayList<>();

    private int wrong = 0;

    public ConstDecl() {}

    public void addWord(Word word) {
        words.add(word);
    }

    public void addDef(ConstDef def) {
        constDefs.add(def);
    }

    public void setbType(BType bType) {
        this.bType = bType;
    }

    public void setWrong() {
        this.wrong = 1;
        constDefs.get(constDefs.size() - 1).setWordWrong(-1);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
        sb.append(bType.toString());
        sb.append(constDefs.get(0).toString());
        if (constDefs.size() != 1) {
            for (;pos < constDefs.size();pos++) {
                sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
                sb.append(constDefs.get(pos).toString());
            }
        }
        if (wrong == 0) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
        }
        sb.append("<ConstDecl>");
        sb.append("\n");
        return sb.toString();
    }
}
