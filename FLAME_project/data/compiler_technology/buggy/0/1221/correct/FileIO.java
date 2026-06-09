import frontend.Error;
import frontend.Token;
import frontend.TokenType;

import java.io.*;
import java.nio.file.Paths;
import java.util.ArrayList;

public class FileIO {
    private static final String testFilePath = String.valueOf(Paths.get("testfile.txt"));
    private static final String lexerFilePath = String.valueOf(Paths.get("lexer.txt"));
    private static final String errorFilePath = String.valueOf(Paths.get("error.txt"));

    public static String readTestFile() throws IOException {
        FileReader fr = new FileReader(testFilePath);
        BufferedReader br = new BufferedReader(fr);
        StringBuilder sb = new StringBuilder();
        String line;
        while ((line = br.readLine()) != null) {
            sb.append(line).append("\n");
        }
        br.close();
        fr.close();
        return sb.toString();
    }

    public static void printLexerResult(ArrayList<Token> tokens) throws IOException {
        FileWriter fw = new FileWriter(lexerFilePath);
        BufferedWriter bw = new BufferedWriter(fw);
        for (Token token: tokens) {
            if (token.getType() != TokenType.ANNOTATION) {
                String line = token.toString() + "\n";
                bw.write(line);
            }
        }
        bw.close();
        fw.close();
    }

    public static void printError(ArrayList<Error> errors) throws IOException {
        if (errors.isEmpty()) {
            return;
        }
        FileWriter fw = new FileWriter(errorFilePath);
        BufferedWriter bw = new BufferedWriter(fw);
        for (Error error: errors) {
            String line = error.toString() + "\n";
            bw.write(line);
        }
        bw.close();
        fw.close();
    }

}
