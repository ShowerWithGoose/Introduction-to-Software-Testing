import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;

public class Compiler
{
    public static void main(String[] args)
    {
        try
        {
            String code = Files.readString(Path.of("testfile.txt"));
            Lexer lexer = new Lexer(code);
            List<Token> tokens = lexer.tokenize();
            if (lexer.isError)
            {
                File file = new File("error.txt");
                file.createNewFile();
                FileWriter fw = new FileWriter(file);
                BufferedWriter bw=new BufferedWriter(fw);
                for (Errors e : lexer.errors)
                    bw.write(e.lineno + " " + e.type + "\n");
                bw.close();
            }
            else
            {
                File file = new File("lexer.txt");
                file.createNewFile();
                FileWriter fw = new FileWriter(file);
                BufferedWriter bw=new BufferedWriter(fw);
                for (Token t : tokens)
                    bw.write(t.type + " " + t.s + "\n");
                bw.close();
            }
        }
        catch (IOException e)
        {
            System.err.println("Error reading file: " + e.getMessage());
        }
    }
}
