driver: Order.o MenuItem.o Kitchen.o 
	g++ main.cpp Order.o MenuItem.o Kitchen.o -o driver
order: Order.cpp
	g++ -c Order.cpp -o Order.o
item: MenuItem.cpp
	g++ -c MenuItem.cpp -o MenuItem.o
kitchen: Kitchen.cpp
	g++ -c Kitchen.cpp -o Kitchen.o


clean:
	rm *.o driver Printer.txt
