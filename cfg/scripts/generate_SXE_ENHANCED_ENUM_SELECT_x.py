def generate_enhanced_enum_select(_number):
    result = []
    for i in range(1, _number + 1):
        values = ', '.join([f'_val_{j}' for j in range(1, i + 1)])
        index = ', '.join([str(j-1) for j in range(1, i + 1)])
        macro = f'#define SXE_ENHANCED_ENUM_SELECT_{i + 1}( _name, {values} ) SXE_ENHANCED_ENUM_IMPL( _name, ( {index} ), ( {values} ) )'
        result.append(macro)
    return result


NUMBER_OF_MACROS = 50
macros = generate_enhanced_enum_select(NUMBER_OF_MACROS)
with open('enhanced_enum_macros.txt', 'w') as f:
    f.write('\n'.join(macros))
