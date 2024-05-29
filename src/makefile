driver: Order.o MenuItem.o Kitchen.o 
	g++ main.cpp MenuItem.o Order.o Kitchen.o -o driver
tests: Order.o MenuItem.o Kitchen.o 
	g++ tests.cpp MenuItem.o Order.o Kitchen.o -o tests
order: Order.cpp
	g++ -c Order.cpp -o Order.o
item: MenuItem.cpp
	g++ -c MenuItem.cpp -o MenuItem.o
kitchen: Kitchen.cpp
	g++ -c Kitchen.cpp -o Kitchen.o
clean:
	rm *.o driver Printer.txt
