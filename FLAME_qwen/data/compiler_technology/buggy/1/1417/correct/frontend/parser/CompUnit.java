package frontend.parser;

import frontend.error.TokenError;
import frontend.lexer.Token;
import frontend.parser.declaration.Decl;
import frontend.parser.function.FuncDef;
import frontend.parser.function.MainFuncDef;

import java.util.ArrayList;
import java.util.Stack;

// CompUnit -> {Decl} {FuncDef} MainFuncDef
// 三个部分的先后顺序确定
public class CompUnit extends Node {

    public CompUnit(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        // 最开始startLine和endLine还未知
        super(startLine, endLine, name, nodes);
    }

    public String syntaxOutput(){
        // 要后序遍历语法树
        StringBuilder sb = new StringBuilder();
        Stack<Node> stack = new Stack<>();
        ArrayList<String> post = new ArrayList<>();
        stack.add(this);
        while (!stack.isEmpty()) {
            Node node = stack.pop();
            if (node instanceof Token) {
                Token token = (Token) node;
                post.add(token.toString());
            } else {
                post.add(node.getName());
            }
            // 终结符直接给nodes传入了null
            if (node.getNodes() != null) {
                stack.addAll(node.getNodes());
            }
        }

        for (int i = post.size() - 1; i >= 0; i--) {
            String s = post.get(i);
            if (!s.equals("") && !s.equals("<BlockItem>") && !s.equals("<Decl>") && !s.equals("<BType>")){
                sb.append(post.get(i) + "\n");
            }
        }
        return sb.toString();
    }
}
