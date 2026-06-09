package SysY.SyntaxAnalysis;

import java.util.ArrayList;

public class ASTnode {
    public String type;
    public ArrayList<String> typeson;//CompUnit → {Decl} {FuncDef} MainFuncDef 则这个Arraylist中包含{Decl} {FuncDef} MainFuncDef
    public ASTnode father;
    public ArrayList<ASTnode> sons=new ArrayList<>();
    public ASTnode(String type,ASTnode father){
        this.type=type;
        this.father=father;
    }

}
