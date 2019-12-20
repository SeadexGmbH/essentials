def generate_macros(_number):
    macro_template = "#define SXE_ENUM_IDX_{0}( _values, _names ) SXE_ENUM_IDX( {0}, _values, _names ), SXE_ENUM_IDX_{1}( _values, _names)"
    macros = [macro_template.format(i, i-1) for i in range(_number + 1)]
    macros[0] = "#define SXE_ENUM_IDX_0( _values, _names ) SXE_ENUM_IDX( 0, _values, _names )"
    return "\n".join(macros)

NUMBER_OF_MACROS = 50
generated_macros = generate_macros(NUMBER_OF_MACROS)

with open('macro_enum_idx.txt', "w") as f:
    f.write(f"{generated_macros}\n")
