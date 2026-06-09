package fronted;

import java.util.Scanner;

public class Processor {
    private String fileLines;
    private int curChar;

    public Processor(Scanner scanner) {
        curChar = -1;
        fileLines = "";
        file2str(scanner);
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
}
