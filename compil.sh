make re
echo "						============						"
gcc $1 main.c printf.a 
echo "						============						"
./a.out
echo "						============						"
make clean
