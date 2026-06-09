import java.io.*;

import frontend.Error;
import frontend.ErrorHandler;
import frontend.Parser;

import java.util.Comparator;
import java.util.List;

public class Compiler {
    public static void main(String[] args) {
        String inputFile = "testfile.txt";
        try (InputStream input = new FileInputStream(inputFile);
             Writer parserOutput = new FileWriter("parser.txt");
             Writer errorOutput = new FileWriter("error.txt")) {
            // 创建 Parser 实例，传入输入流和输出流
            ErrorHandler errorHandler = new ErrorHandler();
            Parser parser = new Parser(input, parserOutput, errorHandler,errorOutput);
            parser.parse(); // 开始语法分析
        } catch (IOException e) {
            System.err.println("Read File Error :" + inputFile);
        }
    }
    /*
    private static String tokenTypeToString(TokenType type) {
        return switch (type) {
            case INTTK -> "INTTK";
            case CHARTK -> "CHARTK";
            case VOIDTK -> "VOIDTK";
            case CONSTTK -> "CONSTTK";
            case IFTK -> "IFTK";
            case ELSETK -> "ELSETK";
            case FORTK -> "FORTK";
            case BREAKTK -> "BREAKTK";
            case CONTINUETK -> "CONTINUETK";
            case RETURNTK -> "RETURNTK";
            case GETINTTK -> "GETINTTK";
            case GETCHARTK -> "GETCHARTK";
            case PRINTFTK -> "PRINTFTK";
            case MAINTK -> "MAINTK";
            case IDENFR -> "IDENFR";
            case INTCON -> "INTCON";
            case CHRCON -> "CHRCON";
            case STRCON -> "STRCON";
            case PLUS -> "PLUS";
            case MINU -> "MINU";
            case MULT -> "MULT";
            case DIV -> "DIV";
            case MOD -> "MOD";
            case NOT -> "NOT";
            case AND -> "AND";
            case OR -> "OR";
            case EQL -> "EQL";
            case NEQ -> "NEQ";
            case LSS -> "LSS";
            case GRE -> "GRE";
            case LEQ -> "LEQ";
            case GEQ -> "GEQ";
            case ASSIGN -> "ASSIGN";
            case SEMICN -> "SEMICN";
            case COMMA -> "COMMA";
            case LPARENT -> "LPARENT";
            case RPARENT -> "RPARENT";
            case LBRACE -> "LBRACE";
            case RBRACE -> "RBRACE";
            case LBRACK -> "LBRACK";
            case RBRACK -> "RBRACK";
            // 其他符号
            case COLON -> "COLON";
            default -> "UNKNOWN";
        };
    }*/
}
