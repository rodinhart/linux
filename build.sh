clang --target=wasm32 -c -o $1.o $1
wasm-ld-8 --no-entry --export add -o $1.wasm $1.o
