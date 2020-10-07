make
echo "						============						"
gcc -I "./include" main.c libftprintf.a 
echo "						============						"
./a.out
echo "						============						"
make clean
