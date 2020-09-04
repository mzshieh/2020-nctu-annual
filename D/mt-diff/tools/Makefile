
input: gen.cpp
	./testcase.pl

solution: fast.cpp slow.cpp 
	g++ -O3 -o fast fast.cpp -std=c++1z
	perl -e 'for($$i=1;$$i<=10;++$$i){print `time ./fast < $$i.in > $$i.sol`}'

pdf:
	pdflatex diff
	pdflatex diff

