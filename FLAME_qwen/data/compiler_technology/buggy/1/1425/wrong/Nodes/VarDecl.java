package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 18:58
 */
import java.util.*;
import Token.*;
import Utils.IO;
import frontend.*;
/**
 * @author:
 * TODO  
 * 2024/9/28 18:58
 */
public class VarDecl {
//     VarDecl â†’ BType VarDef { ',' VarDef } ';'
    private BType bType;
    private List<VarDef> varDefList;
    private List<Token> commaList;
    private Token semicn;

    public VarDecl(BType bType, List<VarDef> varDefList, List<Token> commaList, Token semicn) {
        this.bType = bType;
        this.varDefList = varDefList;
        this.commaList = commaList;
        this.semicn = semicn;
    }

    public void print(){
        bType.print();
        varDefList.get(0).print();
        for(int i=0;i<commaList.size();i++){
            IO.parser_output(commaList.get(i).toString());
            varDefList.get(i+1).print();
        }
        IO.parser_output(semicn.toString());
        IO.parser_output(Parser.nodeTypes.get(NodeType.VarDecl));
    }

    public BType getbType() {
        return bType;
    }

    public List<VarDef> getVarDefList() {
        return varDefList;
    }

    public List<Token> getCommaList() {
        return commaList;
    }

    public Token getSemicn() {
        return semicn;
    }
}
