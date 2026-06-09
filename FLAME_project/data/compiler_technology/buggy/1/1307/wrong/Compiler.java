import error_part.Debug;
import error_part.ErrorList;
import lexer_part.Lexer;
import lexer_part.LineSplitter;
import lexer_part.TokenList;
import parser_part.CompUnit;
import parser_part.CompUnitParser;
import symbol_part.Symbol;
import symbol_part.SymbolList;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class Compiler {
    public static void main(String[] args) {
        InputStream inputStream = null;
        Debug.status = true;
        try {
            inputStream = new FileInputStream("testfile.txt");
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        LineSplitter lineSplitter = new LineSplitter(inputStream);
        Lexer lexer = new Lexer(lineSplitter);
        TokenList tokenList = lexer.getTokenList();
        tokenList.merge();
        CompUnitParser compUnitParser = new CompUnitParser(lexer.getTokenList());
        CompUnit compUnit = compUnitParser.parseCompUnit();
        String output = "symbol.txt";
        String s = SymbolList.sharedSymbolList.toString();//compUnitParser.parseCompUnit().toString();
        if (!ErrorList.isEmpty() && Debug.status){
            output = "error.txt";
            s = ErrorList.errorOutput();
        }
        try {
            OutputStream outputStream = new FileOutputStream(output);
            OutputStream outputStream1 = new FileOutputStream("parser.txt");
            try {
                outputStream.write(s.getBytes());
                outputStream1.write(compUnit.toString().getBytes());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }
}
