# Target: myContacts
myContacts: contactsA2.o createContacts.o readContacts.o searchContacts.o
	gcc -Wall -std=c99 -o bin/myContacts contactsA2.o createContacts.o readContacts.o searchContacts.o

# Target: contactsA2.o
contactsA2.o: src/contactsA2.c include/givenA2.h
	gcc -Wall -std=c99 -Iinclude -c src/contactsA2.c -o contactsA2.o

# Target: createContacts.o
createContacts.o: src/createContacts.c include/givenA2.h
	gcc -Wall -std=c99 -Iinclude -c src/createContacts.c -o createContacts.o

# Target: readContacts.o
readContacts.o: src/readContacts.c include/givenA2.h
	gcc -Wall -std=c99 -Iinclude -c src/readContacts.c -o readContacts.o

# Target: searchContacts.o
searchContacts.o: src/searchContacts.c include/givenA2.h
	gcc -Wall -std=c99 -Iinclude -c src/searchContacts.c -o searchContacts.o

# Target: clean
clean:
	rm -f bin/myContacts contactsA2.o createContacts.o readContacts.o searchContacts.o
