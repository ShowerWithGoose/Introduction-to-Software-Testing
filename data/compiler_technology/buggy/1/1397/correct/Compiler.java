import lexical.Lexer;
import lexical.Read;
import lexical.Token;
import lexical.TokenList;
import syntax.Parser;
import syntax.Unit;

import java.io.*;
import java.util.ArrayList;
import java.util.TreeMap;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String path = "testfile.txt";
        File file = new File(path);
        Read read = new Read();
        read.readFile(file);
//        File fileError = new File("error.txt");
//        if (!fileError.exists()) {
//            fileError.createNewFile();
//        }
//        PrintStream psError = new PrintStream(fileError);
//        File fileLexer = new File("lexer.txt");
//        if (!fileLexer.exists()) {
//            fileLexer.createNewFile();
//        }
//        PrintStream psLexer = new PrintStream(fileLexer);
        BufferedWriter parserWriter = new BufferedWriter(new FileWriter("parser.txt"));

        ArrayList<String> parsers = new ArrayList<>();

        BufferedWriter errorWriter = new BufferedWriter(new FileWriter("error.txt"));
        TreeMap<Integer, String> errors = new TreeMap<>();
        Lexer lexer = new Lexer(read);
        lexer.serErrorWriter(errorWriter);
        lexer.setErrorBuffer(errors);
        lexer.run();
        TokenList tokenList = lexer.getTokenlist();
        tokenList.setParserWriter(parserWriter);
        tokenList.setParsers(parsers);
        Parser parser = new Parser(tokenList, errorWriter, parserWriter, errors, parsers);
        Unit.CompUnit compUnit = parser.run();

//        for (Token token : tokens) {
//            parserWriter.write(token.getType() + " " + token.getRawString());
//            parserWriter.newLine();
//        }
        for (int line : errors.keySet()) {
            errorWriter.write(line + " " + errors.get(line) + "\n");
        }
        for (String line : parsers) {
            parserWriter.write(line + "\n");
        }
        parserWriter.close();
        errorWriter.close();
    }
}
