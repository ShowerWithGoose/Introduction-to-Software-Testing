package frontend.Lexer;

import frontend.Parser.TreeNode;

import java.io.PrintWriter;

/**
 * @author
 * @Description:
 * @date 2024/10/3 18:12
 */
public class Token extends TreeNode {
    private String type;
    private String value;
    private int lineNum;

    public Token(String type, String value, int lineNum){
        this.type = type;
        this.value = value;
        this.lineNum = lineNum;
    }

    public void setType(String type){
        this.type = type;
    }

    public void setValue(String value){
        this.value = value;
    }

    public void setLineNum(int lineNum){
        this.lineNum = lineNum;
    }

    public String getType(){
        return type;
    }

    public String getValue(){
        return value;
    }

    public int getLineNum(){
        return lineNum;
    }

    @Override
    public void print_tree() {
        System.out.println(this.type + " " + this.value);
    }
    public void print_tree_to_file(PrintWriter printWriter){
        printWriter.println(this.type + " " + this.value);
    }
}
