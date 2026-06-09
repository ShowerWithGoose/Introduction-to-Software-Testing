import ErrorsModule.ErrorCollect;
import frontend.ParserModule.CompileUnit;
import frontend.ParserModule.Parser;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;

public class Compiler {
    public static void main(String[] args) throws IOException {
        Parser parser = new Parser();
        CompileUnit compileUnit = parser.parseCompileUnit();
        FileOutputStream fileOut1 = new FileOutputStream("parser.txt");
        PrintStream ps1 = new PrintStream(fileOut1);
        System.setOut(ps1);
        FileOutputStream fileOut2 = new FileOutputStream("error.txt");
        PrintStream ps2 = new PrintStream(fileOut2);
        System.setErr(ps2);
        compileUnit.checkGrammarError();
        if (ErrorCollect.isError()) {
            ErrorCollect.printError();
        } else {
            compileUnit.printRes();
        }
    }
}
