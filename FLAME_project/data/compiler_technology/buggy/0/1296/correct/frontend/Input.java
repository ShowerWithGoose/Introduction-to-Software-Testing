package frontend;

import java.util.ArrayList;
import java.util.Objects;

public class Input {
    private ArrayList<String> inputs;
    private Integer totalLineNum;//行数
    private String currentLine;//当前行
    private Integer lineLen;//当前行的长度
    private Integer lineNum;//当前行号
    private Integer point;//当前字符的位置

    public Input(ArrayList<String> inputs) {
        this.inputs = inputs;
        totalLineNum = this.inputs.size();
        currentLine = this.inputs.get(0);
        lineLen = currentLine.length();
        lineNum = 0;
        point = 0;
    }

    public Character getChar() {
        if (Objects.equals(point, lineLen)) {   //上一次已经读到当前行的末尾
            lineNum++;                          //下移一行
            if (lineNum <= totalLineNum - 1) {
                currentLine = inputs.get(lineNum);
                lineLen = currentLine.length();
                point = 0;
            }
        }
        if (!isEnd()) {
            return currentLine.charAt(point++);
        }
        return null;
    }

    public boolean isEnd() {
        return Objects.equals(lineNum, totalLineNum) && Objects.equals(point, lineLen);
    }

    public int getLine() {
        return lineNum + 1;
    }
}
