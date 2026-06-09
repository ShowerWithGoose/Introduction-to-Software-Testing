package frontend.parser.func;

import java.util.ArrayList;

import frontend.TokenIterator;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

//函数形参表		FuncFParams    ==> FuncFParam { ',' FuncFParam }
public class FuncFParams implements SyntaxNode {
    private final String name = "<FuncFParams>";
    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();
    private ArrayList<FuncFParam> funcFParams = new ArrayList<>();

    public FuncFParams(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        children.forEach(child -> sb.append(child.syntaxPrinter()));
        sb.append(name + "\n");
        return sb.toString();
    }

    @Override
    public boolean parse() {
        FuncFParam funcFParam = new FuncFParam(tokens);
        funcFParam.parse();
        children.add(funcFParam);
        funcFParams.add(funcFParam);

        while (tokens.hasNext()) {
            Token checkComma = tokens.next();
            if (checkComma.getType().equals(TokenType.COMMA)) {
                children.add(checkComma);

                funcFParam = new FuncFParam(tokens);
                funcFParam.parse();
                children.add(funcFParam);
                funcFParams.add(funcFParam);
            } else {
                tokens.stepBack(1);
                break;
            }
        }
        return true;
    }

}
