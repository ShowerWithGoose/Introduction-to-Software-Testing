package frontend.Parser.AST;

import frontend.Lexer.Token;
import frontend.Lexer.TokenType;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;

public class CompUnit extends AstNode {

    public void parse() throws IOException {
        while (getPreTokenType(2) != TokenType.LPARENT) {
            Decl decl = new Decl();
            decl.parse();
        }
        while (getPreTokenType(1) != TokenType.MAINTK) {
            FuncDef funcDef = new FuncDef();
            funcDef.parse();
        }
        MainFuncDef mainFuncDef = new MainFuncDef();
        mainFuncDef.parse();
        stringBuilder.append("<CompUnit>").append("\n");
        Path path2 = Paths.get("parser.txt");
        Files.writeString(path2, stringBuilder.toString());
    }
}
