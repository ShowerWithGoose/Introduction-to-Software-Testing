
import SysY.LexicAnalysis.LexicAnalysis;
import SysY.LexicAnalysis.Token;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) throws IOException {
        // 开关
        boolean outputLexicAnalysis = true;
       
        // 输入
        File inputFile = new File("testfile.txt");
        File outputFile=new File("lexer.txt");
        FileReader fileReader = new FileReader(inputFile);
        FileWriter fileWriter=new FileWriter(outputFile);
        BufferedReader bufferedReader = new BufferedReader(fileReader);
        ArrayList<String> stringList = new ArrayList<>();
        String curString;
        while ((curString = bufferedReader.readLine()) != null) {
            stringList.add(curString);
        }
        // 符号表
        //SymbolTable symbolTable = new SymbolTable();
        // 词法分析
        LexicAnalysis lexicAnalysis = new LexicAnalysis(stringList);
        lexicAnalysis.analyse();
        ArrayList<Token> tokenList = lexicAnalysis.getTokenList();
        if (outputLexicAnalysis) {
            for (Token token : tokenList) {
                try (FileWriter writer = new FileWriter(outputFile,true)) {
                    writer.write(token.getTokenKey()+" "+token.getTokenString()+"\n");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        
       
        }
    }

