#!bin/sh

cd libft
make
cd ../
gcc *.c libft/libft.a
./a.out
