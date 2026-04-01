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
//  Fichier     :       TB6612FNG_pse.h
//  Créé le     :       29.03.2026
//  Auteur      :       Jérôme TOMSKI
//  Site        :       https://passionelectronique.fr/
//  GitHub      :       https://github.com/PassionElectronique/TB6612FNG_pse_Arduino_Library
//  Licence     :       https://creativecommons.org/licenses/by-nc-nd/4.0/deed.fr (BY-NC-ND 4.0 CC)
//
// ===================================================================================================

#pragma once
#include <Arduino.h>

class TB6612FNG_pse {
 private:
  // En "private" et non "protected", pour que ce soit également accessible aux classes enfantes (classe imbriquée nommée Moteur, ci-dessous)
  int _pinAIN1;
  int _pinAIN2;
  int _pinBIN1;
  int _pinBIN2;
  int _pinPWMA;
  int _pinPWMB;
  int _pinSTBY;

 private:
  class Moteur {
   public:
    int _pinIN1;
    int _pinIN2;
    int _pinPWM;

    Moteur();
    void inverserCablage();
    void debrayer();
    void freiner();
    void embrayerMarcheAvant();
    void embrayerMarcheArriere();
    void reglerVitesseDe0a255(uint8_t valeur);
  };

 public:
  Moteur moteurA;
  Moteur moteurB;

  TB6612FNG_pse(int pinAIN1, int pinAIN2, int pinBIN1, int pinBIN2, int pinPWMA, int pinPWMB, int pinSTBY);

  void mettreEnSommeil();
  void sortirDuSommeil();
};
