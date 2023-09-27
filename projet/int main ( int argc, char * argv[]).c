int  main ( int argc, char * argv[])
 { 
  /** 
   * VARIABLES 
   * créer une structure pour notre sigaction 
   * créer une variable pour chaque octet
   * puis variable pour l'identifiant du processus 
   * 
   * SIGACTION 
   * Vérifiez si le bon nombre d'arguments est transmis 
   * convertissez l'argument pid du serveur de chaîne en nombre 
          et enregistrez-le dans la variable d'identifiant de processus 
   * videz les numéros de signal pour éviter les erreurs 
   * -> vous pouvez utiliser le sigemptyset. certaines personnes utilisent également la fonction memset 
   * définissez les indicateurs appropriés pour sigaction 
   * définissez également la fonction sig_handler 
   * appelez la fonction sigaction deux fois : avec SIGUSR1 et SIGUSR2 respectivement 
   * vous pouvez gérer l'erreur pour l'appel de fonction, 
   * où -1 signifie une erreur s'est produit 
   * Gérez chaque caractère de la chaîne en effectuant une boucle sur
   * et conversion en binaire en utilisant une fonction avec un prototype de 
   * int char_to_bin(char c, int pid) // note : c -> argv[2][byte_index++] * 
   puis en dehors de la boucle, appelez à nouveau la fonction de conversion mais 
   * cette fois passez '\0' comme caractère. Ceci est important pour préparer 
   * le serveur à un nouveau flux de chaînes 
   */
 }