Object=SequenStack.c
fileName=SequenStack
SingList:$(Object)
	@echo "Building..."
	gcc -o $(fileName) $(Object)
	@echo "$(Object) was builded."
.PHONY:run
run:
	./$(fileName)
.PHONY:clean
clean:
	rm -rf *.o $(fileName)
	@echo "Clean finished"
