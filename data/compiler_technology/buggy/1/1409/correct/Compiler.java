import frontend.Error;
import frontend.Lexer;
import frontend.Parser;
import frontend.Token;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Compiler {

    private static boolean lex_has_error = false;

    public static List<Token> tokens = new ArrayList<>();

    public static List<Error> errors = new ArrayList<>();

    //public static List<String> parsePrint = new ArrayList<>();

    public static void main(String[] args)
    {

        Dolexer();
//        for(Error error : errors)
//        {
//            System.out.println(error.getLineNum()+" "+error.getErrorType());
//        }
//        for(Token token : tokens)
//        {
//            System.out.println(token.getValue()+" "+token.getLineNum());
//        }
        Doparser();

    }

    public static void Dolexer()
    {
        try{
            FileInputStream input = new FileInputStream("testfile.txt");
            FileOutputStream rightoutput = new FileOutputStream("lexer.txt");
            PrintStream right = new PrintStream(rightoutput);

            Lexer lexer = new Lexer(input);
            int code = lexer.next();
            while(code != -1)
            {
                if(code == 1)
                {
                    //if(!lex_has_error)
                    right.printf("%s %s %d\n", lexer.getLexType(), lexer.getValue(), lexer.getLineNum());
                   // {
                        tokens.add(new Token(lexer.getValue(), lexer.getLexType(), lexer.getLineNum()));
                   // }
                }
                else if(code == -2)
                {
                    tokens.add(new Token(lexer.getValue(), lexer.getLexType(), lexer.getLineNum()));
                    Error a_new_error = new Error(lexer.getLineNum(), lexer.getErrorType());
                    errors.add(a_new_error);

                }
                else if(code == 0)
                {
                    //do nothing
                }

                code = lexer.next();
            }
        }catch(Exception e){
            e.printStackTrace();
        }

    }


    public static void Doparser()
    {
        try{
            FileInputStream input = new FileInputStream("lexer.txt");
            FileOutputStream rightoutput = new FileOutputStream("parser.txt");
            PrintStream right = new PrintStream(rightoutput);

            FileOutputStream wrongoutput = new FileOutputStream("error.txt");
            PrintStream error = new PrintStream(wrongoutput);

            Parser parser = new Parser(tokens);
            var result = parser.parse();
            errors.addAll(parser.getErrors());
            if(errors.isEmpty())
            {
                result.walk(right);
            }
            else {
                Collections.sort(errors, Comparator.comparingInt(Error::getLineNum));
                for (Error e : errors) {
                    error.println(e.getLineNum()+" "+e.getErrorType());
                }
            }
        }catch(Exception e){
            e.printStackTrace();
        }

    }


}
