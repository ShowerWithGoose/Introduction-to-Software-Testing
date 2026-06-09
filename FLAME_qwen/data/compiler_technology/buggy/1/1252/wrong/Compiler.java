import frontend.Printer;
import frontend.lexer.Lexer;
import frontend.lexer.TokenStream;
import frontend.paser.Parser;

import java.io.*;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Compiler {
    public static void main(String[] args) throws IOException {
        //打开文件
        String input_file_name = "testfile.txt";
        InputStream inputStream = null;
        try {
            inputStream = new FileInputStream(input_file_name);
        } catch (FileNotFoundException e){
            System.err.println( input_file_name + " can't open.");
        }

        //设置输出流
        String output_correct_file_name = "parser.txt";
        String output_error_file_name = "error.txt";
        OutputStream outputStream_Error = new FileOutputStream(output_error_file_name);
        OutputStream outputStream_Correct = new FileOutputStream(output_correct_file_name);
        Printer printer = Printer.getInstance();
        printer.setOutputStreams(outputStream_Correct, outputStream_Error);

        //词法分析 -> 创建TokenStream
        PushbackInputStream input = new PushbackInputStream(inputStream, 16);
        Lexer lexer = new Lexer(input);
        lexer.addToken();
        TokenStream tokenStream = new TokenStream(lexer.getTokenArrayList());

        Parser parser = new Parser(tokenStream);
        parser.parseCompUnit();

        if (Printer.getInstance().isHasError()) {
            Printer.getInstance().printError();
        }
    }
}