import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

import Config.Config;
import IOcontrol.*;
import LexParser.*;
import Node.*;
import Token.*;
// 编译器入口
public class Compiler {
    public static void main(String[] args) throws IOException {
        HashMap<Integer,Character> errors = new HashMap<>();
        Lexer lexer = new Lexer(errors);
        lexer.parse(IO.read(Config.lexerInPath));
        IO.LexerOutput(lexer.getTokenList(),Config.lexerOutPath);
        //System.out.println("//////////////////////////");
        Parser parser = new Parser(lexer.getTokenList(),errors);
        parser.analyze();
        if (errors.isEmpty()) {
            parser.getCompUnitNode().print();
        }
        else {
            IO.errorOutput(errors, Config.errorOutPath);
        }
    }
}