package frontend.nodes;

import java.util.ArrayList;

public class ASTNode {
    public String word; // 单词
    public String type; // 单词类型
    public String VnName; // 非终结符的名字
    public int line; // 错误结点所在行号，用于错误处理
    public ArrayList<ASTNode> children=new ArrayList<>();
    public boolean isLegal; // 结点是否标志
    public char errorType; // 错误结点的错误类型 a b c……
    public boolean isTerminal; // 结点是否为终结符
    public ASTNode parent; // 指向父节点

    // 终结符结点构造规则
    public ASTNode(String word, String type) {
        this.word = word;
        this.type = type;
        this.isLegal = true;
        this.isTerminal = true;
    }
    // 非终结符结点构造规则
    public ASTNode(String VnName) {
        this.VnName = VnName;
        this.isLegal = true;
        this.isTerminal = false;
    }
    // 截至到语法分析的错误结点构造规则，目前的错误只在终结符出现
    public ASTNode(String word, String type,char errorType,int line) {
        this.word = word;
        this.type = type;
        this.line = line;
        this.isLegal = false;
        this.errorType = errorType;
    }

    public void addChild(ASTNode child) {
        children.add(child);
        child.parent=this; // parent.addChild(tmp) --> 赋值tmp.parent = parent
    }

    public void delete(){
        children.remove(children.size()-1);
    }

    //后序遍历语法树
    public void postOrderVisit() {
        if(!children.isEmpty()){
            for(ASTNode child : children) {
                child.postOrderVisit();
            }
        }
        printNodeInfo(); // 打印节点信息
    }

    private void printNodeInfo(){
        if(isLegal) {
            if(isTerminal) {
                writeToFile("parser.txt", type + " " + word);
            }
            else {
                if(!VnName.equals("BType") && !VnName.equals("Decl") && !VnName.equals("BlockItem")){
                    writeToFile("parser.txt", "<" + VnName + ">");
                }
            }
        }
        else{
            writeToFile("error.txt", line + " " + errorType);
        }
    }

    private void writeToFile(String fileName, String content) {
        try (java.io.FileWriter fileWriter = new java.io.FileWriter(fileName, true)) {
            fileWriter.write(content + "\n");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
