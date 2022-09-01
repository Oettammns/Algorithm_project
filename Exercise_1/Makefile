$(CC) = gcc

order: 
	$(info ***** COMMANDS *****)
	$(info Build with 'make order' command, then execute with './order [filename.csv] [k value]'. To remove it use 'rm order')
	$(info For test purpose only the command is : make test, then for launching use ./test)
	$(info ***** ABOUT US *****)
	$(info Authors : )
	$(info Giuseppe Pio Lobascio)
	$(info Matteo Mansi)
	$(CC) functions.c main.c -o order
	$(info **** SUCCESSFULLY COMPILED ****)

test: 
	$(CC) test_suite.c test.c functions.c -o test
	

