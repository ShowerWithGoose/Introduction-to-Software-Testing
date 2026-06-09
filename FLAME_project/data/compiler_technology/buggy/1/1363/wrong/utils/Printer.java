package utils;

import front_end.lexer.Token;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;

public class Printer {
    public static boolean OUT_PERM = true;
    public static boolean ERR_PERM = true;
//    public static boolean LLVM_PERM = true;
//    public static boolean MIPS_PERM = true;
    public static boolean onOff = true;

    private static FileOutputStream outFile = null;
    private static FileOutputStream errFile = null;
    private static FileOutputStream parseFile = null;
    private static HashMap<Integer, ErrorType> errorMap;


    public static void init() throws Exception {
        Printer.outFile = new FileOutputStream("parser.txt");
        Printer.errFile = new FileOutputStream("error.txt");
        Printer.parseFile = new FileOutputStream("parser.txt");
        Printer.errorMap = new HashMap<>();

    }

    public static void printToken(Token token) {
        String content = token.toString();
        if(onOff){
            try {
                outFile.write(content.getBytes());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

    }

    public static void printSyntaxVarType(SyntaxVarType type) {
        String content = "<" + type.toString() + ">\n";
        if (onOff & OUT_PERM) {
            try {outFile.write((content).getBytes());} catch (IOException e) {throw new RuntimeException(e);}
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
