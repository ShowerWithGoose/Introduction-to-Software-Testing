package frontend;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class SrcFileLexer {
    private InputStream inputStream;
    private ArrayList<String> lines=new ArrayList<>();
    private int lineNumber=0;
    private int columnNumber=0;
    public SrcFileLexer(InputStream inputStream) {
        this.inputStream=inputStream;
    }
    public void readLines(){
        BufferedReader br=new BufferedReader(new InputStreamReader(inputStream));
        while(true){
            try {
                String lineNow=br.readLine();
                if(lineNow==null){
                    break;
                }else{
                    lines.add(lineNow);
                }
            }
            catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    public boolean endOfFile(){
        if(lineNumber>=lines.size()){
            return true;
        }else if(lineNumber==lines.size()-1&&columnNumber>=lines.get(lineNumber).length()){
            return true;
        }
        return false;
    }
    public boolean endOfLine(){
        if(endOfFile()){
            return true;
        }else{
            return columnNumber>=lines.get(lineNumber).length();
        }
    }
    public int getLineNumber(){
        return (this.lineNumber+1);
    }
    public String getLine(){
        if(endOfFile()){
            return null;
        }else{
            return lines.get(lineNumber);
        }
    }
    public Character getChar(){
        if(endOfLine()){
            return 0;
        }else{
            if(endOfLine()){
                return '\n';
            }else{
                return lines.get(lineNumber).charAt(columnNumber);
            }
        }
    }
    public String getSubStr(int length){
        if(endOfFile()){
            return null;
        } else{
          if(columnNumber+length>=lines.get(lineNumber).length()){
              return lines.get(lineNumber).substring(columnNumber);
          }else{
              return lines.get(lineNumber).substring(columnNumber,columnNumber+length);
          }
        }
    }
    //over one line -->column==0,line++
    public void moveForward(int length){
        if(endOfFile()){
            return;
        }else{
            if(columnNumber+length>=lines.get(lineNumber).length()){
                columnNumber=0;
                lineNumber++;
            }else{
                columnNumber+=length;
            }
        }
    }
    public void skipWhiteSpace(){
        while(!endOfFile()&&Character.isWhitespace(getChar())){
            moveForward(1);
        }
    }
    public void nextLine(){
        if (!endOfFile()){
            lineNumber++;
            columnNumber=0;
        }
    }
    public String getRemainingLine(){
        if(endOfFile()||endOfLine()){
            return null;
        }else{
            return getLine().substring(columnNumber);
        }
    }
    public String matchRemainingLine(Pattern pattern){
        String remainingLine=getRemainingLine();
        if(remainingLine==null){
            return null;
        }
        if(remainingLine.startsWith("'")&&pattern.pattern().equals("^'(.*?)'")&&remainingLine.substring(1,2).equals("\\")){
            return remainingLine.substring(0,4);
        }
        Matcher matcher=pattern.matcher(remainingLine);
        if (matcher.find()) {
            return matcher.group(0);
        } else {
            //        exception
            if(pattern.pattern().equals("^&&")&&remainingLine.startsWith("&")){
                return "&";
            }
            if(pattern.pattern().equals("^\\|\\|")&&remainingLine.startsWith("|")){
                return "|";
            }
            // not match
            return null;
        }
    }
}
