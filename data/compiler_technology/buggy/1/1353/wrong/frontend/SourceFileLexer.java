package frontend;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * 源文件词法分析器
 * 提供一系列对输入字符流的处理的接口
 */
public class SourceFileLexer {
    private InputStream inputStream;
    private ArrayList<String> lines;
    private int lineNum;
    private int columnNum;

    public SourceFileLexer(InputStream inputStream) {
        /* initialize */
        this.inputStream = inputStream;
        this.lines = new ArrayList<>();
        this.lineNum = 0;
        this.columnNum = 0;

        /* read lines from inputStream */
        readLines();
    }

    private void readLines() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        try {
            String line = null;
            while (true) {
                line = reader.readLine();
                if (line == null) {
                    break;
                }
                this.lines.add(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /* judge if reach EOF */
    public boolean endOfFile() {
        return lineNum >= lines.size();
    }
    /* judge if reach EOL */
    public boolean endOfLine() {
        if (endOfFile()){
            return true;
        }
        return columnNum >= this.lines.get(lineNum).length();
    }

    /* get line*/
    public String getLine() {
        if (endOfFile()) {
            return "";
        }
        return lines.get(lineNum);
    }
    /* get char */
    public char getChar() {
        if (endOfFile()) {
            return 0;   // 0 for EOF
        }else if (endOfLine()) {
            return '\n';
        }
        return getLine().charAt(columnNum);
    }

    /* get rest part of the line */
    public String getRestLine() {
        if (endOfFile() || endOfLine()) {
            return "";
        } else {
            return getLine().substring(columnNum);  // from columnNum to eol
        }
    }
    /* get next substr */
    public String getSubstr(int len) {
        if (endOfFile()) {
            return "";
        }else if (columnNum + len >= getLine().length()) {
            return getRestLine();
        }else {
            return getLine().substring(columnNum, columnNum + len); // from columnNum for len
        }
    }

    /* move to next char */
    public void move(int stride) {
        int cnt = stride;
        while (!endOfFile() && cnt > 0) {
            int lineLength = this.getLine().length();
            if(columnNum + cnt >= lineLength) {     //if reach EOL
                lineNum++;  // next line
                cnt -= (lineLength - columnNum + 1);    // the rest of stride
                columnNum = 0;  // initial columnNum
            } else {
                columnNum += cnt;
                cnt = 0;
            }
        }
    }

    /* judge whitespace */
    public boolean isWhitespace(char ch) {
        return Character.isWhitespace(ch);
    }
    /* skip whitespace */
    public void skipWhitespace() {
        while (!endOfFile() && isWhitespace(getChar())) {
            move(1);
        }
    }

    /* next line */
    public void nextLine() {
        if (!endOfFile()) {
            lineNum++;
            columnNum = 0;
        }
    }


    /* try to hit the following substr */
    public String tryRestSubstr(Pattern pattern) {
        String rest = getRestLine();
        Matcher matcher = pattern.matcher(rest);
        if (matcher.find()) {
            return matcher.group(0);
        } else {
            return null;
        }
    }

    /* get current line num START WITH 1 */
    public int currentLineNum() {
        return lineNum + 1;
    }
}
