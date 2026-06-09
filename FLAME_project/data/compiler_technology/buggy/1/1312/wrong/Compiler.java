//自动对齐 ctrl+alt+L
import SysY.Error.theError;
import SysY.LexicAnalysis.LexicAnalysis;
import SysY.LexicAnalysis.Token;
import SysY.SyntaxAnalysis.SyntaxAnalysis;


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;

public class Compiler {
    public static ArrayList<theError> errList=new ArrayList<>();

    public static void main(String[] args) throws IOException {
        // 开关
        boolean outputLexicAnalysis = true;
        boolean outputSyntaxAnalysis=true;
       
        // 输入
        File inputFile = new File("testfile.txt");
        File outputFile=new File("parser.txt");
        FileReader fileReader = new FileReader(inputFile);
        FileWriter fileWriter=new FileWriter(outputFile);
        BufferedReader bufferedReader = new BufferedReader(fileReader);
        ArrayList<String> stringList = new ArrayList<>();//原文
        String curString;

        while ((curString = bufferedReader.readLine()) != null) {
            //读入testfile原文
            stringList.add(curString);
        }


        LexicAnalysis lexicAnalysis = new LexicAnalysis(stringList);//建立词法分析器
        lexicAnalysis.analyse();//分析
        ArrayList<Token> tokenList = lexicAnalysis.getTokenList();//得到结果
        errList.addAll(errList.size(),lexicAnalysis.LexicErrorList);
        if (outputLexicAnalysis) {//开关
            for (Token token : tokenList) {
                outputFile=new File("lexic.txt");
                try (FileWriter writer = new FileWriter(outputFile,true)) {
                    writer.write(token.getTokenKey()+" "+token.getTokenString()+"\n");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        SyntaxAnalysis syntaxAnalysis=new SyntaxAnalysis(tokenList);
        syntaxAnalysis.analysis();
        errList.addAll(errList.size(),syntaxAnalysis.SyntaxErrorList);
        if(outputSyntaxAnalysis){
            outputFile=new File("parser.txt");
            for(String i :syntaxAnalysis.syntaxArrayList){
                try (FileWriter writer = new FileWriter(outputFile,true)) {
                    writer.write(i+"\n");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        if(!errList.isEmpty()){
            errList.sort(Comparator.comparingInt(theError::getRow));
            outputFile=new File("error.txt");
            for(theError err : errList){
                try (FileWriter writer = new FileWriter(outputFile,true)) {
                    writer.write(err.row+" "+err.type+"\n");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }





    }
    }

