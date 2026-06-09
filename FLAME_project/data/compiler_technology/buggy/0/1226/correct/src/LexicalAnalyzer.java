package src;

import javax.sound.sampled.Line;
import java.io.*;
import java.util.*;

public class LexicalAnalyzer {
    static boolean hasError = false;
    public LexicalAnalyzer() {
    }

    public void analyze(InputStream inputFile) {
        Scanner scanner = new Scanner(inputFile);
        LineAnalyzer lineAnalyzer = new LineAnalyzer();
        int lineNumber = 0;
        boolean isComment = false;
        OutputStream outputStream;
        OutputStream errorStream;
        PrintWriter lexerWriter;
        PrintWriter errorWriter;
        try {
            outputStream = new FileOutputStream("lexer.txt");
            errorStream = new FileOutputStream("error.txt");
            lexerWriter = new PrintWriter(outputStream, true);
            errorWriter = new PrintWriter(errorStream, true);
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        while (scanner.hasNext()) {
            String line = scanner.nextLine();
            lineNumber++;
            //skip empty lines
            if (line.trim().isEmpty()) {
                continue;
            }
            isComment = lineAnalyzer.analyze(line, lineNumber, isComment, lexerWriter, errorWriter);
        }
        if (hasError) {
            try {
                PrintWriter writer = new PrintWriter("lexer.txt");
                writer.print("");
                writer.close();
            } catch (FileNotFoundException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
