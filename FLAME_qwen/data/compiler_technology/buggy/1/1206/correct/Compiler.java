import error.error;
import error.errorList;
import frontend.Lexer;
import frontend.Parser;
import frontend.token;
import print.out;

import java.io.*;
import java.util.Comparator;

/**
 * @author
 * @Description:
 * @date 2024/9/23 9:51
 */
public class Compiler {
    public static void main(String[] args){
        String file="testfile.txt";
        Lexer lexer=new Lexer(file);
        lexer.tokenize();
        //test1(lexer);//词法分析
        Parser parser=new Parser(lexer.tokens);
        parser.parse();
        try {
            parser.print();
            errorList.getList().errors.sort(Comparator.comparing(error:: getLineno));
            for(error error: errorList.getList().errors){
                out.wWrong(error.toString());
                System.out.println(error.toString());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
    public static void test1(Lexer lexer){
        try (FileWriter fw = new FileWriter("lexer.txt", false); // 追加模式
             PrintWriter out = new PrintWriter(fw);
             PrintWriter outwrong = new PrintWriter(new FileWriter("error.txt",false))) {
            for (frontend.token token : lexer.tokens) {
                if(token.wrong)outwrong.println(token.lineno+" "+token.wType);
                out.println(token);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}

