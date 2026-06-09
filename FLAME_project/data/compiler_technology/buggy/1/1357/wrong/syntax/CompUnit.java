package syntax;

import lexer.LexType;
import logger.Logger;

import java.util.Arrays;
import java.util.Objects;
import java.util.stream.Stream;

public class CompUnit {
    public static final LexType[] FIRST = Stream.concat(Stream.concat(Arrays.stream(Decl.FIRST), Arrays.stream(FuncDef.FIRST)), Arrays.stream(MainFuncDef.FIRST)).toArray(LexType[]::new);

    private final Decl[] decls;
    private final FuncDef[] funcDefs;
    private final MainFuncDef mainFuncDef;

    public CompUnit(Decl[] decls, FuncDef[] funcDefs, MainFuncDef mainFuncDef) {
        this.decls = Objects.requireNonNull(decls);
        this.funcDefs = Objects.requireNonNull(funcDefs);
        this.mainFuncDef = Objects.requireNonNull(mainFuncDef);
        Logger.logGood("<CompUnit>\n");
    }
}
