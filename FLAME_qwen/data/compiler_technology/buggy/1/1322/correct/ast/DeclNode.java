package ast;

import enum_package.DeclType;

public class DeclNode {
    // Decl -> ConstDecl | VarDecl
    public ConstDeclNode constDecl; // 常量声明节点（如果是常量声明）
    public VarDeclNode varDecl; // 变量声明节点（如果是变量声明）

    public DeclNode(ConstDeclNode constDecl, VarDeclNode varDecl) {
        this.constDecl = constDecl; // 设置常量声明
        this.varDecl = varDecl; // 设置变量声明
    }

    public void print() {
        if (constDecl != null) {
            constDecl.print();
        } else if (varDecl != null) {
            varDecl.print();
        }
    }
}

