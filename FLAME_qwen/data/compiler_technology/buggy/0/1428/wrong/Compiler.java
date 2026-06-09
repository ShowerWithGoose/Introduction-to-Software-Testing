import java.io.*;


public class Compiler {
    public static void main(String[] args) {
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
        Lexer lexer = new Lexer();
        ErrorList errorList = new ErrorList();
        lexer.lexer_program(testFileString, errorList);
        String rightOutput = lexer.toString();
        String errorOutput = errorList.toString();
        String outputPath;
        String outputString;
        if (errorOutput == "") {
            outputPath = "lexer.txt";
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