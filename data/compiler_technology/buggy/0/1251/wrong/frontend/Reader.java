package frontend;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Reader {
    private String source = null;
    private int curPos = 0;
    private int curLine;

    public Reader(String inputFile) {
        try {
            source = Files.readString(Paths.get(inputFile));
            StringBuilder sb = new StringBuilder(source);
            sb.append((char) 0);
            source = sb.toString();
        } catch (IOException ex) {
            System.err.println("Can not read " + inputFile);
        }
    }

    public char read() {
        char c = source.charAt(curPos);
        curPos++;
        return c;
    }

    public void unread() {
        curPos--;
    }


}
