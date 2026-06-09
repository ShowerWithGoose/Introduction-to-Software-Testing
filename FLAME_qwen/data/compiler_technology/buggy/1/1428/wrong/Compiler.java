import java.io.*;

import frontend.ErrorList;
import frontend.lexer.*;
import frontend.parser.Parser;
import frontend.parser.base.CompUnit;
import frontend.parser.stmt.Decl.InitVal;

public class Compiler {
    public static void main(String[] args) {
        String string = readProgram();
        ErrorList errorList = new ErrorList();
        Lexer lexer = new Lexer(errorList);
        TokenStream tokenStream;
        tokenStream = lexer.lexerProgram(string);
        Parser parser = new Parser(tokenStream, errorList);
        CompUnit compUnit = parser.parseCompUnit();
        String rightString = compUnit.toString();
        String errString = errorList.toString();
        outputFile(rightString, errString);
    }

    public static String readProgram() {
        String testFilePath = "testfile.txt";
        String testFileString;
        File testFile = new File(testFilePath);
        try {
            FileInputStream fileInputStream = new FileInputStream(testFile);
            int length = fileInputStream.available();
            byte bytes[] = new byte[length];
            fileInputStream.read(bytes);
            testFileString = new String(bytes);
            fileInputStream.close();
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return testFileString;
    }

    public static void outputFile(String rightOutput, String errorOutput) {
        String outputPath;
        String outputString;
        if (errorOutput == "") {
            outputPath = "parser.txt";
            outputString = rightOutput;
        } else {
            outputPath = "error.txt";
            outputString = errorOutput;
        }
        File outputFile = new File(outputPath);
        if (!outputFile.exists()) {
            try {
                outputFile.createNewFile();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        try {
            FileOutputStream fileOutputStream = new FileOutputStream(outputFile);
            byte bytes[] = outputString.getBytes();
            fileOutputStream.write(bytes);
            fileOutputStream.close();
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

}