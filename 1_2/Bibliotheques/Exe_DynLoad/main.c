#include <stdio.h>
#include <Windows.h>

typedef void(*function)(char*);

static function func;

int main(void) {
	void* ref = LoadLibrary(TEXT("C:/Users/Michel K/source/repos/Bibliotheques/Debug/Bibliotheques.dll")); // Conversion n�cessaire
	if (!ref) // Erreur lors du chargement de la biblioth�que ?
	{
		printf("Impossible de charger la biblioth�que.");
	}
	else { // On r�cup�re l'adresse de la fonction 
		func = (function) GetProcAddress(ref, "PrintStop");
		func("Test dynamic load");
	}
	return 0;
}