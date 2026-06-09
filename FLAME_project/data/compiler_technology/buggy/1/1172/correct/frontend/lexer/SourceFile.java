package frontend.lexer;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class SourceFile {
    private String inputFile;
    private ArrayList<String> lines = new ArrayList<>();
    private int lineNum = 0;
    private int columnNum = 0;

    public SourceFile(String input) {
        this.inputFile = input;
        readLinesFromFile();
    }

    private void readLinesFromFile() {
        try (BufferedReader bufferedReader = new BufferedReader(new FileReader(inputFile))) {
            String lineContent;
            while ((lineContent = bufferedReader.readLine()) != null) {
                lines.add(lineContent + "\n");
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public char readCurrentChar() {
        if (isEndOfInput()) {
            return '\0';
        }
        String currentLine = lines.get(lineNum);
        if (columnNum >= currentLine.length()) {
            return '\n';
        }
        return currentLine.charAt(columnNum);
    }

    public String readRemainingInput() {
        int originalLine = lineNum;
        int originalColumn = columnNum;
        StringBuilder sb = new StringBuilder();
        while (!isEndOfInput() && !EndOfLine()) {
            sb.append(readCurrentChar());
            advanceChar();
        }
        int tempLine = lineNum;
        int tempColumn = columnNum;
        lineNum = originalLine;
        columnNum = originalColumn;
        return sb.toString();
    }

    public boolean EndOfLine() {
        if (isEndOfInput()) {
            return true;
        }
        return readCurrentChar() == '\n';
    }

    public void advanceChar() {
        if (isEndOfInput()) {
            return;
        }
        String currentLine = lines.get(lineNum);
        columnNum++;
        if (columnNum >= currentLine.length()) {
            columnNum = 0;
            lineNum++;
        }
    }

    public String readSubStr(int length) {
        if (isEndOfInput()) {
            return "";
        }
        StringBuilder sb = new StringBuilder();
        int tempLine = lineNum;
        int tempColumn = columnNum;
        int charsRead = 0;
        while (charsRead < length && tempLine < lines.size()) {
            String currentLine = lines.get(tempLine);
            while (tempColumn < currentLine.length() && charsRead < length) {
                sb.append(currentLine.charAt(tempColumn));
                tempColumn++;
                charsRead++;
            }
            if (tempColumn >= currentLine.length()) {
                tempLine++;
                tempColumn = 0;
            }
        }
        return sb.toString();
    }

    public void skipNextSubStr(int length) {
        int stepsRemaining = length;
        while (!isEndOfInput() && stepsRemaining > 0) {
            String currentLine = lines.get(lineNum);
            int charsInLine = currentLine.length() - columnNum;
            if (stepsRemaining >= charsInLine) {
                stepsRemaining -= charsInLine;
                columnNum = 0;
                lineNum++;
            } else {
                columnNum += stepsRemaining;
                stepsRemaining = 0;
            }
        }
    }

    public boolean isEndOfInput() {
        return lineNum >= lines.size();
    }

    public int getLineNum() {
        return lineNum + 1;
    }
}
