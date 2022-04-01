all:
	echo
	gcc -Wall -Wextra -Werror -ansi -pedantic -o proj1.out proj1.c
	./proj1.out

clean:
	rm -rf proj1.out

f:
	gcc -g -fsanitize=address -Wall -Wextra -Werror -ansi -pedantic -o proj1.out proj1.c
	./proj1.out < tests-public/test03.in

v:
	gcc -g -Wall -Wextra -Werror -ansi -pedantic -o proj1.out proj1.c
	valgrind ./proj1.out < tests-public/test03.in

l:
	lizard proj1.c

up:
	code proj1.c
	make t

t:
	clear
	gcc -Wall -Wextra -Werror -ansi -pedantic -o proj1.out proj1.c
	time ./proj1.out < tests-public/test01.in > test01.myout
	time ./proj1.out < tests-public/test02.in > test02.myout
	time ./proj1.out < tests-public/test03.in > test03.myout
	time ./proj1.out < tests-public/test04.in > test04.myout
	time ./proj1.out < tests-public/test05.in > test05.myout
	time ./proj1.out < tests-public/test06.in > test06.myout
	time ./proj1.out < tests-public/test07.in > test07.myout
	time ./proj1.out < tests-public/test08.in > test08.myout
	time ./proj1.out < tests-public/test09.in > test09.myout
	time ./proj1.out < tests-public/test10.in > test10.myout
	time ./proj1.out < tests-public/test11.in > test11.myout
	time ./proj1.out < tests-public/test12.in > test12.myout
	time ./proj1.out < tests-public/test13.in > test13.myout
	time ./proj1.out < tests-public/test14.in > test14.myout
	time ./proj1.out < tests-public/test15.in > test15.myout
	diff tests-public/test01.out test01.myout
	diff tests-public/test02.out test02.myout
	diff tests-public/test03.out test03.myout
	diff tests-public/test04.out test04.myout
	diff tests-public/test05.out test05.myout
	diff tests-public/test06.out test06.myout
	diff tests-public/test07.out test07.myout
	diff tests-public/test08.out test08.myout
	diff tests-public/test09.out test09.myout
	diff tests-public/test10.out test10.myout
	diff tests-public/test11.out test11.myout
	diff tests-public/test12.out test12.myout
	diff tests-public/test13.out test13.myout
	diff tests-public/test14.out test14.myout
	diff tests-public/test15.out test15.myout
	rm -rf proj1.out proj1.zip
	zip proj1.zip proj1.c