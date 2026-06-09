package frontend;

import java.util.ArrayList;

public class FuncDef {
    // FuncType Ident '(' [FuncFParams] ')' Block
    // 可能出现j错误，缺右小括号
    private FuncType funcType;
    private FuncFParams funcFParams;
    private Block block;
    private ArrayList<Word> words = new ArrayList<>();
    private int wrong = 0;

    public FuncDef() {
        funcFParams = null;
    }

    public void setWrong() {
        this.wrong = 1;
        if (funcFParams != null) {
            funcFParams.setWordWrong(-2);
        } else {
            words.get(1).setRight(-2);
        }
    }

    public void addWord(Word word) {
        words.add(word);
    }

    public void setBlock(Block block) {
        this.block = block;
    }

    public void setFuncType(FuncType funcType) {
        this.funcType = funcType;
    }

    public void setFuncFParams(FuncFParams funcFParams) {
        this.funcFParams = funcFParams;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        sb.append(funcType.toString());
        sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
        sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
        if (funcFParams != null) {
            sb.append(funcFParams.toString());
        }
        if (wrong == 0) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
        }
        sb.append(block.toString());
        sb.append("<FuncDef>");
        sb.append("\n");
        return sb.toString();
    }
}
