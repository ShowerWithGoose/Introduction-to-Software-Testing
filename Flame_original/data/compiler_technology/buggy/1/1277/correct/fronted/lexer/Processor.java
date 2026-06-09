package fronted.lexer;

import java.util.Scanner;

public class Processor {
    private String fileLines;
    private int curChar;

    public Processor(Scanner scanner) {
        curChar = -1;
        fileLines = "";
        file2str(scanner);
        removeMsgs();
    }

    private void file2str(Scanner scanner) {
        int idx = 0;
        while(scanner.hasNextLine()) {
            idx++;
            String line = scanner.nextLine();
            fileLines += line + '\n';
        }
    }

    /**
     * observer + modifier
     * check isLineEnd before getChar
     */
    public char getChar() {
        return fileLines.charAt(curChar);
    }

    // forward at least one char
    // after move, must point to a char unless it's the end of the file
    public void forward() {
        curChar++;
    }

    public void backward() {
        curChar--;
    }

    public boolean hasNext() {
        return (curChar + 1) < fileLines.length();
    }


    private void removeMsgs() {
        StringBuilder sb = new StringBuilder();
        int f = 0; // 0 means norm, 1 means '//', 2 means '/*'
        for(int i = 0; i < fileLines.length(); i++) {
            char c = fileLines.charAt(i);
            if (f == 0) {
                if (c == '/' && i + 1 < fileLines.length() && fileLines.charAt(i + 1) == '/') {
                    f = 1;
                    i++;
                } else if (c == '/' && i + 1 < fileLines.length() && fileLines.charAt(i + 1) == '*') {
                    f = 2;
                    i++;
                } else {
                    sb.append(c);
                }
            } else if (f == 1) { // ignore until \n
                if (c == '\n') {
                    sb.append('\n');
                    f = 0;
                }
            } else { // /*, should meet another */, save '\n'
                if (c == '\n') {
                    sb.append('\n');
                }
                if (c == '*' && i + 1 < fileLines.length() && fileLines.charAt(i + 1) == '/') {
                    i++;
                    f = 0;
                }
            }
        }
        fileLines = sb.toString();
    }
}
