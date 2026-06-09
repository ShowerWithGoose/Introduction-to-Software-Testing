package frontend.lexer;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class KernelLexer {
    //主要负责了testfile每一行的存储，读取指针的移动（行和列）
    /*注意：curline、curcolumn指向的都是当前还没有处理的字符，peek的应该是它们*/
    private InputStream inputStream;
    private ArrayList<String> lines;
    private int curLine;//行
    private int curColumn;//列

    public KernelLexer(InputStream inputStream) {
        this.inputStream = inputStream;
        this.lines = new ArrayList<>();
        this.curLine = 0;
        this.curColumn = 0;
        readLines();
    }

    public int curLine() {
        return curLine;
    }

    public void readLines() {
        //通过inputStream把lines都读进来
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream))) {
            String line;
            while ((line = reader.readLine()) != null) {
                lines.add(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /*当前行里，还未处理的字符串*/
    public String curLineStr_remain() {
        return lines.get(curLine).substring(curColumn);
    }

    /*看下一个字符，curColumn表示未处理的下一个字符*/
    /*问题：有可能一开头就是空字符*/
    /*问题：假如文件末尾全都是换行符，没有内容*/
    public char peekChar() {
        while (true) {
            if (endOfFile()) {
                return '\uFFFD'; //说明到文件末尾了
            } else if (endOfLine() == true) {
                curLine++;
                curColumn = 0;
            } else if (endOfLine() == false) {
                break;
            }
        }
        if (endOfFile()) {
            return '\uFFFD';
        }
        return lines.get(curLine).charAt(curColumn);
    }

    public void moveSteps(int steps) {
        if (curColumn + steps < lines.get(curLine).length()) {
            curColumn += steps;
        } else {
            curColumn = curColumn + steps - lines.get(curLine).length(); //?有待考量
            curLine++;
        }
    }

    public void moveToNextLine() {
        curLine++;
        curColumn = 0;
    }

    public void moveToColumn(int column) {
        curColumn = column;
    }

    /*表示读到了文件的结尾*/
    public boolean endOfFile() {
        if (curLine >= lines.size()) {
            return true;
        }
        else if (curLine == lines.size() - 1
                && curColumn >= lines.get(curLine).length()) {
            return true;
        }
        return false;
    }

    public Boolean endOfLine() {
        //System.out.println("curline:" + curLine);
        if (endOfFile()) {
            return null;
        }
        if (curColumn >= lines.get(curLine).length()) {
            return true;
        }
        return false;
    }

    /*匹配某个tokentype的pattern，需要在匹配完之后移动行指针和列指针*/
    public Token tryMatch(Pattern pattern) {
        if (endOfFile()) {
            return null;
        }
        String lineRemain = lines.get(curLine).substring(curColumn);
        Matcher matcher = pattern.matcher(lineRemain);
        /*需要处理注释的情况，比如匹配‘*’时不能匹配到注释*/
        if (matcher.find()) {
            Token token = new Token(null, matcher.group(0), curLine+1);
            int strlen = matcher.group(0).length();
            curColumn = curColumn + strlen;
            if (curColumn >= lines.get(curLine).length()) {
                curLine++;
                curColumn = 0;
            }
            return token;
        } else {
            return null;
        }

    }
}
