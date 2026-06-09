package Parser.Func;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.Exp.Exp;
import Parser.Exp.ExpParser;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/13
 */
public class FuncRParamsParser {
    private TokenListIterator iterator;
    /* FuncRParams Attributes */
    private Exp firstExp = null;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<Exp> exps = new ArrayList<>();

    public FuncRParamsParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }
    public FuncRParams funcRParamsParse()
    {
        this.commas = new ArrayList<>();
        this.exps = new ArrayList<>();
        ExpParser expParser = new ExpParser(this.iterator);
        firstExp = expParser.expParse();
        //System.out.println("吴安邦变猪"+this.firstExp.print_tree());
        Token next = this.iterator.readNextToken();
        while(next.getValue().equals(","))
        {
            this.commas.add(next);
            this.exps.add(expParser.expParse());
            next = this.iterator.readNextToken();
        }
        this.iterator.unReadToken(1);
        return new FuncRParams(firstExp,commas,exps);
    }

}
