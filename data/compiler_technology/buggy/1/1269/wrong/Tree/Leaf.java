package Tree;

import frontend.Lexer;

import java.io.BufferedWriter;
import java.io.IOException;

public class Leaf implements Node{
    private Lexer.Type type;
    private String content;
    
    public Leaf(Lexer.Type t, String c) {
        this.type = t;
        this.content = c;
    }
    
    @Override
    public void postOrderTraversal(BufferedWriter writer) {
        try {
            writer.write(type.name());
            writer.write(" ");
            writer.write(content);
            writer.newLine(); // 写入一个新行字符
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    
    @Override
    public void postOrderTraversal() {
        System.out.println(type.name() + " " + content);
    }
}
