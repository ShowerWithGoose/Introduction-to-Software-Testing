
import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String path = "testfile.txt"; // 指定文件路径
        StringBuilder contentBuilder = new StringBuilder();

        try (BufferedReader reader = new BufferedReader(new FileReader(path))) {
            String line;
            while ((line = reader.readLine()) != null) {
                contentBuilder.append(line).append("\n"); // 读取每一行并追加换行符
            }
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
        }
        Preprocess preprocess=new Preprocess(contentBuilder);
        StringBuilder afterPreProcess=preprocess.process();
        // 将读取的内容转换为String
        String content = afterPreProcess.toString();
        //System.out.println(content);
        LexicalAnalyzer lexicalAnalyzer =new LexicalAnalyzer(content);
        try {
            FileWriter fileWriter = new FileWriter("lexer.txt", true); // true 表示追加写入
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
            lexicalAnalyzer.parse();
            for (Token token :lexicalAnalyzer.getTokens()){
                bufferedWriter.write(token.toString());
                bufferedWriter.newLine(); // 写入换行符
            }
            bufferedWriter.close();
        } catch (LexicalException e) {
            FileWriter fileWriter = new FileWriter("error.txt", true); // true 表示追加写入
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
            bufferedWriter.write(e.toString());
            bufferedWriter.newLine();
            bufferedWriter.close();
            //e.print();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        // 使用LexicalAnalyzer处理读取的内容
//        LexicalAnalyzer analyzer = new LexicalAnalyzer(content);
//        try {
//            ArrayList<HashMap<Word, String>> result = analyzer.parse();
//            // 输出或处理结果
//        } catch (Exception e) {
//            System.err.println("Error during lexical analysis: " + e.getMessage());
//        }
    }
}
