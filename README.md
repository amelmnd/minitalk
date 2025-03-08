<h1 align="center">Minitalk</h1>
<p align="center">
	<img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" />
</p>
<div align="center">
	<img src="./minitalk_demo.gif" width="450" height="150" />
</div>

- [Description](#description)
- [Structure du projet](#structure-du-projet)
- [Utilisation de so_long](#utilisation-de-so_long)
	- [Pré-requis](#pre-requis)
	- [Compilation du projet](#compilation-du-projet)
	- [Exécution du projet](#exécution-du-projet)

## Description

Le but de ce projet d'introduction a UNIX, est de développer un programme d'échange de données utilisant des signaux UNIX.

Il s'agira d'un communication server/client.
Le client envoie une chaîne de caractère passée en paramètre et une fois la chaîne entièrement reçue, le serveur l’affiche.

Les contraintes sont :
- le serveur peut recevoir des messages de plusieurs clients en même temps.
- la communication entre les programmes doit se faire uniquement à l’aide des signaux UNIX SIGUSR1 et SIGUSR2.

Le bonus réalisé ici est la confirmation de réception de chaque message par le serveur.

## Structure du projet
- include : fonctions nécessaires au projet
- fichier server et server bonus
- fichier client

## Utilisation de minitalk

### Pre-requis

* **compilateur `gcc`**

### Compilation du projet
```shell
cd projet
make
```
### Exécution du projet
1. Ouvrir au moins 2 terminaux différents sur un même ordinateur
2. Lancer le serveur :
    ```shell
    ./server
    ```
3. Envoyer des messages
    ```shell
    ./client <PID_server> <meessage>
    ```

À noter pour cette étape :
- le PID est fournis a l'exécution du serveur.
- si le message est plus que 1 mot, il est nécessaire de mettre des quotes (simple ou double au choix)

## Ressources utiles et Testeur
Aucun