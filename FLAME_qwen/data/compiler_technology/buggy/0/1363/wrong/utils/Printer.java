package utils;

import front_end.lexer.Token;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;

public class Printer {
    private static FileOutputStream outFile = null;
    private static FileOutputStream errFile = null;
    private static HashMap<Integer, ErrorType> errorMap;

    public static void init() throws Exception {
        Printer.outFile = new FileOutputStream("lexer.txt");
        Printer.errFile = new FileOutputStream("error.txt");
        Printer.errorMap = new HashMap<>();

    }

    public static void printToken(Token token) {
        String content = token.toString();
        try {
            outFile.write(content.getBytes());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void addErrorMsg(Integer lineNumber, ErrorType errorType) {
        errorMap.put(lineNumber, errorType);
    }

    public static void printAllErrorMsg() {
        Object[] lineNumbers = errorMap.keySet().toArray();
        Arrays.sort(lineNumbers);
        for (Object lineNumber : lineNumbers) {
            String content = lineNumber + " " + errorMap.get((Integer) lineNumber) + "\n";
            try {
                errFile.write((content).getBytes());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
