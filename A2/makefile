bin/myContacts: contactsA2.o createContactsA2.o readContactsA2.o searchContactsA2.o
    gcc -Wall -std=c99 contactsA2.o createContactsA2.o readContactsA2.o searchContactsA2.o -o bin/myContacts

contactsA2.o: src/contactsA2.c include/givenA2.h
    gcc -Wall -std=c99 -c src/contactsA2.c -Iinclude -o contactsA2.o

createContactsA2.o: src/createContactsA2.c include/givenA2.h
    gcc -Wall -std=c99 -c src/createContactsA2.c -Iinclude -o createContactsA2.o

readContactsA2.o: src/readContactsA2.c include/givenA2.h
    gcc -Wall -std=c99 -c src/readContactsA2.c -Iinclude -o readContactsA2.o

searchContactsA2.o: src/searchContactsA2.c include/givenA2.h
    gcc -Wall -std=c99 -c src/searchContactsA2.c -Iinclude -o searchContactsA2.o
    
clean:
	rm -f bin/myContacts contactsA2.o createContactsA2.o readContactsA2.o searchContactsA2.o
