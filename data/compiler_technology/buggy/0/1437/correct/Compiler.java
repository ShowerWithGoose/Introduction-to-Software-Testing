import file.File;
import frontend.Lexer;

public class Compiler {

    public static void main(String[] args) {
        // System.out.println(File.readFileToString(File.readPath));

        Lexer.getInstance().getsym(File.readFileToString(File.readPath));

        File.writeStringToFile(File.lexerPath, Lexer.getSymList());

        File.writeErrorsToFile(File.errorPath);
    }
}