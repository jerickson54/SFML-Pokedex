#pragma once
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;


class Pokemon
{
public:
	Pokemon();
	int SearchPokemon(string x);
	void SetRandPokemon();
	string GetPokemon();
	void SetPokemon(string z);
	bool WhoThatPokemon(string z);

private:
	string pokeName;
	sf::Event event;




};