all: s21_grep
	
clean:
			rm -rf s21_grep *.o
s21_grep.o: s21_grep.c
			gcc -c -o s21_grep.o s21_grep.c
args.o: args.c
			gcc -c -o args.o args.c
s21_grep: s21_grep.o args.o
			gcc -o s21_grep s21_grep.o args.o