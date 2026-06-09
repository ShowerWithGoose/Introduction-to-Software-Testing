import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Compiler
{
    public static List<Errors> errors = new ArrayList<>();
    public static boolean isError;
    public static List<Token> tokens = new ArrayList<>();

    public static void main(String[] args)
    {
        isError = false;
        try
        {
            String code = Files.readString(Path.of("testfile.txt"));
            //词法分析
            Lexer lexer = new Lexer(code);
            tokens = lexer.tokenize();

            //语法分析
            Parser parser = new Parser(tokens);
            ASTNode astNode = parser.parseCompUnit();

            if (Compiler.isError)
            {
                errors.sort(Comparator.comparingInt(o -> o.lineno));
                File file = new File("error.txt");
                file.createNewFile();
                FileWriter fw = new FileWriter(file);
                BufferedWriter bw = new BufferedWriter(fw);
                for (Errors e : Compiler.errors)
                    bw.write(e.lineno + " " + e.type + "\n");
                bw.close();
            }
            else
            {
                File file = new File("parser.txt");
                file.createNewFile();
                FileWriter fw = new FileWriter(file);
                BufferedWriter bw = new BufferedWriter(fw);
                ASTPrinter astPrinter = new ASTPrinter(bw);
                astNode.accept(astPrinter);
            }
        }
        catch (IOException e)
        {
            System.err.println("Error reading file: " + e.getMessage());
        }
    }
}
