#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

class PodstawowyObiekt
{
protected:
	string nazwa;
	sf::Vector2f pozycja_na_mapie;
	sf::Texture tekstura;
	sf::Sprite sprite;

public:
	PodstawowyObiekt() {}
	PodstawowyObiekt(string s_nazwa, sf::Vector2i u_pozycja_na_mapie, string tekstura_sciezka, sf::Vector2f skala);

	string podajNazwe() { return nazwa; }
	sf::Vector2i podajPunktCentralnySpritea(); //odleglosc od lewego gornego rogu do srodka
	sf::Vector2f podajPozycjeNaMapie() { return pozycja_na_mapie; }
	sf::Vector2f podajPozycjeSprita() { return sprite.getPosition(); }
	sf::Sprite podajSprite() { return sprite; }

	virtual void aktualizujPolozenie(unsigned int szerokosc_mapy_w_pxl, unsigned int wysokosc_mapy_w_pxl, float czas_do_pozycjonowania) {}
	virtual void zmienKierunekRuchuWPionie(float y) {}
	virtual void zmienKierunekRuchuWPoziomie(float x) {}
};

class RuchomyObiekt : public PodstawowyObiekt
{
protected:
	unsigned int predkosc = 0; //piksele na sekunde
	sf::Vector2f kierunek = sf::Vector2f(0, 0);

public:
	RuchomyObiekt(string s_nazwa, sf::Vector2i u_pozycja_na_mapie, unsigned int u_predkosc, string tekstura_sciezka, sf::Vector2f skala)
		: PodstawowyObiekt::PodstawowyObiekt(s_nazwa, u_pozycja_na_mapie, tekstura_sciezka, skala),
		predkosc(u_predkosc)
	{}

	virtual void aktualizujPolozenie(unsigned int szerokosc_mapy_w_pxl, unsigned int wysokosc_mapy_w_pxl, float czas_do_pozycjonowania) override;
	virtual void zmienKierunekRuchuWPionie(float y) override;
	virtual void zmienKierunekRuchuWPoziomie(float x) override;
};

class Gracz : public RuchomyObiekt
{
public:
	Gracz(string s_nazwa, sf::Vector2i u_pozycja_na_mapie, unsigned int u_predkosc, string tekstura_sciezka, sf::Vector2f skala)
		: RuchomyObiekt::RuchomyObiekt(s_nazwa, u_pozycja_na_mapie, u_predkosc, tekstura_sciezka, skala)
	{}
};

class Drzewo : public PodstawowyObiekt
{
public:
	Drzewo(string s_nazwa, sf::Vector2i u_pozycja_na_mapie, string tekstura_sciezka, sf::Vector2f skala)
		: PodstawowyObiekt::PodstawowyObiekt(s_nazwa, u_pozycja_na_mapie, tekstura_sciezka, skala)
	{}
};