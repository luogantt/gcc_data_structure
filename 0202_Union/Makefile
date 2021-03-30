
SOURCE:=SqList.o Union.o  Union-main.o  
EXE :=main

$(EXE):$(SOURCE)
	gcc  $^ -o $@
$@: $^
	gcc -c $^ -o $@


clean:
	rm -rf *.o main
