package syntax;

import lexer.LexType;
import logger.Logger;

import java.util.Objects;

public class Exp {
    public static final LexType[] FIRST = AddExp.FIRST;

    private final AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = Objects.requireNonNull(addExp);
        Logger.logGood("<Exp>\n");
    }

    public AddExp getAddExp() {
        return addExp;
    }
}
