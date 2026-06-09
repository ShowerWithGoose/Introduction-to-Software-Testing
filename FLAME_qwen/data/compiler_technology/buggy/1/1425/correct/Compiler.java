/**
 * @author:
 * TODO
 * 2024/9/21 9:16
 */

import frontend.Lexer;
import Config.Config;
import Utils.IO;
import frontend.Parser;
import Error.ErrorHandler;

import java.io.BufferedReader;
import java.io.FileReader;

public class Compiler {
    private static int lineNumber = 0;

    public static void LexicalAnalysis() {
        try (BufferedReader bufferedReader = new BufferedReader(new FileReader(Config.fileInput))) {
            Lexer lexer = Lexer.getInstance();
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                lineNumber += 1;
                lexer.init(lineNumber, line);
                lexer.Lexer_main();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        init();
//        Lexer
        LexicalAnalysis();
        if (Config.lexer)
            Lexer.getInstance().Lexer_print();

//        Parser
        Parser.getInstance().Parser_Main();
        if (Config.parser)
            Parser.getInstance().Parser_print();

//        Error print
        if (Config.error)
            ErrorHandler.getInstance().Error_print();
    }

    public static void init() {
        IO.clear_file(Config.lexerOutput);
        IO.clear_file(Config.parserOutput);
        IO.clear_file(Config.fileError);
    }
}
