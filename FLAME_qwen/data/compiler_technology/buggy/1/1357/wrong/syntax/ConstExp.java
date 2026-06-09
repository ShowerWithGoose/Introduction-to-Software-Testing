package syntax;

import lexer.LexType;
import logger.Logger;

import java.util.Objects;

public class ConstExp {
    public static final LexType[] FIRST = AddExp.FIRST;

    private final AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = Objects.requireNonNull(addExp);
        Logger.logGood("<ConstExp>\n");
    }
}
