package fronted;

import java.util.ArrayList;
import java.util.Scanner;

public class Processor {
    private final ArrayList<String> fileLines = new ArrayList<>();
    private int curLine = 0;
    private int curChar = 0;

    public Processor(Scanner scanner) {
        file2str(scanner);
    }

    private void file2str(Scanner scanner) {
        int idx = 0;
        while(scanner.hasNextLine()) {
            idx++;
            String line = scanner.nextLine();
            fileLines.add(line);
        }
        if (fileLines.get(0).length() == 0) {
            move();
        }
    }

    /**
     * observer + modifier
     * check isLineEnd before getChar
     */
    public char getChar() {
        System.out.println(fileLines.get(curLine).charAt(curChar));
        return fileLines.get(curLine).charAt(curChar);
    }

    public int getCurLine() {
        return curLine;
    }

    // forward at least one char
    // after move, must point to a char unless it's the end of the file
    public void move() {
        do {
            curChar++;
            if (curChar >= fileLines.get(curLine).length()) {
                curChar = 0;
                System.out.println("done: " + fileLines.get(curLine));
                curLine++;
            }
        } while (!isValid() && !isFileEnd());
        System.out.println("curLine " + curLine);
    }

    private boolean isValid() {
        return (curLine < fileLines.size()) && (curChar < fileLines.get(curLine).length());
    }

    public boolean isFileEnd() {
        return curLine >= fileLines.size();
    }
}
