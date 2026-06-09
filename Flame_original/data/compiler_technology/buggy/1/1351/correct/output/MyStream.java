package output;

import java.io.*;
import java.util.ArrayList;

public class MyStream {
    public static class Configure {
        private static final String input = "testfile.txt";
        private static final String lexer = "lexer.txt";
        private static final String parser = "parser.txt";
        private static final String err = "error.txt";
        public static final boolean isLexer = false;
        public static final boolean isParser = true;
        public static final boolean isDebug = false;
//        public static final boolean isDebug = true;

    }
    private static BufferedInputStream input;
    private static BufferedWriter lexer;
    private static BufferedWriter parser;
    private static BufferedWriter err;

    private static ArrayList<ErrorMessage> errorList;
    static {
        try {
            input = new BufferedInputStream(new FileInputStream(Configure.input));
            lexer = new BufferedWriter(new FileWriter(Configure.lexer));
            parser = new BufferedWriter(new FileWriter(Configure.parser));
            err = new BufferedWriter(new FileWriter(Configure.err));
            errorList = new ArrayList<>();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static BufferedInputStream getInput(){
        return input;
    }
    public static void printLexer(String str) throws IOException {
        if (Configure.isLexer) {
            lexer.append(str);
        }
    }

    public static void printParser(String str) throws IOException {
        if (Configure.isParser) {
            parser.append(str);
            if (Configure.isDebug) {
                System.out.println(str);
            }
        }
    }

    public static void errThrow(int lineNo, String str) {
        errorList.add(new ErrorMessage(lineNo, str));
    }

    private static void printErr() throws IOException {
        errorList.sort(null);
        for (ErrorMessage errorMessage : errorList) {
            err.append(errorMessage.toString());
        }
    }
    public static void close() throws IOException {
        lexer.close();
        parser.close();
        printErr();
        err.close();
    }
}
