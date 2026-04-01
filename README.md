# Librairie TB6612FNG pse, pour Arduino IDE

![Double driver moteur TB6612FNG](https://passionelectronique.fr/wp-content/uploads/module_TB6612FNG_driver_moteur_h100.png)

Le TB6612 FNG est une puce électronique :

- permettant de piloter jusqu'à 2 moteurs DC
- acceptant environ 1A en continu par moteur (3A en pic)
- contrôlant les modes de fonctionnement individuels des moteurs via signaux d'entrées tout-ou-rien (IN1 et IN2). Cela permet 4 modes de fonctionnement possibles :
  - marche avant
  - marche arrière
  - rotation libre
  - freinage actif
- pilotable selon rapport cyclique fourni (définissant la vitesse du moteur, en fait) via lignes d'entrées PWMA et PWMB (fréquence PWM = 100 kHz, typiquement, et rapport cyclique à faire varier entre 0 et 100%)
- activable/désactivable via la ligne STBY (état haut = puce active ; état bas = puce en sommeil)

## Contenu dans ce dépôt

- **/examples** - Des exemples de sketch arduino (.ino)
- **/src** - Les fichiers sources de cette librairie (.h et .cpp)
- **keywords.txt** - La liste des mots clefs de cette librairie, que l'IDE Arduino doit syntaxiquement colorer
- **library.properties** - Les propriétés générales de cette librairie, à destination du gestionnaire de bibliothèques Arduino IDE

## Utilisation

> Tuto complet ici : [_Double driver moteur TB6612FNG_](https://passionelectronique.fr/tutoriel-tb6612fng)

(sera détaillé ensuite, dès que j'aurais le temps... !)

## Licence

Licence BY-NC-ND 4.0 CC<br />
Lien : https://creativecommons.org/licenses/by-nc-nd/4.0/deed.fr

## À propos

@2026<br />
Créé par Jérôme TOMSKI<br />
Site web : [passionelectronique.fr](https://passionelectronique.fr/)
