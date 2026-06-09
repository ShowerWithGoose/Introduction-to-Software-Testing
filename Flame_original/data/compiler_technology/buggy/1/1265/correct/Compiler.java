import fault.Fault;
import front.lexer.Lexer;
import front.parser.Parser;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintStream;

/**
 * 编译器入口类
 */
public class Compiler {

    /**
     * 编译器入口
     *
     * @param args 命令行参数
     */
    public static void main(String[] args) {
        final String INPUT = "testfile.txt";
        final String OUTPUT = "parser.txt";
        final String ERROR = "error.txt";
        FileReader inputReader;
        PrintStream outputStream;
        PrintStream errorStream;
        try {
            inputReader = new FileReader(INPUT);
            outputStream = new PrintStream(OUTPUT);
            errorStream = new PrintStream(ERROR);
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }

        Lexer.initLexer(inputReader);
        Lexer.getLexer().pass();

        Parser parser = Parser.getParser();
        parser.pass();

        Fault fault = Fault.getFault();
        if (fault.hasFault()) {
            fault.printFault(errorStream, true);
        } else {
            parser.printTree(outputStream);
        }
    }
}
