package frontend;

import java.util.ArrayList;

public class MainFuncDef {
    // 'int' 'main' '(' ')' Block
    // 可能出现j错误，缺右小括号
    private Block block;
    private ArrayList<Word> words = new ArrayList<>();
    private int wrong = 0;

    public MainFuncDef() {}

    public void setBlock(Block block) {
        this.block = block;
    }

    public void addWord(Word word) {
        words.add(word);
    }

    public void setWrong() {
        wrong = 1;
        words.get(2).setRight(-2);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
        sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
        sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
        if (wrong == 0) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
        }
        sb.append(block.toString());
        sb.append("<MainFuncDef>");
        sb.append("\n");
        return sb.toString();
    }
}
