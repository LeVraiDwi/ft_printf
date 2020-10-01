make
echo "						============						"
gcc $1 -I "./include" main.c libftprintf.a 
echo "						============						"
./a.out
echo "						============						"
make clean
