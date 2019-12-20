NUMBER_OF_MACROS = 50
MACRO_PREFIX = "SXE_ENHANCED_ENUM_NUMERIC_SELECT"
MACRO_ARGS = ["_name"]
for i in range(1, NUMBER_OF_MACROS + 1):
    MACRO_NAME = MACRO_PREFIX + "_" + str(i * 2 + 1)
    MACRO_ARG_COUNT = i * 2 + 1
    MACRO_ARGS.extend(["_val_" + str(j) + ", _numeric_val_" + str(j) for j in range(1, i + 1)])
    MACRO_ARGS_STR = ", ".join(MACRO_ARGS)
    MACRO_BODY = "SXE_ENHANCED_ENUM_IMPL( _name, ( {0} ), ( {1} ) )".format(
        ", ".join("_numeric_val_" + str(j) for j in range(1, i + 1)),
        ", ".join("_val_" + str(j) for j in range(1, i + 1))
    )
    MACRO_STR = "#define {0}( {1} ) {2}\n".format(MACRO_NAME, MACRO_ARGS_STR, MACRO_BODY)
    with open("output.txt", "a") as f:
        f.write(MACRO_STR)
    MACRO_ARGS = ["_name"]