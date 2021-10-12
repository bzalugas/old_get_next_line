
echo "BUFFER_SIZE=1"
clang -Werror -Wextra -Wall -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main_gnl.c
cat textes/test.txt > intended
./a.out textes/test.txt > out
diff intended out > diff
fichier="diff"
if [ -s $fichier ]; then
	echo "Not OK."
else
	echo "OK."
fi
