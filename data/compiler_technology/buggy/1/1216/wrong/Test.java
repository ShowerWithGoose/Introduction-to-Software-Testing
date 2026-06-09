import frontend.lexer.Lexer;
import frontend.lexer.TokenList;
import frontend.parser.CompUnit;
import frontend.parser.Parser;
import frontend.parser.TokenHandler;
import output.Output;

public class Test {
    private static final String rootPath = "test/PublicTest/Parser/%c/testcase%s/testfile.txt";
    public static String getTestCase(char lev, int id) {
        return String.format(rootPath, lev, id);
    }
    public static void main(String[] args) {
        testSingle('A', 5);
    }

    public static void TestAll() {
        for (char lev = 'A'; lev < 'C'; lev++)
            for (int i = 1; i <= 10; i++) {
                testSingle(lev, i);
            }
    }
    public static void testSingle(char lev, int id) {
        Lexer lexer = Lexer.getLexer(getTestCase(lev, id));
        lexer.getTokenList();
        TokenList tokenList = lexer.getCorrectedTokenList();
        new Output<>(tokenList).printToFile("lexer.txt", false); // 打印lexer词法分析的结果
        new Output<>(lexer.getErrorList()).printToFile("error.txt", false); // 打印lexer词法分析过程中的错误

        TokenHandler tokenHandler =  new TokenHandler(tokenList);
        Parser.setHandler(tokenHandler);
        CompUnit compUnit = Parser.parseCompUnit(tokenHandler);
        new Output<>(compUnit).printToFile("parser.txt", false);
        new Output<>(tokenHandler.getErrorList()).printToFile("error.txt", true);
    }
}
