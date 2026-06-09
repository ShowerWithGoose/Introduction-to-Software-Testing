package frontend;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.ArrayList;

public class ParserFile {
    ArrayList<Token> tokens;

    public ParserFile() {
        this.tokens = new ArrayList<>();
    }

    public void addToken(Token token) {
        tokens.add(token);
    }

    public void deleToken() {
        int size = tokens.size();
        tokens.remove(size-1);
    }

    public void printWords() {
        String outputFileName;
        outputFileName = "parser.txt";
        try {
            OutputStream outputStream = new FileOutputStream(outputFileName);
            PrintStream ps = new PrintStream(outputStream);
            for (int i = 0; i < tokens.size(); i++) {
                if (tokens.get(i).getPosLine() == -1) {
                    ps.println(tokens.get(i).getType());
                } else {
                    ps.println(tokens.get(i).getType() + " " + tokens.get(i).getString());
                }
            }
            int x = tokens.size() - 1;
            //outputStream.write((words.get(x).getType() + " " + words.get(x).getString()).getBytes());
        } catch (FileNotFoundException e) {
            System.err.println("Can not open " + outputFileName);
        }
    }
}
