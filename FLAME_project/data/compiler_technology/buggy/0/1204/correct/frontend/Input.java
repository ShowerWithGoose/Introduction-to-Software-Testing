package frontend;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Input {
    private InputStream inputStream;
    private ArrayList<String> lines = new ArrayList<>();
    private int lineNum = 0;
    private int linePos = 0;

    public Input(InputStream inputStream) {
        this.inputStream = inputStream;
        readLine();
    }

    public void readLine() {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(this.inputStream));
        try {
            while (true) {
                String line = bufferedReader.readLine();
                if (line == null) {
                    break;
                } else {
                    this.lines.add(line);
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public String getLine() {
        if (endFile()) { // always judge endOfFile firstly
            return "";
        }
        return this.lines.get(lineNum);
    }

    public char getChar() {
        if (endFile()) { // always judge endOfFile firstly
            return 0;
        } else if (endLine()) { // judge endOfLine
            return '\n';
        } else {
            return getLine().charAt(linePos);
        }
    }

    public String getString(int len) {
        if (endFile()) {
            return "";
        } else if (this.linePos + len >= getLine().length()) {
            return getLine().substring(this.linePos);
        } else {
            return getLine().substring(this.linePos, this.linePos + len);
        }
    }

    public boolean endLine() {
        if (endFile()) {
            return true;
        }
        return this.linePos >= this.lines.get(lineNum).length();
    }

    public boolean endFile() {
        return this.lineNum >= this.lines.size();
    }

    private boolean isWhiteSpace(char c) {
        return Character.isWhitespace(c);
    }

    public void skipWhiteSpace() {
        while (!endFile() && isWhiteSpace(getChar())) {
            moveForward(1);
        }
    }

    public void moveForward(int steps) {
        int cnt = steps;
        while (!this.endFile() && cnt > 0) {
            int lineLen = getLine().length();
            if (linePos + cnt >= lineLen) {
                lineNum++;
//                cnt -= (lineLen - linePos + 1);
                cnt = 0;
                linePos = 0;
            } else {
                linePos += cnt;
                cnt = 0;
            }
        }
    }

    public void skipCurLine() {
        if (!endFile()) {
            lineNum++;
            linePos = 0;
        }
    }

    public int getLineNum() {
        return lineNum + 1;
    }

}
