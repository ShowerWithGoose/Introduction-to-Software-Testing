package Parser.Func;

import Lexer.Token;
import Lexer.TokenListIterator;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/13
 */
public class FuncFParamsParser {
    private TokenListIterator iterator;
    private FuncFParam funcFParam;
    private ArrayList<Token> commmas;
    private ArrayList<FuncFParam> funcFParamArrayList;

    public FuncFParamsParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }
    public FuncFParams funcFParamsParse()
    {
        commmas=new ArrayList<>();
        funcFParamArrayList=new ArrayList<>();
        FuncFParamParser funcFParamParser=new FuncFParamParser(iterator);
        this.funcFParam=funcFParamParser.funcFParamParse();
        //System.out.println(this.funcFParam.print_tree()+"吴安邦是猪");
        Token next =iterator.readNextToken();
        while(next.getValue().equals(","))
        {
            this.commmas.add(next);
            this.funcFParamArrayList.add(funcFParamParser.funcFParamParse());
            next=iterator.readNextToken();
        }
//        for(int i=0;i<funcFParamArrayList.size();i++){
//            System.out.println(this.funcFParamArrayList.get(i).print_tree()+"吴安邦是猪zhu");
//        }
        iterator.unReadToken(1);
        return new FuncFParams(funcFParam,commmas,funcFParamArrayList);
    }
}
