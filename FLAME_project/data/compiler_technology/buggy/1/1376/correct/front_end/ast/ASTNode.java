package front_end.ast;

import front_end.lexer.TokenType;

import java.util.ArrayList;
import java.util.List;

public class ASTNode {

    private Object type;              // 节点类型
    private String value;               // 节点值（如标识符名称、常量值等）
    private List<Object> children = new ArrayList<>();     // 子节点列表
    private boolean isArr = false;      // 是否是数组

    public ASTNode(TokenType type, String value) {
        this.type = type;
        this.value = value;
        this.children = new ArrayList<>();
    }

    public ASTNode(NodeType type, boolean isArr, List<Object> children) {
        this.type = type;
        this.isArr = isArr;
        this.children = children;
    }

    public ASTNode(NodeType type, List<Object> children) {
        this.type = type;
        this.children = children;
    }

    public ASTNode(NodeType type, ASTNode child) {
        this.type = type;
        this.children = new ArrayList<>();
        if (child != null) {
            this.children.add(child);
        }
    }

    // 添加子节点
    public void addChild(ASTNode child) {
        this.children.add(child);
    }

    // Getter 和 Setter 方法
    public Object getType() {
        return type;
    }

    public void setType(NodeType type) {
        this.type = type;
    }

    public String getValue() {
        StringBuilder result = new StringBuilder();
        if (type == TokenType.STRCON) {
            result.append("\"");
        }
        if (type == TokenType.CHRCON) {
            result.append("'");
        }
        for (int i = 0; i < value.length(); i++) {
            char c = value.charAt(i);
            if (c == '\n') {
                result.append("\\n");
            } else if (c == '\t') {
                result.append("\\t");
            } else if (c == '\r') {
                result.append("\\r");
            } else if (c == '\b') {
                result.append("\\b");
            } else if (c == '\f') {
                result.append("\\f");
            } else if (c == '\\') {
                result.append("\\\\");
            } else if (c == '\'') {
                result.append("\\'");
            } else if (c == '\"') {
                result.append("\\\"");
            } else if (c == '\0') {
                result.append("\\0");
            } else if (c == '\007') {
                result.append("\\a");
            } else if (c == '\013') {
                result.append("\\v");
            } else {
                result.append(c);
            }
        }
        if (type == TokenType.STRCON) {
            result.append("\"");
        }
        if (type == TokenType.CHRCON) {
            result.append("'");
        }
        return result.toString();
//        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }

    public List<Object> getChildren() {
        return children;
    }

    public void setChildren(List<Object> children) {
        this.children = children;
    }

}