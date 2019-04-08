all:
	g++ -o program -O2 graph.cpp main.cpp -std=c++11
clean: 
	$(RM) program 
