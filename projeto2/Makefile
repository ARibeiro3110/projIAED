all:
	echo
	gcc -g -Wall -Wextra -Werror -ansi -pedantic -o proj2 data_hora.c aeroportos.c voos.c reservas.c proj2.c hashtable.c

	
f:
	gcc -g -fsanitize=address -Wall -Wextra -Werror -ansi -pedantic -o proj2 data_hora.c aeroportos.c voos.c reservas.c proj2.c hashtable.c
	./proj2 < Testes/community_tests/c_test08.in

i:
	make
	clear
	./proj2 < Testes/testes-fabio/test03.in

v:
	clear
	make
	make vv

l:
	rm -rf proj2.zip 
	lizard data_hora.c aeroportos.c voos.c reservas.c proj2.c hashtable.c data_hora.h aeroportos.h voos.h reservas.h proj2.h hashtable.h


z:
	rm -rf proj2.zip 
	zip proj2.zip data_hora.c aeroportos.c voos.c reservas.c proj2.c hashtable.c data_hora.h aeroportos.h voos.h reservas.h proj2.h hashtable.h


t:
	clear
	make 
	make tt
	rm -rf proj2.zip 
	make z

c:
	rm -rf T01.myout
	rm -rf T02.myout
	rm -rf T03.myout
	rm -rf T04.myout
	rm -rf T05.myout
	rm -rf T06.myout
	rm -rf T07.myout
	rm -rf T08.myout
	rm -rf T09.myout
	rm -rf T10.myout
	rm -rf T11.myout
	rm -rf T12.myout
	rm -rf T13.myout
	rm -rf T14.myout
	rm -rf T15.myout
	rm -rf T16.myout
	rm -rf T17.myout
	rm -rf T18.myout
	rm -rf T19.myout
	rm -rf T20.myout
	rm -rf T21.myout
	rm -rf T22.myout
	rm -rf T23.myout
	rm -rf T24.myout
	rm -rf T25.myout
	rm -rf T26.myout
	rm -rf T27.myout
	rm -rf T28.myout
	rm -rf T29.myout
	rm -rf T30.myout
	rm -rf T31.myout
	rm -rf T32.myout
	rm -rf T33.myout
	rm -rf T34.myout
	rm -rf T35.myout
	rm -rf T36.myout
	rm -rf T37.myout
	rm -rf T38.myout
	rm -rf T39.myout
	rm -rf T40.myout
	rm -rf T41.myout
	rm -rf T42.myout
	rm -rf T43.myout
	rm -rf T44.myout
	rm -rf T45.myout
	rm -rf T46.myout
	rm -rf T47.myout
	rm -rf T48.myout
	rm -rf test01.myout
	rm -rf test02.myout
	rm -rf test03.myout
	rm -rf test04.myout
	rm -rf test05.myout
	rm -rf test06.myout
	rm -rf test07.myout
	rm -rf test08.myout
	rm -rf test09.myout
	rm -rf test10.myout
	rm -rf test11.myout
	rm -rf test12.myout
	rm -rf test13.myout
	rm -rf test14.myout
	rm -rf test15.myout
	rm -rf c_test01.myout
	rm -rf c_test02.myout
	rm -rf c_test03.myout
	rm -rf c_test04.myout
	rm -rf c_test05.myout
	rm -rf c_test06.myout
	rm -rf c_test07.myout
	rm -rf c_test08.myout
	rm -rf c_test09.myout
	rm -rf c_test10.myout
	rm -rf bulk.myout
	rm -rf super_bulk.myout
	rm -rf proj2
	clear

tt:
	time ./proj2 < Testes/tests-public-p2/test01.in > test01.myout
	time ./proj2 < Testes/tests-public-p2/test02.in > test02.myout
	time ./proj2 < Testes/tests-public-p2/test03.in > test03.myout
	time ./proj2 < Testes/tests-public-p2/test04.in > test04.myout
	time ./proj2 < Testes/tests-public-p2/test05.in > test05.myout
	time ./proj2 < Testes/tests-public-p2/test06.in > test06.myout
	time ./proj2 < Testes/tests-public-p2/test07.in > test07.myout
	time ./proj2 < Testes/tests-public-p2/test08.in > test08.myout
	time ./proj2 < Testes/tests-public-p2/test09.in > test09.myout
	time ./proj2 < Testes/tests-public-p2/test10.in > test10.myout
	time ./proj2 < Testes/tests-public-p2/test11.in > test11.myout
	time ./proj2 < Testes/tests-public-p2/test12.in > test12.myout
	time ./proj2 < Testes/tests-public-p2/test13.in > test13.myout
	time ./proj2 < Testes/tests-public-p2/test14.in > test14.myout
	time ./proj2 < Testes/tests-public-p2/test15.in > test15.myout
	diff Testes/tests-public-p2/test01.out test01.myout
	diff Testes/tests-public-p2/test02.out test02.myout
	diff Testes/tests-public-p2/test03.out test03.myout
	diff Testes/tests-public-p2/test04.out test04.myout
	diff Testes/tests-public-p2/test05.out test05.myout
	diff Testes/tests-public-p2/test06.out test06.myout
	diff Testes/tests-public-p2/test07.out test07.myout
	diff Testes/tests-public-p2/test08.out test08.myout
	diff Testes/tests-public-p2/test09.out test09.myout
	diff Testes/tests-public-p2/test10.out test10.myout
	diff Testes/tests-public-p2/test11.out test11.myout
	diff Testes/tests-public-p2/test12.out test12.myout
	diff Testes/tests-public-p2/test13.out test13.myout
	diff Testes/tests-public-p2/test14.out test14.myout
	diff Testes/tests-public-p2/test15.out test15.myout

	time ./proj2 < Testes/testes-fabio/test01.in > test01.myout
	time ./proj2 < Testes/testes-fabio/test02.in > test02.myout
	time ./proj2 < Testes/testes-fabio/test03.in > test03.myout
	time ./proj2 < Testes/testes-fabio/test04.in > test04.myout
	time ./proj2 < Testes/testes-fabio/test05.in > test05.myout
	time ./proj2 < Testes/testes-fabio/test06.in > test06.myout
	time ./proj2 < Testes/testes-fabio/test07.in > test07.myout
	time ./proj2 < Testes/testes-fabio/test08.in > test08.myout
	time ./proj2 < Testes/testes-fabio/test09.in > test09.myout
	time ./proj2 < Testes/testes-fabio/test10.in > test10.myout
	diff Testes/testes-fabio/test01.out test01.myout
	diff Testes/testes-fabio/test02.out test02.myout
	diff Testes/testes-fabio/test03.out test03.myout
	diff Testes/testes-fabio/test04.out test04.myout
	diff Testes/testes-fabio/test05.out test05.myout
	diff Testes/testes-fabio/test06.out test06.myout
	diff Testes/testes-fabio/test07.out test07.myout
	diff Testes/testes-fabio/test08.out test08.myout
	diff Testes/testes-fabio/test09.out test09.myout
	diff Testes/testes-fabio/test10.out test10.myout

	time ./proj2 < Testes/community_tests/c_test01.in > test01.myout
	time ./proj2 < Testes/community_tests/c_test02.in > test02.myout
	time ./proj2 < Testes/community_tests/c_test03.in > test03.myout
	time ./proj2 < Testes/community_tests/c_test04.in > test04.myout
	time ./proj2 < Testes/community_tests/c_test05.in > test05.myout
	time ./proj2 < Testes/community_tests/c_test06.in > test06.myout
	time ./proj2 < Testes/community_tests/c_test07.in > test07.myout
	time ./proj2 < Testes/community_tests/c_test08.in > test08.myout
	time ./proj2 < Testes/community_tests/c_test09.in > test09.myout
	time ./proj2 < Testes/community_tests/c_test10.in > test10.myout
	diff Testes/community_tests/c_test01.out test01.myout
	diff Testes/community_tests/c_test02.out test02.myout
	diff Testes/community_tests/c_test03.out test03.myout
	diff Testes/community_tests/c_test04.out test04.myout
	diff Testes/community_tests/c_test05.out test05.myout
	diff Testes/community_tests/c_test06.out test06.myout
	diff Testes/community_tests/c_test07.out test07.myout
	diff Testes/community_tests/c_test08.out test08.myout
	diff Testes/community_tests/c_test09.out test09.myout
	diff Testes/community_tests/c_test10.out test10.myout

	time ./proj2 < Testes/extensive_tests/bulk.in > bulk.myout
	diff Testes/extensive_tests/bulk.out bulk.myout
	time ./proj2 < Testes/extensive_tests/super_bulk.in > super_bulk.myout
	diff Testes/extensive_tests/super_bulk.out super_bulk.myout

	time ./proj2 < Testes/tests-mooshak-proj1/T01/input > T01.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T02/input > T02.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T03/input > T03.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T04/input > T04.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T05/input > T05.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T06/input > T06.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T07/input > T07.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T08/input > T08.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T09/input > T09.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T10/input > T10.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T11/input > T11.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T12/input > T12.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T13/input > T13.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T14/input > T14.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T15/input > T15.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T16/input > T16.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T17/input > T17.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T18/input > T18.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T19/input > T19.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T20/input > T20.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T21/input > T21.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T22/input > T22.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T23/input > T23.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T24/input > T24.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T25/input > T25.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T26/input > T26.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T27/input > T27.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T28/input > T28.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T29/input > T29.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T30/input > T30.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T31/input > T31.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T32/input > T32.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T33/input > T33.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T34/input > T34.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T35/input > T35.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T36/input > T36.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T37/input > T37.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T38/input > T38.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T39/input > T39.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T40/input > T40.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T41/input > T41.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T42/input > T42.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T43/input > T43.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T44/input > T44.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T45/input > T45.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T46/input > T46.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T47/input > T47.myout
	time ./proj2 < Testes/tests-mooshak-proj1/T48/input > T48.myout
	diff Testes/tests-mooshak-proj1/T01/output T01.myout
	diff Testes/tests-mooshak-proj1/T02/output T02.myout
	diff Testes/tests-mooshak-proj1/T03/output T03.myout
	diff Testes/tests-mooshak-proj1/T04/output T04.myout
	diff Testes/tests-mooshak-proj1/T05/output T05.myout
	diff Testes/tests-mooshak-proj1/T06/output T06.myout
	diff Testes/tests-mooshak-proj1/T07/output T07.myout
	diff Testes/tests-mooshak-proj1/T08/output T08.myout
	diff Testes/tests-mooshak-proj1/T09/output T09.myout
	diff Testes/tests-mooshak-proj1/T10/output T10.myout
	diff Testes/tests-mooshak-proj1/T11/output T11.myout
	diff Testes/tests-mooshak-proj1/T12/output T12.myout
	diff Testes/tests-mooshak-proj1/T13/output T13.myout
	diff Testes/tests-mooshak-proj1/T14/output T14.myout
	diff Testes/tests-mooshak-proj1/T15/output T15.myout
	diff Testes/tests-mooshak-proj1/T16/output T16.myout
	diff Testes/tests-mooshak-proj1/T17/output T17.myout
	diff Testes/tests-mooshak-proj1/T18/output T18.myout
	diff Testes/tests-mooshak-proj1/T19/output T19.myout
	diff Testes/tests-mooshak-proj1/T20/output T20.myout
	diff Testes/tests-mooshak-proj1/T21/output T21.myout
	diff Testes/tests-mooshak-proj1/T22/output T22.myout
	diff Testes/tests-mooshak-proj1/T23/output T23.myout
	diff Testes/tests-mooshak-proj1/T24/output T24.myout
	diff Testes/tests-mooshak-proj1/T25/output T25.myout
	diff Testes/tests-mooshak-proj1/T26/output T26.myout
	diff Testes/tests-mooshak-proj1/T27/output T27.myout
	diff Testes/tests-mooshak-proj1/T28/output T28.myout
	diff Testes/tests-mooshak-proj1/T29/output T29.myout
	diff Testes/tests-mooshak-proj1/T30/output T30.myout
	diff Testes/tests-mooshak-proj1/T31/output T31.myout
	diff Testes/tests-mooshak-proj1/T32/output T32.myout
	diff Testes/tests-mooshak-proj1/T33/output T33.myout
	diff Testes/tests-mooshak-proj1/T34/output T34.myout
	diff Testes/tests-mooshak-proj1/T35/output T35.myout
	diff Testes/tests-mooshak-proj1/T36/output T36.myout
	diff Testes/tests-mooshak-proj1/T37/output T37.myout
	diff Testes/tests-mooshak-proj1/T38/output T38.myout
	diff Testes/tests-mooshak-proj1/T39/output T39.myout
	diff Testes/tests-mooshak-proj1/T40/output T40.myout
	diff Testes/tests-mooshak-proj1/T41/output T41.myout
	diff Testes/tests-mooshak-proj1/T42/output T42.myout
	diff Testes/tests-mooshak-proj1/T43/output T43.myout
	diff Testes/tests-mooshak-proj1/T44/output T44.myout
	diff Testes/tests-mooshak-proj1/T45/output T45.myout
	diff Testes/tests-mooshak-proj1/T46/output T46.myout
	diff Testes/tests-mooshak-proj1/T47/output T47.myout
	diff Testes/tests-mooshak-proj1/T48/output T48.myout

	time ./proj2 < Testes/tests-public-p1/test01.in > test01.myout
	time ./proj2 < Testes/tests-public-p1/test02.in > test02.myout
	time ./proj2 < Testes/tests-public-p1/test03.in > test03.myout
	time ./proj2 < Testes/tests-public-p1/test04.in > test04.myout
	time ./proj2 < Testes/tests-public-p1/test05.in > test05.myout
	time ./proj2 < Testes/tests-public-p1/test06.in > test06.myout
	time ./proj2 < Testes/tests-public-p1/test07.in > test07.myout
	time ./proj2 < Testes/tests-public-p1/test08.in > test08.myout
	time ./proj2 < Testes/tests-public-p1/test09.in > test09.myout
	time ./proj2 < Testes/tests-public-p1/test10.in > test10.myout
	time ./proj2 < Testes/tests-public-p1/test11.in > test11.myout
	time ./proj2 < Testes/tests-public-p1/test12.in > test12.myout
	time ./proj2 < Testes/tests-public-p1/test13.in > test13.myout
	time ./proj2 < Testes/tests-public-p1/test14.in > test14.myout
	time ./proj2 < Testes/tests-public-p1/test15.in > test15.myout
	diff Testes/tests-public-p1/test01.out test01.myout
	diff Testes/tests-public-p1/test02.out test02.myout
	diff Testes/tests-public-p1/test03.out test03.myout
	diff Testes/tests-public-p1/test04.out test04.myout
	diff Testes/tests-public-p1/test05.out test05.myout
	diff Testes/tests-public-p1/test06.out test06.myout
	diff Testes/tests-public-p1/test07.out test07.myout
	diff Testes/tests-public-p1/test08.out test08.myout
	diff Testes/tests-public-p1/test09.out test09.myout
	diff Testes/tests-public-p1/test10.out test10.myout
	diff Testes/tests-public-p1/test11.out test11.myout
	diff Testes/tests-public-p1/test12.out test12.myout
	diff Testes/tests-public-p1/test13.out test13.myout
	diff Testes/tests-public-p1/test14.out test14.myout
	diff Testes/tests-public-p1/test15.out test15.myout

vv:
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/community_tests/c_test01.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/community_tests/c_test02.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/community_tests/c_test03.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/community_tests/c_test04.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/community_tests/c_test05.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/community_tests/c_test06.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/community_tests/c_test07.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/community_tests/c_test08.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/community_tests/c_test09.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/community_tests/c_test10.in

	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/tests-public-p2/test01.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/tests-public-p2/test02.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/tests-public-p2/test03.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/tests-public-p2/test04.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/tests-public-p2/test05.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/tests-public-p2/test06.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/tests-public-p2/test07.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/tests-public-p2/test08.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/tests-public-p2/test09.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/tests-public-p2/test10.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/tests-public-p2/test11.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/tests-public-p2/test12.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/tests-public-p2/test13.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/tests-public-p2/test14.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/tests-public-p2/test15.in

	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/testes-fabio/test01.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/testes-fabio/test02.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/testes-fabio/test03.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/testes-fabio/test04.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/testes-fabio/test05.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/testes-fabio/test06.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/testes-fabio/test07.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/testes-fabio/test08.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/testes-fabio/test09.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/testes-fabio/test10.in

	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/extensive_tests/bulk.in
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./proj2 < Testes/extensive_tests/super_bulk.in
