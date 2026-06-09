package frontend;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class FileLexer {
    private InputStream inputStream;
    private ArrayList<String> lines;
    private int lineNo; //行指针
    private int position; //行中的位置

    public FileLexer(InputStream inputStream) throws IOException {
        this.inputStream = inputStream;
        this.lines = new ArrayList<>();
        this.lineNo = 0;
        this.position = 0;
        scanLines();
    }

    public void scanLines() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        try{
            String newLine = null;
            while((newLine = reader.readLine()) != null){
                lines.add(newLine);
                //System.out.println(newLine);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        //System.out.println("input success");
    }

    public boolean endOfFile(){
        return lineNo >= lines.size();
    }

    public boolean endOfLine(){
        if(endOfFile()){
            return true;
        } else if(lineNo >= lines.size()){
            return true;
        }
        return position >= lines.get(lineNo).length();
    }
    public int getLineNo(){
        return lineNo + 1;
    }

    public String getLine(){
        if(endOfFile()){
            return "";
        } else{
            return lines.get(lineNo);
        }
    }
    //得到当前位置的字符
    public char getChar(){
        if(endOfLine()){
            return '\n';
        } else if(endOfFile()){
            return 0;
        } else{
            return getLine().charAt(position);
        }
    }

    public boolean isBlankSpace(char ch){
        return Character.isWhitespace(ch);
    }

    public void jumpOverBlankSpace(){  //跳过空格
        while(!endOfFile() && isBlankSpace(getChar())){
            move(1);
        }
    }

    public void move(int stepNum){
        int temp = stepNum;
        while(!endOfFile() && temp > 0){
            if(temp + position < getLine().length()){
                position += temp;
                temp = 0;
            } else {
                temp -= (getLine().length() - position + 1);
                lineNo++;
                //length不计换行符
                position = 0;
            }
        }
    }

    public void jumpCurrentLine(){
        if(!endOfFile()){
            lineNo++;
            position = 0;
        }
    }

    public String getSubstring(int len){
        if(endOfFile()){
            return "";
        }else if(position + len >= getLine().length()){
            return getLine().substring(position);
        } else {
            return getLine().substring(position, position + len);
        }
    }

    public String getLineRest(){ //该行剩下未进行词法分析部分
        if(endOfFile() || endOfLine()){
            return "";
        } else {
            return getLine().substring(position);
        }
    }

    public String matchTheStr(Pattern pattern){
        String str = getLineRest();
        Matcher matcher = pattern.matcher(str);

        if(matcher.find()){
            return matcher.group(0); //返回匹配到的第一个
        } else {
            return null; //没有匹配到
        }
    }
}
