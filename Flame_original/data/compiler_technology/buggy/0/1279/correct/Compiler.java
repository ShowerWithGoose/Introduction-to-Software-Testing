import java.io.FileInputStream;
import java.io.InputStream;
import java.io.IOException;
import frontend.Lexer;
import frontend.Token;
import frontend.TokenType;
import frontend.Error;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Comparator;

public class Compiler {
    public static void main(String[] args) {
        String inputFile = "testfile.txt";
        try (InputStream input = new FileInputStream(inputFile)) {
            Lexer lexer = new Lexer(input);
            Token token;
            List<Token> tokens = new ArrayList<>();
            while ((token = lexer.getNextToken()).getType() != TokenType.EOF) {
                tokens.add(token);
            }
            // 检查是否有错误
            if (lexer.getErrors().isEmpty()) {
                // 无错误，输出词法分析结果到 lexer.txt
                try (BufferedWriter writer = new BufferedWriter(new FileWriter("lexer.txt"))) {
                    for (Token t : tokens) {
                        String tokenTypeCode = tokenTypeToString(t.getType());
                        writer.write(tokenTypeCode + " " + t.getLexeme());
                        writer.newLine();
                    }
                }
            } else {
                // 有错误，输出错误信息到 error.txt
                try (BufferedWriter writer = new BufferedWriter(new FileWriter("error.txt"))) {
                    // 按行号排序错误
                    List<Error> errors = lexer.getErrors();
                    errors.sort(Comparator.comparingInt(Error::getLineNumber));
                    for (Error e : errors) {
                        writer.write(e.getLineNumber() + " " + e.getErrorCode());
                        writer.newLine();
                    }
                }
            }
        } catch (IOException e) {
            System.err.println("Read File Error :" + inputFile);
        }
    }
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
    }

}
