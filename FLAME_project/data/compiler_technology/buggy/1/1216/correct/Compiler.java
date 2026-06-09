import exeptions.ErrorList;
import frontend.SymbolTableBuilder;
import frontend.lexer.Lexer;
import frontend.lexer.TokenList;
import frontend.parser.CompUnit;
import frontend.parser.Parser;
import frontend.parser.TokenHandler;
import frontend.symbol.SymbolTable;
import output.Output;

import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) {
        ErrorList errorList = new ErrorList();

        Lexer lexer = Lexer.getLexer("testfile.txt");
        TokenList tokenList = lexer.getTokenList();
        new Output<>(tokenList).printToFile("lexer.txt", false); // 打印lexer词法分析的结果
        errorList.appendErrorList(lexer.getErrorList());

        TokenHandler handler = new TokenHandler(lexer.getCorrectedTokenList());
//        lexer.getCorrectedTokenList().printInfo(); // 测试词法分析

        CompUnit compUnit = Parser.parseCompUnit(handler);
        new Output<>(compUnit).printToFile("parser.txt", false);
        errorList.appendErrorList(handler.getErrorList());

//        SymbolTableBuilder builder = new SymbolTableBuilder(compUnit);
//        builder.buildSymbolTables();// symbol table 的获取和排序
//        ArrayList<SymbolTable> symbolTables = builder.getSymbolTables();
//        new Output<>("").printToFile("symbol.txt", false); // 先清空以前的输出
//        for (SymbolTable symbolTable: symbolTables) {
//            new Output<>(symbolTable).printToFile("symbol.txt", true);
//        }
//        errorList.appendErrorList(builder.getErrorList());

        new Output<>(errorList.sortUpOrder()).printToFile("error.txt", false);
        // 将错误按照行号升序输出到error.txt
    }
}