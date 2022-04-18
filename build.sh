clang --target=wasm32 -c -O2 -o $1.o $1
wasm-ld-8 --no-entry --export draw -o $1.wasm $1.o
