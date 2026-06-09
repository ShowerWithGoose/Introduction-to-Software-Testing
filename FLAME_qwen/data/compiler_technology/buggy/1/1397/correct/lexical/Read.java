package lexical;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class Read {
    private ArrayList<String> lines = new ArrayList<>();
    private int currentLine = 0;
    private int currentColumn = 0;

    public void readFile(File file) throws FileNotFoundException {
        Scanner scanner = new Scanner(file);
        while (scanner.hasNextLine()) {
            lines.add(scanner.nextLine());
        }
        scanner.close();
    }

    public char read() {
        if (currentColumn < lines.get(currentLine).length()) {
            currentColumn++;
            return lines.get(currentLine).charAt(currentColumn - 1);
        } else if (currentLine < lines.size() - 1) {
            currentColumn = 0;
            currentLine++;
            return '\n';
        } else {
            currentColumn++;
            return ((char) -1);
        }
    }

    public void unread() {
        if (currentColumn > 0) {
            currentColumn--;
        } else if (currentLine > 0) {
            currentLine--;
            currentColumn = lines.get(currentLine).length();
        } else {
            return;
        }
    }

    public int getCurrentLine() {
        return currentLine + 1;
    }
}
