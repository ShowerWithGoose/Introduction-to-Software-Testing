package frontend;

import java.io.*;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class SrcReader {
    private final ArrayList<String> lines = new ArrayList<>();
    private int lineIndex = 0;
    private int charIndex = 0;

    public SrcReader(InputStream inputStream) {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream))) {
            String line;
            while ((line = reader.readLine()) != null) {
                lines.add(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public boolean isEndOfLine() {
        return isEndOfFile() || charIndex >= currentLine().length();
    }

    public boolean isEndOfFile() {
        return lineIndex >= lines.size();
    }

    public String currentLine() {
        return lines.get(lineIndex);
    }

    public char peekNextChar() {
        return isEndOfLine() ? '\n' : currentLine().charAt(charIndex);
    }

    public String peekNextSubstring(int length) {
        return isEndOfFile() ? "" : currentLine().substring(charIndex, Math.min(charIndex + length, currentLine().length()));
    }

    public void skipWhitespace() {
        while (!isEndOfFile() && Character.isWhitespace(peekNextChar())) {
            advancePosition(1);
        }
    }

    public void advancePosition(int steps) {
        while (steps > 0 && !isEndOfFile()) {
            int remainingInLine = currentLine().length() - charIndex;
            if (steps < remainingInLine) {
                charIndex += steps;
                steps = 0;
            } else {
                steps -= remainingInLine + 1;  // Move to the next line
                lineIndex++;
                charIndex = 0;
            }
        }
    }

    public void moveToNextLine() {
        if (!isEndOfFile()) {
            lineIndex++;
            charIndex = 0;
        }
    }

    public String getRemainingLineContent() {
        return isEndOfLine() ? "" : currentLine().substring(charIndex);
    }

    public String matchPattern(Pattern pattern) {
        Matcher matcher = pattern.matcher(getRemainingLineContent());
        return matcher.find() ? matcher.group(0) : null;
    }

    public int getCurrentLineNumber() {
        return lineIndex + 1;  // Start with 1 instead of 0
    }
}
