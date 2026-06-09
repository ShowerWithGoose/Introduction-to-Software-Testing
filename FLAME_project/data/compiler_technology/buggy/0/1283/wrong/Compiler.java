import java.io.*;
import Lexer.Token;
/**
 *
 * <p>Project: Compiler - Compiler
 * <p>Powered by berry On 2024-09-20 
 *
 * @author
 * @version 1.0
 */
import Lexer.Lexer;
public class Compiler {
    public static void main(String[] args){
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter("./lexer.txt", false)); // 设置为false以清空文件
            writer.close(); // 关闭流，这将清空文件
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter("./error.txt", false)); // 设置为false以清空文件
            writer.close(); // 关闭流，这将清空文件
        } catch (IOException e) {
            e.printStackTrace();
        }
        Lexer lexer=Lexer.getLexer();
        lexer.tokens.clear();//之后可以保存
        lexer.isError=false;
        //System.out.println(new Token(Token.Type.NONE,"",0).type);
        try {
            BufferedReader reader = new BufferedReader(new FileReader("./testfile.txt"));
            String line;
            while ((line = reader.readLine()) != null) {
                lexer.line=line;
                lexer.token="";
                lexer.curPos=0;
                lexer.isEnd=false;
                lexer.lineNum++;
                lexer.isEnd=false;
                lexer.analyseLine();
                //System.out.println(lexer.lineNum);
            }
            reader.close();
        } catch (IOException e) {
            System.out.print("input test.txt Exception");
        }
        //System.out.print("isError"+lexer.isError);
        if(!lexer.isError){
            lexer.output();
        }else{
            try {
                BufferedWriter writer = new BufferedWriter(new FileWriter("./error.txt", false));
                writer.write(lexer.errorLine+" "+"a");
                writer.close(); // 关闭流，这将清空文件
            } catch (IOException e) {
                e.printStackTrace();
            }
            //System.out.println(lexer.errorLine+" "+"a");
        }
    }
}
