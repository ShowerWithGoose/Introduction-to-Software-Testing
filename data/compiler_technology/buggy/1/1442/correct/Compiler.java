import frontend.Parser.CompUnit;
import frontend.lexer.*;

import java.io.FileWriter;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.IOException;
import java.util.ArrayList;

public class Compiler
{


    public static void main(String[] args)
    {
        try
        {
            String content = Files.readString(Paths.get("testfile.txt"));
            Tokenlist tokenlist = new Tokenlist();
            Lexer lexer = new Lexer(content, tokenlist);
            lexer.LexicalAnalysis();
            ArrayList<Token> tokenList = lexer.getTokenlist();
            CompUnit ParserCompUnit = new CompUnit(null, null, null);
            CompUnit compUnit = ParserCompUnit.ParseCompUnit(tokenlist);
            if (Errorlist.getErrorlist().getErrors().isEmpty())
            {
                try (PrintWriter writer = new PrintWriter(new FileWriter("parser.txt")))
                {
                    writer.println(compUnit.toString());
                }
                catch (IOException e)
                {
                    //System.out.println("Output Error!");
                }
            }
            else
            {
                try (PrintWriter writer = new PrintWriter(new FileWriter("error.txt")))
                {
                    ArrayList<Errors> errorlist = Errorlist.getErrorlist().getErrors();
                    for (Errors error : errorlist)
                    {
                        writer.println(error.getLine() + " " + error.getType());
                    }
                }
                catch (IOException e)
                {
                    //System.out.println("Output Error!");
                }
            }
        }
        catch (IOException e)
        {
            //System.out.println("File Open Error!");
        }
    }

}