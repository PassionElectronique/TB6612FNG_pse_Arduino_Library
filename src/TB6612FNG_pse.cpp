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
//  Fichier     :       TB6612FNG_pse.cpp
//  Créé le     :       31.03.2026
//  Auteur      :       Jérôme TOMSKI
//  Site        :       https://passionelectronique.fr/
//  GitHub      :       https://github.com/PassionElectronique/TB6612FNG_pse_Arduino_Library
//  Licence     :       https://creativecommons.org/licenses/by-nc-nd/4.0/deed.fr (BY-NC-ND 4.0 CC)
//
// ===================================================================================================

#include "TB6612FNG_pse.h"

TB6612FNG_pse::TB6612FNG_pse(int pinAIN1, int pinAIN2, int pinBIN1, int pinBIN2, int pinPWMA, int pinPWMB, int pinSTBY) {
  _pinAIN1 = pinAIN1;
  _pinAIN2 = pinAIN2;
  _pinBIN1 = pinBIN1;
  _pinBIN2 = pinBIN2;
  _pinPWMA = pinPWMA;
  _pinPWMB = pinPWMB;
  _pinSTBY = pinSTBY;

  // clang-format off
  pinMode(_pinSTBY, OUTPUT);    digitalWrite(_pinSTBY, LOW);    // Par défaut, le module TB6612FNG sera désactivé (mise de STBY à l'état bas)
  pinMode(_pinAIN1, OUTPUT);    digitalWrite(_pinAIN1, LOW);
  pinMode(_pinAIN2, OUTPUT);    digitalWrite(_pinAIN2, LOW);
  pinMode(_pinBIN1, OUTPUT);    digitalWrite(_pinBIN1, LOW);
  pinMode(_pinBIN2, OUTPUT);    digitalWrite(_pinBIN2, LOW);
  pinMode(_pinPWMA, OUTPUT);    digitalWrite(_pinPWMA, LOW);
  pinMode(_pinPWMB, OUTPUT);    digitalWrite(_pinPWMB, LOW);
  // clang-format on

  moteurA._pinIN1 = _pinAIN1;
  moteurA._pinIN2 = _pinAIN2;
  moteurA._pinPWM = _pinPWMA;

  moteurB._pinIN1 = _pinBIN1;
  moteurB._pinIN2 = _pinBIN2;
  moteurB._pinPWM = _pinPWMB;
}

void TB6612FNG_pse::mettreEnSommeil() {
  digitalWrite(_pinSTBY, LOW);
}

void TB6612FNG_pse::sortirDuSommeil() {
  digitalWrite(_pinSTBY, HIGH);
}

TB6612FNG_pse::Moteur::Moteur() {}

void TB6612FNG_pse::Moteur::inverserCablage() {
  // On permute IN1 et IN2, tout simplement
  int _old_pinIN1 = _pinIN1;
  _pinIN1 = _pinIN2;
  _pinIN2 = _old_pinIN1;
}

void TB6612FNG_pse::Moteur::debrayer() {
  digitalWrite(_pinIN1, LOW);
  digitalWrite(_pinIN2, LOW);
  analogWrite(_pinPWM, 0);
}

void TB6612FNG_pse::Moteur::freiner() {
  digitalWrite(_pinIN1, HIGH);
  digitalWrite(_pinIN2, HIGH);
  analogWrite(_pinPWM, 0);
}

void TB6612FNG_pse::Moteur::embrayerMarcheAvant() {
  digitalWrite(_pinIN1, HIGH);
  digitalWrite(_pinIN2, LOW);
}

void TB6612FNG_pse::Moteur::embrayerMarcheArriere() {
  digitalWrite(_pinIN1, LOW);
  digitalWrite(_pinIN2, HIGH);
}

void TB6612FNG_pse::Moteur::reglerVitesseDe0a255(uint8_t vitesse) {
  analogWrite(_pinPWM, vitesse);
}
