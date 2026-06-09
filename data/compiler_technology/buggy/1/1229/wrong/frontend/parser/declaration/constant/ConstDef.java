package frontend.parser.declaration.constant;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.declaration.constant.constinitval.ConstInitVal;
import frontend.parser.expression.ConstExp;
import frontend.parser.terminal.Ident;
import middle.error.Error;
import middle.error.ErrorTable;

import java.util.ArrayList;

public class ConstDef implements Node {
    private final String name = "<ConstDef>";
    private Ident ident;
    //TODO 实际上不会有二维数组，所以不需要arraylist
    private ArrayList<Token> leftBracks; // '['
    private ArrayList<ConstExp> constExps;
    private ArrayList<Token> rightBracks; // ']'
    private Token eq; // '='
    private ConstInitVal constInitval;

    private TokenList tokenList;

    public ConstDef(TokenList tokenList) {
        this.tokenList = tokenList;
        this.leftBracks = new ArrayList<>();
        this.constExps = new ArrayList<>();
        this.rightBracks = new ArrayList<>();
    }

    public void parseConstDef(){
        Ident ident1 = new Ident(tokenList);
        ident1.parseIdent();
        this.ident = ident1;
        Token token = tokenList.getNextToken();
        while (token.getType().equals(TokenType.LBRACK)){
            this.leftBracks.add(token);
            //ConstExp
            ConstExp constExp = new ConstExp(tokenList);
            constExp.parseConstExp();
            this.constExps.add(constExp);
            //TODO handle error

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




            token = tokenList.getNextToken();
        }
        //假设一定是 = TODO handle error
        this.eq = token;
        ConstInitVal constInitVal = new ConstInitVal(tokenList);
        constInitVal.parseConstInitVal();
        this.constInitval = constInitVal;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ident.syntaxOutput());
        if (this.leftBracks != null && this.rightBracks != null && this.constExps != null &&
                this.leftBracks.size() == this.constExps.size() &&
                this.constExps.size() == this.rightBracks.size()) {
            int len = leftBracks.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.leftBracks.get(i).syntaxOutput());
                sb.append(this.constExps.get(i).syntaxOutput());
                sb.append(this.rightBracks.get(i).syntaxOutput());
            }
        }
        sb.append(this.eq.syntaxOutput());
        sb.append(this.constInitval.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
