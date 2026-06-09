import frontend.Lexer;
import frontend.Parser;
import node.Node;
import setting.Setting;
import token.Token;
import error.Error;
import util.IOUtil;

import java.awt.image.WritableRaster;
import java.io.IOException;
import java.util.List;

/**
 * ClassName: Compiler
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author
 * @Create 2024/9/23 19:19
 * @Version 1.0
 */
public class Compiler {
    public static StringBuilder printInfo = new StringBuilder();

    public static void main(String[] args) throws IOException {
        String code = IOUtil.read(Setting.readInPath);
        Lexer.lexer.parse(code);
//        lexerInfoPrint();
        Parser.parser.parse(Lexer.lexer.tokens);
        parserInfoPrint();
//        parserInfoPrintDeBug();

    }

    public static void lexerInfoPrint() {
        List<Token> tokens = Lexer.lexer.tokens;
        List<Error> errors = Error.errors;
        String writePath = Setting.writeOutPath;
        if (errors.size() > 0) {
            writePath = Setting.writeErrorPath;
            for (Error error : errors) {
                printInfo.append(error.lineNo + " " + error.type + "\n");
            }
        } else {
            for (Token token : tokens) {
//            System.out.println(token.content
//                    + " " + token.type
//                    + " " + token.lineNo
//                    + " " + token.columnTokenNo
//                    + " " + token.columnCharNo);
//                printInfo.append(token.type + " " + token.content + "\n");
//                printInfo.append(token.type + " "
//                        + token.content + " "
//                        + token.lineNo + " " + token.thisLineTokenNo + "\n");
                printInfo.append(token.type).append(" ").append(token.content).append("\n");
            }
        }
        IOUtil.write(writePath, printInfo.toString());
    }

    public static void parserInfoPrint(){
        StringBuilder info = new StringBuilder();
        String writePath = "parser.txt";
        Error lastError = null;
        if(Error.errors.size() > 0){
            for (Error error : Error.errors) {
                if(lastError != null){
                    if(error.lineNo == lastError.lineNo && error.type == lastError.type){
                        continue;
                    }
                }
                info.append(error.lineNo).append(" ").append(error.type).append("\n");
                lastError = error;
            }
            writePath = "error.txt";
        }else{
            info = Parser.parser.compUnit.getPrintInfo();
        }
        IOUtil.write(writePath, info.toString());
    }
    public static void parserInfoPrintDeBug(){
        StringBuilder info = new StringBuilder();
        String writePath;
        if(Error.errors.size() > 0){
            for (Error error : Error.errors) {
                info.append(error.lineNo + " " + error.type + "\n");
            }
            writePath = "error.txt";
            IOUtil.write(writePath, info.toString());
        }
        info = Parser.parser.compUnit.getPrintInfo();
//        info = getPrintInfoSafely(Parser.parser.compUnit);
        writePath = "parser.txt";
        IOUtil.write(writePath, info.toString());
    }


}
