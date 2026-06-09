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
        // 将 TokenType 映射到指定的单词类别码
        return switch (type) {
            case INT -> "INTTK";
            case CHAR -> "CHARTK";
            case VOID -> "VOIDTK";
            case CONST -> "CONSTTK";
            case IF -> "IFTK";
            case ELSE -> "ELSETK";
            case FOR -> "FORTK";
            case BREAK -> "BREAKTK";
            case CONTINUE -> "CONTINUETK";
            case RETURN -> "RETURNTK";
            case GETINT -> "GETINTTK";
            case GETCHAR -> "GETCHARTK";
            case PRINTF -> "PRINTFTK";
            case MAIN -> "MAINTK";
            case IDENTIFIER -> "IDENFR";
            case INT_CONST -> "INTCON";
            case CHAR_CONST -> "CHARCON";
            case STRING_CONST -> "STRCON";
            case PLUS -> "PLUS";
            case MINUS -> "MINU";
            case MULTIPLY -> "MULT";
            case DIVIDE -> "DIV";
            case MODULO -> "MOD";
            case NOT -> "NOT";
            case AND -> "AND";
            case OR -> "OR";
            case EQUAL -> "EQL";
            case NOT_EQUAL -> "NEQ";
            case LESS -> "LSS";
            case GREATER -> "GRE";
            case LESS_EQUAL -> "LEQ";
            case GREATER_EQUAL -> "GEQ";
            case ASSIGN -> "ASSIGN";
            case SEMICOLON -> "SEMICN";
            case COMMA -> "COMMA";
            case LEFT_PAREN -> "LPARENT";
            case RIGHT_PAREN -> "RPARENT";
            case LEFT_BRACE -> "LBRACE";
            case RIGHT_BRACE -> "RBRACE";
            case LEFT_BRACKET -> "LBRACK";
            case RIGHT_BRACKET -> "RBRACK";
            default -> "UNKNOWN";
        };
    }
}
