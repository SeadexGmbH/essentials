#!/usr/bin/env python3

import subprocess

def main():
    # Get the available options for c++
    cmd = "sudo update-alternatives --list c++"
    output = subprocess.check_output(cmd.split()).decode().strip()
    print(output)
    options = output.split('\n')

    # Find the index of the option for clang++
    clang_index = -1
    for i, option in enumerate(options):
        if "clang++" in option:
            clang_index = i
            break

    if clang_index == -1:
        print("Error: clang++ not found in update-alternatives")
        return

    # Set clang++ as the default option
    cmd = f"echo {clang_index + 1} | sudo update-alternatives --config c++"
    subprocess.run(cmd, shell=True)

if __name__ == '__main__':
    main()
