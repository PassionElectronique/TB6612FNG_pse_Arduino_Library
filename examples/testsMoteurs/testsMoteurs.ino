// ===================================================================================================
//   ______               _                  _///_ _           _                   _
//  /   _  \             (_)                |  ___| |         | |                 (_)
//  |  [_|  |__  ___  ___ _  ___  _ __      | |__ | | ___  ___| |_ _ __ ___  _ __  _  ___  _   _  ___
//  |   ___/ _ \| __|| __| |/ _ \| '_ \_____|  __|| |/ _ \/  _|  _| '__/   \| '_ \| |/   \| | | |/ _ \
//  |  |  | ( ) |__ ||__ | | ( ) | | | |____| |__ | |  __/| (_| |_| | | (_) | | | | | (_) | |_| |  __/
//  \__|   \__,_|___||___|_|\___/|_| [_|    \____/|_|\___|\____\__\_|  \___/|_| |_|_|\__  |\__,_|\___|
//                                                                                      | |
//                                                                                      \_|
// ===================================================================================================
//
//  Nom Projet  :       TB6612FNG_pse_Arduino_Library
//  Desc Projet :       Librairie Arduino pour TB6612FNG
//
//  Fichier     :       testsMoteurs.ino
//  Créé le     :       31.03.2026
//  Auteur      :       Jérôme TOMSKI
//  Site        :       https://passionelectronique.fr/
//  GitHub      :       https://github.com/PassionElectronique/TB6612FNG_pse_Arduino_Library
//  Licence     :       https://creativecommons.org/licenses/by-nc-nd/4.0/deed.fr (BY-NC-ND 4.0 CC)
//
// ===================================================================================================
//
//  /!\ IMPORTANT /!\
//
//    Cette librairie "TB6612FNG_pse" n'est pas téléchargeable depuis le "gestionnaire de bibliothèques" d'Arduino IDE.
//    Il faudra donc l'installer manuellement ! Voici comment procéder :
//        - Allez sur la page GitHub de cette librairie : https://github.com/PassionElectronique/TB6612FNG_pse_Arduino_Library
//        - Sur la page GitHub, cliquez sur le bouton "Code" puis "Download ZIP", pour télécharger le fichier zip
//        - Une fois fait, allez sur Arduino IDE
//        - Sur Arduino IDE, cliquez dans le menu Sketch (croquis) → Include library (inclure une bibliothèque) → Add .ZIP library (ajouter la bibliothèque .ZIP)
//        - Sélectionnez votre fichier ZIP précédemment téléchargé
//        - Et effacez le fichier précédemment téléchargé (car il ne sert plus à rien, du fait qu'Arduino IDE en a fait une copie, dans son répertoire de librairies !)
//
// ===================================================================================================
#include <TB6612FNG_pse.h>

// ---------------------------------------------------------------------------------
// Affectation des broches (Arduino Uno ou ESP32-S3), pour le pilotage du TB6612 FNG
// ---------------------------------------------------------------------------------
#define pin_PWMA 5   // La broche PWMA du module TB6612FNG sera reliée à la broche 5
#define pin_AIN2 6   // La broche AIN2 du module TB6612FNG sera reliée à la broche 6
#define pin_AIN1 7   // La broche AIN1 du module TB6612FNG sera reliée à la broche 7
#define pin_STBY 8   // La broche STBY du module TB6612FNG sera reliée à la broche 8
#define pin_BIN1 9   // La broche BIN1 du module TB6612FNG sera reliée à la broche 9
#define pin_BIN2 10  // La broche BIN2 du module TB6612FNG sera reliée à la broche 10
#define pin_PWMB 11  // La broche PWMB du module TB6612FNG sera reliée à la broche 11

// -----------------------
// Instanciation librairie
// -----------------------
TB6612FNG_pse monDriverMoteur = TB6612FNG_pse(pin_AIN1, pin_AIN2, pin_BIN1, pin_BIN2, pin_PWMA, pin_PWMB, pin_STBY);
auto& moteurDeGauche = monDriverMoteur.moteurA;  // Pour créer un alias nommé "moteurDeGauche", rattaché à cette instance, donc plus simple à utiliser ensuite
auto& moteurDeDroite = monDriverMoteur.moteurB;  // Idem, pour le "moteurDeDroite"

// ============================================
// Fonction setup (lancée 1 fois, au démarrage)
// ============================================
void setup() {
  monDriverMoteur.sortirDuSommeil();  // Sortie du mode STBY du TB6612FNG, par défaut
  moteurDeGauche.inverserCablage();   // Si besoin, dans le cas où le moteur ne tournerait initialement pas dans le bon sens
  moteurDeDroite.inverserCablage();   // Si besoin, pour la même raison !
}

// ==================================
// Fonction loop (boucle perpétuelle)
// ==================================
void loop() {
  // Marche avant, à 100% de la vitesse max (soit vitesse = 255, comme le max est à 255)
  moteurDeGauche.embrayerMarcheAvant();
  moteurDeDroite.embrayerMarcheAvant();
  moteurDeGauche.reglerVitesseDe0a255(255);
  moteurDeDroite.reglerVitesseDe0a255(255);
  delay(2000);

  // Arrêt (en "roue libre")
  moteurDeGauche.debrayer();
  moteurDeDroite.debrayer();
  delay(1000);

  // Marche arrière, à 50% de la vitesse max (soit vitesse = 127, comme le max est à 255)
  moteurDeGauche.embrayerMarcheArriere();
  moteurDeDroite.embrayerMarcheArriere();
  moteurDeGauche.reglerVitesseDe0a255(127);
  moteurDeDroite.reglerVitesseDe0a255(127);
  delay(2000);

  // Arrêt (en "freinage actif")
  moteurDeGauche.freiner();
  moteurDeDroite.freiner();
  delay(1000);
}
