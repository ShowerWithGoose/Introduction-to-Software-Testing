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
public class FuncFParams {
//    FuncFParams â†’ FuncFParam { ',' FuncFParam }
    private List<FuncFParam> funcFParamList;
    private List<Token> commaList;

    public FuncFParams(List<FuncFParam> funcFParamList, List<Token> commaList) {
        this.funcFParamList = funcFParamList;
        this.commaList = commaList;
    }

    public void print(){
        funcFParamList.get(0).print();
        for(int i=0;i<commaList.size();i++){
            IO.parser_output(commaList.get(i).toString());
            funcFParamList.get(i+1).print();
        }
        IO.parser_output(Parser.nodeTypes.get(NodeType.FuncFParams));
    }
}
