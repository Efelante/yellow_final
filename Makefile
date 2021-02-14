all:
	g++-8 -std=c++17 *.cpp 

archive:
	tar -cf solution.tar.gz  date.* database.* node.* token.* condition_parser.* main.cpp condition_parser_test.cpp
	gzip solution.tar
