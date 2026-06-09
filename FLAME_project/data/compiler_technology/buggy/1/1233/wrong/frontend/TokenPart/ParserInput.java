package frontend.TokenPart;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class ParserInput {
    private ArrayList<String> lines;//用来存放输入文件的每一行
    private String inputLine;//代表把输入文件转成一行String
    private String filePath = "testfile.txt";//文件路径
    public ParserInput(){
        lines = new ArrayList<>();
        inputLine = null;
        initParser();
    }
    public void initParser(){
        //需要读入输入文件并且把文件内容转化给line
        //需要把一整个文件都加给inputLine
        StringBuilder sb = new StringBuilder();
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                lines.add(line); // 将每一行添加到 ArrayList
                sb.append(line);
                sb.append("\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        inputLine = sb.toString();
    }
    public ArrayList<String> getLines(){
        return lines;
    }
    public String getInputLine(){
        return inputLine;
    }
}
