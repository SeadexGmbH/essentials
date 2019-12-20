NUMBER_OF_PARAMS = 50

with open('get_argument_x.txt', 'w') as f:
    for i in range(0, NUMBER_OF_PARAMS + 1):
        macro_args = ", ".join([f"_val{j}" for j in range(0, i)])
        f.write(f"#define SXE_GET_ARGUMENT_{i}( {macro_args}, N, ... ) N\n")
