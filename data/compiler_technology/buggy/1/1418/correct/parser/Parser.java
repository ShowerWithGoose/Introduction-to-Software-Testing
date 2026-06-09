package parser;

import common.GlobalData;
import model.Token;
import model.Tokens;
import model.TokensIterator;

import java.util.List;

public class Parser {
    public void run() {
        Tokens instance = Tokens.getInstance();
        List<Token> tokens = instance.get();
        TokensIterator iterator = new TokensIterator(tokens);

        //分析CompUnit
        CompUnitParser compUnitParser = new CompUnitParser();
        GlobalData.CompUnitNode = compUnitParser.run(iterator);
    }
}
