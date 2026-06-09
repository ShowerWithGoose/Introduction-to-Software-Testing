package frontend;

import java.util.ArrayList;

public class VarDecl implements Decl {
    // BType VarDef { ',' VarDef } ';'
    // 可能出现i错误，缺分号
    private BType bType;
    private ArrayList<VarDef> varDefs = new ArrayList<>();
    private ArrayList<Word> words = new ArrayList<>();
    private int wrong = 0;

    public VarDecl() {}
    public void addWord(Word word) {
        words.add(word);
    }

    public void addDef(VarDef def) {
        varDefs.add(def);
    }

    public void setbType(BType bType) {
        this.bType = bType;
    }

    public void setWrong() {
        this.wrong = 1;
        varDefs.get(varDefs.size() - 1).setWordWrong(-1);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        sb.append(bType.toString());
        sb.append(varDefs.get(0).toString());
        if (varDefs.size() != 1) {
            for (;(pos + 1) < varDefs.size();pos++) {
                sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
                sb.append(varDefs.get(pos + 1).toString());
            }
        }
        if (wrong == 0) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
        }
        sb.append("<VarDecl>");
        sb.append("\n");
        return sb.toString();
    }
}
