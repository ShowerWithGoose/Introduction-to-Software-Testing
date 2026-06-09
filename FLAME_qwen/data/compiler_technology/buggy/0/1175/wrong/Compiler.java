import frontend.Lexer;
import frontend.LexType;
import java.io.*;

public class Compiler {
    public static Lexer lexer;

    public static void main(String[] args) throws IOException {
        try(FileWriter fw = new FileWriter("lexer.txt")){
            fw.write("");
        } catch(IOException e){e.printStackTrace();}
        lexer = Lexer.getInstance();
        lexer.getSource();
        while(!lexer.isFinish()){
           // System.out.println(1);
            lexer.next();
        }
        if(lexer.isLegal()){
            try(FileWriter fw = new FileWriter("lexer.txt",true)){
                for(int i=0;i<lexer.wordDatas.size();i++){
                    fw.write(lexer.wordDatas.get(i).lexType + " " + lexer.wordDatas.get(i).token + "\n");
                }
            } catch(IOException e){
                e.printStackTrace();
            }
        }
        else{
            try(FileWriter fw = new FileWriter("error.txt",true)){
                for(int i=0;i<lexer.illegalWordDatas.size();i++){
                    fw.write(lexer.illegalWordDatas.get(i).lineNum + " " + lexer.illegalWordDatas.get(i).errorType + "\n");
                }
            } catch(IOException e){
                e.printStackTrace();
            }
        }
    }
}