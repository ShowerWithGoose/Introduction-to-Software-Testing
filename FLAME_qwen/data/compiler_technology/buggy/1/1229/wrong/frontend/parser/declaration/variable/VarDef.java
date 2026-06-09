package frontend.parser.declaration.variable;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.declaration.variable.initval.InitVal;
import frontend.parser.expression.ConstExp;
import frontend.parser.terminal.Ident;
import middle.error.Error;
import middle.error.ErrorTable;

import java.util.ArrayList;

public class VarDef implements Node {
    private final String name = "<VarDef>";
    /* VarDef Attributes */
    private Ident ident = null;
    private ArrayList<Token> leftBracks = new ArrayList<>();
    private ArrayList<ConstExp> constExps = new ArrayList<>();
    private ArrayList<Token> rightBracks = new ArrayList<>();
    /* Init Val */
    private Token eq = null;
    private InitVal initVal = null;
    /* VarDefEle */
    //private VarDefEle varDefEle = null;


    private TokenList tokenList;

    public VarDef(TokenList tokenList) {
        this.tokenList = tokenList;
        this.leftBracks = new ArrayList<>();
        this.constExps = new ArrayList<>();
        this.rightBracks = new ArrayList<>();
    }

    public void parseVarDef(){
        Ident ident1 = new Ident(tokenList);
        ident1.parseIdent();
        this.ident = ident1;
        Token token = tokenList.seeAfterToken(0);
        while (token.getType().equals(TokenType.LBRACK)){
            //其实只需要if,因为只会有一维数组
            token = tokenList.getNextToken();
            this.leftBracks.add(token);
            ConstExp constExp = new ConstExp(tokenList);
            constExp.parseConstExp();
            this.constExps.add(constExp);


            if (tokenList.seeAfterToken(0).getType().equals(TokenType.RBRACK)){
                token = tokenList.getNextToken();
                this.rightBracks.add(token);
            } else {
                //handle error k
                Token token1 = tokenList.seeAfterToken(-1);
                int lineNum = token1.getLineNum();
                middle.error.Error error = new Error(lineNum,"k");
                ErrorTable.addError(error);
                token = new Token(TokenType.RBRACK,lineNum,"]");
                this.rightBracks.add(token);
                //自己捏造个)放这，防止以后分析到这，再出错
            }


            token = tokenList.seeAfterToken(0);
        }
        if (token.getType().equals(TokenType.ASSIGN)){
            this.eq = tokenList.getNextToken();
            InitVal initVal1 = new InitVal(tokenList);
            initVal1.parseInitVal();
            this.initVal = initVal1;
        }
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();

        sb.append(ident.syntaxOutput());
        if (leftBracks != null && constExps != null && rightBracks != null &&
                leftBracks.size() == constExps.size() && constExps.size() == rightBracks.size()) {
            int len = leftBracks.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.leftBracks.get(i).syntaxOutput());
                sb.append(this.constExps.get(i).syntaxOutput());
                sb.append(this.rightBracks.get(i).syntaxOutput());
            }
        }
        if (this.eq != null){
            sb.append(this.eq.syntaxOutput());
            sb.append(this.initVal.syntaxOutput());
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
