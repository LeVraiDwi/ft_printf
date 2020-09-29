make re
echo "						============						"
gcc $1 main.c printf.a libft/libft.a
echo "						============						"
./a.out | cat -e
echo "						============						"
make clean
