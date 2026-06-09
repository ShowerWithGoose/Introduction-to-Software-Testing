import frontend.*;
public class Compiler {
    public static void main(String[] args){
        Lexer.getInstance().handle("testfile.txt");
    }
}
