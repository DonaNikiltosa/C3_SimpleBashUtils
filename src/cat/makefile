all: s21_cat
	
clean:
			rm -rf s21_cat *.o
s21_cat.o: s21_cat.c
			gcc -c -o s21_cat.o s21_cat.c
flags.o: flags.c
			gcc -c -o flags.o flags.c
s21_cat: s21_cat.o flags.o
			gcc -o s21_cat s21_cat.o flags.o