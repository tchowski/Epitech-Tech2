#	KICK-OFF
#		PLAZZA

Projet-module a 2 credits

Function virtual classique:
Peut être définie et utiliser dans une classe fille mais DOIT être rédéfinie si elle est utiliser
avec d'autre paramètre dans la classe fille ou le corps de la fonction.

## Objectif:
	Multithreading
	Execution de proc en parallele

## Partie:
	Reception : Interpreteur de cmd
	Cuisine : Produire une pizza
	Rendu : Donner des pizzas sans interruption

## Notion:
	proc pere/fils
	cuisine : thread
	multi-fichier (IPC)

Si ce nombre dépasse il faut fork une nouvelle cuisine.
Si la cuisine n'est pas utilisé au bout de 5 sec close.

Reception:

#	FOLLOW-UP
#		PLAZZA

Création de cuisine seulement si commande 
Mutex! 
Faire les interfaces générique 
Test unitaire sur les interfaces 
Evitez les signaux  
-> voir IPC 
-> Pipe 
-> message queue 
-> mémoire partagée 
-> socket 
-> sigma4 
Pour Linux, thread == fork 