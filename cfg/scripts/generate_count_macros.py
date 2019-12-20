def generate_macros(_number):
    macros = []

# Generate SXE_GET_COUNT
    macros.append(f"//!\def SXE_GET_COUNT( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10,..., {_number}, COUNT, ... )")
    macros.append("//!\\brief Helper for counting the number of parameters of a macro.")
    macros.append("#define SXE_GET_COUNT( \\")
    macro = ""
    for i in range( _number ):
        idx = i + 1
        if i % 10 == 0 and macro!= "":
            macros.append(macro + "\\")
            macro = ""
        macro += f" _{idx},"
    if _number % 10 == 0:
        macros.append(macro + "\\")
        macros.append(" COUNT, ...) COUNT")
    else:
        macros.append(macro + " COUNT, ...) COUNT")

    macros.append("")
    macros.append("")

# Generate SXE_VA_SIZE
    macro = ""
    macros.append("//!\def SXE_VA_SIZE( ... )")
    macros.append("//!\\brief Count the number of parameters of a macro.")
    macro = "#define SXE_VA_SIZE( ... ) SXE_EXPAND( SXE_GET_COUNT( __VA_ARGS__,"
    for i in range( _number + 2 ):
        idx = _number - i
        if idx % 10 == 0 and macro!= "":
            macros.append(macro + "\\")
            macro = ""
        macro += f" {idx}"
        if( i < _number + 1):
            macro += ","

    if (_number + 3) % 10 == 0:
        macros.append(macro)
        macros.append(" ) )")
    else:
        macros.append(macro + " ) )")

    macros.append("")
    macros.append("")

# Generate SXE_GET_COUNT_IDX
    macros.append(f"//!\def SXE_GET_COUNT_IDX( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10,..., _{_number}, COUNT, ... )")
    macros.append("//!\\brief Helper for counting the number of parameters of a macro, as index - starts from zero.")
    macros.append("#define SXE_GET_COUNT_IDX( \\")
    macro = ""
    for i in range( _number + 1 ):
        idx = i
        if i % 10 == 0 and macro!= "":
            macros.append(macro + "\\")
            macro = ""
        macro += f" _{idx},"
    if _number % 10 == 0:
        macros.append(macro + "\\")
        macros.append(" COUNT, ...) COUNT")
    else:
        macros.append(macro + " COUNT, ...) COUNT")

    macros.append("")
    macros.append("")


# Generate SXE_VA_SIZE_IDX
    macro = ""
    macros.append("//!\def SXE_VA_SIZE_IDX( ... )")
    macros.append("//!\\brief Count the number of parameters of a macro, as index - starts from zero.")
    macro = "#define SXE_VA_SIZE_IDX( ... ) SXE_EXPAND( SXE_GET_COUNT_IDX( __VA_ARGS__,"
    for i in range( _number + 2 ):
        idx = _number - i
        if idx % 10 == 0 and macro!= "":
            macros.append(macro + "\\")
            macro = ""
        macro += f" {idx}"
        if( i < _number + 1):
            macro += ","

    if (_number + 3) % 10 == 0:
        macros.append(macro)
        macros.append(" ) )")
    else:
        macros.append(macro + " ) )")

    macros.append("")
    macros.append("")

    return macros


NUMBER_OF_MACROS = 500
generated_macros = generate_macros(NUMBER_OF_MACROS)
with open("count_macros.txt", "w") as f:
    f.write("\n".join(generated_macros))
    