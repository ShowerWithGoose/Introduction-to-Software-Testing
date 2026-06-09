import frontend.LexicalAnalysis.LexicalMain;
import frontend.SyntaxAnalysis.SyntaxMain;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Compiler {
    public static void main(String[] args) throws IOException{
        //输出开关
        boolean lexPrint = true;
        boolean lexErrPrint = false;
        boolean parserPrint = true;
        boolean parserErrPrint = true;
        //按行存储待编译文件
        ArrayList<String> stringInLine = new ArrayList<>();
        File testfile = new File("testfile.txt");
        FileReader fr = new FileReader(testfile);
        Scanner sc = new Scanner(fr);
        while(sc.hasNextLine()){
            String line = sc.nextLine();
            //line中没有末尾换行符
            stringInLine.add(line);
        }
        fr.close();
        /*词法分析*/
        LexicalMain lexicalMain = new LexicalMain(stringInLine);
        lexicalMain.runLexer();
        if(lexPrint){
            lexicalMain.writeWordsToFile("lexer.txt");
        }
        if(lexErrPrint){
            lexicalMain.writeErrorsToFile("error.txt");
        }
        /*语法分析*/
        SyntaxMain syntaxMain = new SyntaxMain(lexicalMain.getWordList(),lexicalMain.getErrorList());
        syntaxMain.buildAst();
        if(parserPrint){
            syntaxMain.writeResToFile("parser.txt");
        }
        if(parserErrPrint){
            syntaxMain.writeErrorsToFile("error.txt");
        }

    }
}