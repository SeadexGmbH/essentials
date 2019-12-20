def generate_macros(_number):
    macros = []
    macros.append("#define SXE_MAKE_PAIR_IDX_0( _txt, _values, _names ) SXE_MAKE_PAIR_IDX( _txt, 0, _values, _names )")
    for i in range(_number):
        idx = i + 1
        macro = f"#define SXE_MAKE_PAIR_IDX_{idx}( _txt, _values, _names ) SXE_MAKE_PAIR_IDX( _txt, {idx}, _values, _names ), SXE_MAKE_PAIR_IDX_{i}( _txt, _values, _names )"
        macros.append(macro)
    return macros


NUMBER_OF_MACROS = 50
generated_macros = generate_macros(NUMBER_OF_MACROS)
with open("make_pair_idx.txt", "w") as f:
    f.write("\n".join(generated_macros))
    