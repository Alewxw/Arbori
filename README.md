Arbori binari de cautare
	Sunt structuri de date abstracte utilizate la stocarea și organizarea elementelor, astfel încât operațiile de căutare, inserare și ștergere să poată fi realizate eficient. Acesta se numește binar deoarece fiecare nod poate avea cel mult doi copii și respectă o proprietate predefinită. Proprietatea fiecărui nod este că toate valorile din subarborele stâng sunt mai mici decât valoarea nodului curent, iar toate valorile din subarborele drept sunt mai mari decât valoarea nodului curent.

Toate operațiile (inserare, căutare, ștergere) au o complexitate medie O(log n), însă, în cazul în care arborele devine dezechilibrat (poate fi văzut ca o listă), complexitatea ajunge la cazul defavorabil O(n).
