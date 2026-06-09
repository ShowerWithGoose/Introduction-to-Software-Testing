import frontend.Lexer;
import frontend.Token;

import java.io.*;
import java.util.List;

/**
* @Author:
* @Date: 2024/9/24 10:37 
*/

public class Compiler {
    public static void main(String[] args){
        File sourceFile = new File("testfile.txt"); //路径?
        Lexer lexer = Lexer.getInstance();
        try {
            lexer.init(sourceFile);
            while(lexer.next()){
                lexer.getTokens().add(new Token(lexer.getLexType(),lexer.getToken()));
            }
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
        if (lexer.isCorrect())
        {
            try{
                writeResultsToFile(lexer.getTokens(),"lexer.txt");
            }catch (IOException e){
                System.out.println("Error writing to file: " + e.getMessage());
            }
        }else{
            try{
                FileWriter fileWriter = new FileWriter("error.txt");
                BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
                bufferedWriter.write(lexer.getFalseLineNumber() + "x" + lexer.getFalseType());
            }catch(IOException e){
                System.out.println("Error writing to file: " + e.getMessage());
            }
        }
    }

    // 将词法分析结果写入文件
    private static void writeResultsToFile(List<Token> tokens, String fileName) throws IOException {
        FileWriter fileWriter = new FileWriter(fileName);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

        // 将每个 Token 对象按行写入文件
        for (Token token : tokens) {
            bufferedWriter.write(token.toString());
            bufferedWriter.newLine();  // 换行
        }

        // 关闭文件流
        bufferedWriter.close();
    }
}
