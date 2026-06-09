package frontend;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class SourceLexer {
    private InputStream source;
    private ArrayList<String> lines;
    private ArrayList<Integer> lineCapacities;
    private int lineNum;
    private int curPos;
    private Matcher matcher;
    private int fileCapacity;
    private int currentLineCapacity;

    public SourceLexer(InputStream inputStream) {
        this.source = inputStream;
        this.lines = new ArrayList<>();
        this.lineCapacities = new ArrayList<>();
        this.lineNum = 0;
        this.curPos = 0;
        readLines();
    }

    private void readLines() {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(this.source));
        String curLine;
        while (true) {
            try {
                curLine = bufferedReader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (curLine == null) {
                break;
            }
            this.lines.add(curLine);
            this.lineCapacities.add(curLine.length());
        }
        fileCapacity = lines.size();
        updateCurrentLineCapacity();
    }

    private void updateCurrentLineCapacity() {
        if (lineNum < fileCapacity) {
            currentLineCapacity = lineCapacities.get(lineNum);
        }
    }

    public boolean lineIsEnd() {
        return this.curPos >= currentLineCapacity;
    }

    public boolean fileIsEnd() {
        return this.lineNum >= fileCapacity;
    }

    public char getCurChar() {
        if (lineIsEnd()) {
            return '\n';
        } else if (fileIsEnd()) {
            return '\0';
        } else {
            return getCurLine().charAt(curPos);
        }
    }

    public String getCurLine() {
        if (fileIsEnd()) {
            return "";
        } else {
            return this.lines.get(lineNum);
        }
    }

    public String getSubString(int len) {
        if (fileIsEnd()) {
            return "";
        } else if (this.curPos + len >= getCurLine().length()) {
            return getCurLine().substring(this.curPos);
        } else {
            return getCurLine().substring(this.curPos, this.curPos + len);
        }
    }

    public String getSubString() {
        if (fileIsEnd()) {
            return "";
        } else if (lineIsEnd()) {
            return "";
        } else {
            return getCurLine().substring(this.curPos);
        }
    }

    private boolean isWhiteSpace(char c) {
        return Character.isWhitespace(c);
    }

    public void skipWhiteSpace() {
        while (!fileIsEnd() && isWhiteSpace(getCurChar())) {
            move();
        }
    }

    public void move() {
        if (curPos + 1 >= currentLineCapacity) {
            lineNum++;
            curPos = 0;
            updateCurrentLineCapacity();
        } else {
            curPos++;
        }
    }

    public void next() {
        if (!fileIsEnd()) {
            lineNum++;
            curPos = 0;
            updateCurrentLineCapacity();
        }
    }

    public String matchSubStr(Pattern pattern) {
        String pendingString = getSubString();
        matcher = pattern.matcher(pendingString);
        if (matcher.find()) {
            return matcher.group(0);
        } else {
            return null;
        }
    }

    public int getLineNum() {
        return lineNum + 1;
    }
}