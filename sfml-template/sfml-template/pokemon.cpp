#include <string>
#include <iostream>
#include "pokemon.h"
#include <time.h>
#include <fstream>
using namespace std;

#include <SFML/Graphics.hpp>

Pokemon::Pokemon()
{
	pokeName = "Trevenant";
}


void Pokemon::SetPokemon(string z)
{
	pokeName = z;


}

void Pokemon::SetRandPokemon()
{

	int randomPokemon;


	vector<string> pokemons;
	vector<int> pokemonIndex;
	int foundPokemon;

	ifstream FindPokemon("pokedex.txt");

	if (FindPokemon.fail())
	{
		//error
	}

	string name = "";




	while (!FindPokemon.eof())
	{
		FindPokemon >> name;

		pokemons.push_back(name);


	}



	randomPokemon = (rand() % pokemons.size() + 1);

	pokeName = pokemons.at(randomPokemon);





}

int Pokemon::SearchPokemon(string x)
{
	vector<string> pokemons;
	vector<int> pokemonIndex;
	int foundPokemon;

	ifstream FindPokemon("pokedex.txt");

	if (FindPokemon.fail())
	{
		//error
	}

	string name = "";

	int counter = 0;


	while (!FindPokemon.eof())
	{
		FindPokemon >> name;

		pokemons.push_back(name);

		pokemonIndex.push_back(counter);

		counter++;
	}



	for (int i = 0; i < pokemons.size(); i++)
	{
		if (pokemons.at(i) == x) {

			foundPokemon = pokemonIndex.at(i);
			return foundPokemon;
		}


	}

	return -1;

}

string Pokemon::GetPokemon()
{
	return pokeName;
}






bool Pokemon::WhoThatPokemon(string z)
{
	if (z == GetPokemon())
		return true;
	else
		return false;
}