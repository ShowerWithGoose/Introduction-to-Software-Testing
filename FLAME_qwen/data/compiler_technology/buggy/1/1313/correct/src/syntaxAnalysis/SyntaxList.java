package src.syntaxAnalysis;

import java.util.ArrayList;
import java.util.List;

/**
 * 语法树后序遍历的列表
 */
public class SyntaxList {
    private List<String> syntaxs;

    public SyntaxList() { this.syntaxs = new ArrayList<>(); }

    public void add(String syntax) { this.syntaxs.add(syntax); }

    public List<String> getSyntaxs() { // 支持返回单词序列，实现更多功能
        return this.syntaxs;
    }

    @Override
    public String toString() { // 输出为指定格式
        StringBuilder sb = new StringBuilder();
        for (String syntax : syntaxs) {
            sb.append(syntax).append("\n");
        }
        return sb.toString();
    }
}
