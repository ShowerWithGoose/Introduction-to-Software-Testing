package frontend;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * @author
 * 源文件词法分析器
 */
public class SourceFileLexer {
    private InputStream inputStream; // 字符串输入流
    private ArrayList<String> lines; // 行容器，在 readLines 中初始化
    private int lineNum; // 当前光标所在行号，从 0 开始
    private int columnNum; // 当前光标所在列号，从 0 开始

    public SourceFileLexer(InputStream inputStream) {
        this.inputStream = inputStream;
        this.lines = new ArrayList<>();
        this.lineNum = 0;
        this.columnNum = 0;
        readLines();
    }

    /* 将源程序文件按行读入 lines 中存储 */
    private void readLines() {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(this.inputStream));
        try {
            // 表示每一次新读入的行
            String lineNow = null;
            while (true) {
                lineNow = bufferedReader.readLine(); // 行终止符并不会包括在里面
                if (lineNow == null) { // 流的末尾，如果是行的末尾会返回 ""
                    break;
                }
                lines.add(lineNow);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * 判断是否到达行的末尾
     * @return 是否到达行的末尾
     */
    public boolean endOfLine() {
        if (endOfFile()) { // 优先判断是否到达文件末尾
            return true;
        }
        // 拿到当前行号对应的行的内容，然后比较列号与该行的长度
        return columnNum >= lines.get(lineNum).length();
    }

    /* 判断是否到了文件的末尾，它是 endOfLine 的子集，所以要先判断 */
    public boolean endOfFile() {
        return this.lineNum >= this.lines.size();
    }

    /* 获取现在的行 */
    public String peekLine() {
        if (endOfFile()) {
            return "";
        } else {
            return lines.get(lineNum);
        }
    }

    /* 获取现在的字符 */
    public char peekChar() {
        if (endOfFile()) {
            return 0;
        } else if (endOfLine()) {
            return '\n';
        } else {
            return peekLine().charAt(columnNum);
        }
    }

    /**
     * 得到这一行的剩下的 len 个字符
     * @param len 需要去后面多少个字符
     * @return len 个字符
     */
    public String peekSubStr(int len) {
        if (endOfFile()) {
            return "";
        } else if (this.columnNum + len >= peekLine().length()) {
            return peekLine().substring(this.columnNum);
        } else {
            return peekLine().substring(this.columnNum, this.columnNum + len);
        }
    }

    /**
     * 判断将要处理的字符是否是 whitespace
     * 注意：Java 里的 whitespace 不只是空格键，还包含 tab 键，换行符
     * @param c 将要处理的字符
     * @return 将要处理的字符是否是 whitespace
     */
    private boolean isWhiteSpace(char c) {
        return Character.isWhitespace(c);
    }

    /**
     * 跳过 whitespace，直到待处理的字符不是 whitespace 为止
     * @return 是否有跳过 whitespace
     */
    public boolean skipWhiteSpace() {
        boolean flag = false;
        while (!endOfFile() && isWhiteSpace(peekChar())) {
            flag = true;
            moveForward(1);
        }
        return flag;
    }

    /**
     *  将指针向前移动 steps 步
     * @param steps 向前移动的步数
     */
    public void moveForward(int steps) {
        int cnt = steps;
        while (!this.endOfFile() && cnt > 0) {
            // 统计当前行的长度
            int lineLen = peekLine().length();
            if (columnNum + cnt >= lineLen) { // 移动范围超出当前行的长度
                lineNum++;
                cnt -= (lineLen - columnNum + 1); // TODO：很怪
                columnNum = 0;
            } else {
                columnNum += cnt;
                cnt = 0;
            }
        }
    }

    /* 将当前指针指向下一行的开始位置 */
    public void nextLine() {
        if (!endOfFile()) {
            lineNum++;
            columnNum = 0;
        }
    }

    /* 得到该行的剩下部分，包括 columnNum 当前指向的字符 */
    public String getLeftLine() {
        if (endOfFile() || endOfLine()) {
            return "";
        } else {
            return peekLine().substring(columnNum);
        }
    }

    /**
     * 尝试根据正则表达式来匹配待匹配的字符流
     * @param pattern 正则表达式
     * @return 若匹配成功返回 token，否则返回 null
     */
    public String hitSubStr(Pattern pattern) {
        String leftLine = getLeftLine();
        Matcher matcher = pattern.matcher(leftLine);
        if (matcher.find()) {
            return matcher.group(0);
        } else {
            return null;
        }
    }

    /**
     * 获取当前行号（从 1 开始）
     * @return 当前行号
     */
    public int getLineNum() {
        return lineNum + 1;
    }
}
