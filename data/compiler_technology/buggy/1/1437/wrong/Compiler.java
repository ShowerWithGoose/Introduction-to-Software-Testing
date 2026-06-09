import error.ErrorList;
import file.File;
import frontend.Lexer;
import frontend.Parser;
import frontend.SemanticAnalyzer;

public class Compiler {

    public static void main(String[] args) {
        Lexer.getInstance().setText(File.readFileToString(File.readPath));
        Lexer.getInstance().getToken();
        File.writeStringToFile(File.lexerPath, Lexer.getInstance().getTokenListAsString());

        Parser.getInstance().setTokenList(Lexer.getInstance().getTokenList());
        Parser.getInstance().parse();
        File.writeStringToFile(File.parserPath, Parser.getInstance().getASTAsString());

        SemanticAnalyzer.getInstance().setRoot(Parser.getInstance().getAST());
        SemanticAnalyzer.getInstance().semanticAnalysis();
        File.writeStringToFile(File.symbolPath, SemanticAnalyzer.getInstance().printSymbolTables());

        ErrorList.getInstance().sortErrors();
        File.writeStringToFile(File.errorPath, ErrorList.getInstance().getErrorsAsString());
    }
}