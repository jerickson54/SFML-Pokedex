/* CSCI 261 Final Pokdex Pokedex
*
* Author: Ben Tarman
* Username: btarman
* Section: A
*
* Author: Jake Erickson
* Username: jerickson
* Section: E
*
* Using our pokemon sprite pictures there are 974 Pokemon pictures along with every form
*
*
*/



#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include "pokemon.h"
#include <fstream>
#include <ctime>
#include <random>
#include<SFML\Audio.hpp>

void HandleWindow(string& str, Pokemon& pokemon);

void Draw_Window(sf::Vector2i &loadCounter, string& str, Pokemon& pokemon);

void textPosition(sf::Vector2i &loadCounter, Pokemon& pokemon, string& str);

string pokemontype(sf::Vector2i &loadCounter, Pokemon& pokemon, string& str);

void WhoThatPokemon(sf::Vector2i &loadCounter, string& str, Pokemon& pokemon);

int menu();


int main()
{
	string str = "";
	Pokemon pokemon;



	srand(time(NULL));



	sf::Vector2i loadCounter = sf::Vector2i(-1, 0);

	int check = menu();

	while (check != 4) {
		if (check == 1) {
			HandleWindow(str, pokemon);
			textPosition(loadCounter, pokemon, str);
			Draw_Window(loadCounter, str, pokemon);
		}

		else if (check == 2) {
			//do random function stuff for randomPokemon to modify parameter
			pokemon.SetRandPokemon();
			Draw_Window(loadCounter, pokemon.GetPokemon(), pokemon);

		}

		else if (check == 3)
		{
			pokemon.SetRandPokemon();

			textPosition(loadCounter, pokemon, pokemon.GetPokemon());

			WhoThatPokemon(loadCounter, pokemon.GetPokemon(), pokemon);

		}

		str = "";
		loadCounter = sf::Vector2i(-1, 0);
		check = menu();

	}

	return 0;



}


int menu()
{


	sf::RenderWindow window(sf::VideoMode(640, 640), "Pokedex Menu");
	sf::Sprite pokedex;
	sf::Texture pokedexTex;
	sf::Event event;
	sf::Font font;
	sf::Text displayText("Search Pokemon", font);
	sf::Text displayText2("Random Pokemon", font);
	sf::Text displayText3("Who's that Pokemon", font);
	sf::Text displayText4("Exit", font);

	sf::Text backButton("Press escape after your \n selection to go back to menu!", font);

	sf::Music route11;

	if (!route11.openFromFile("PokemonRBYRoute11.wav")) {
		cerr << "The file could not be found.";
	}

	route11.play();
	route11.setLoop(true);



	if (!font.loadFromFile("data/arial.ttf"))
	{
		cerr << "The file failed to open.";
	}

	displayText.setColor((sf::Color(0, 0, 0)));
	displayText2.setColor((sf::Color(0, 0, 0)));
	displayText3.setColor((sf::Color(0, 0, 0)));
	backButton.setColor(sf::Color(150, 0, 150));




	displayText.setPosition(sf::Vector2f(250, 400));
	displayText2.setPosition(sf::Vector2f(250, 440));
	displayText3.setPosition(sf::Vector2f(250, 480));
	displayText4.setPosition(sf::Vector2f(250, 520));
	backButton.setPosition(sf::Vector2f(250, 100));

	backButton.setCharacterSize(20);

	if (!pokedexTex.loadFromFile("pokedex.png")) {
		cerr << "The file failed to open.";
	}

	pokedex.setTexture(pokedexTex);


	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			sf::Vector2i localPosition = sf::Mouse::getPosition(window);

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.x > 250 && event.mouseButton.x < 485 && event.mouseButton.y > 400 && event.mouseButton.y < 440)
				{
					window.close();
					return 1;
				}

				else if (event.mouseButton.x > 250 && event.mouseButton.x < 495 && event.mouseButton.y > 440 && event.mouseButton.y < 475)
				{
					window.close();
					return 2;

				}

				else if (event.mouseButton.x > 250 && event.mouseButton.x < 525 && event.mouseButton.y > 480 && event.mouseButton.y < 515)
				{
					window.close();
					return 3;

				}

				else if (event.mouseButton.x > 250 && event.mouseButton.x < 300 && event.mouseButton.y > 520 && event.mouseButton.y < 550)
				{

					window.close();
					return 4;



				}


			}

			if ((localPosition.x >= 250) && (localPosition.x <= 485) && (localPosition.y >= 400) && (localPosition.y <= 440)) { //sets color to blue if mouse is over the text
				displayText.setColor(sf::Color(0, 0, 250));
			}

			else if ((localPosition.x >= 250) && (localPosition.x <= 495) && (localPosition.y >= 443) && (localPosition.y <= 475)) {
				displayText2.setColor(sf::Color(0, 0, 250));

			}

			else if ((localPosition.x >= 250) && (localPosition.x <= 525) && (localPosition.y >= 480) && (localPosition.y <= 515)) {
				displayText3.setColor(sf::Color(0, 0, 250));
			}

			else if ((localPosition.x >= 250) && (localPosition.x <= 300) && (localPosition.y >= 520) && (localPosition.y <= 550)) {
				displayText4.setColor(sf::Color(250, 0, 0));
			}

			else {
				displayText.setColor(sf::Color(0, 0, 0));
				displayText2.setColor(sf::Color(0, 0, 0));
				displayText3.setColor(sf::Color(0, 0, 0));
				displayText4.setColor(sf::Color(0, 0, 0));
			}



			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();

			}






		}

		pokedex.setPosition(-50, 0);

		window.draw(pokedex);
		window.draw(displayText);
		window.draw(displayText2);
		window.draw(displayText3);
		window.draw(displayText4);
		window.draw(backButton);
		window.display();
		window.clear();




	}







}




void HandleWindow(string& str, Pokemon& pokemon)
{

	sf::Font font;
	if (!font.loadFromFile("data/arial.ttf"))
	{
		// error...
	}
	sf::Text text(str, font);
	sf::Text askDisplay("Please enter Pokemon's name: ", font);
	sf::Text text2("Invalid. Please enter again.", font); //displays if user entered invalid stuff

	sf::Text backButton("Press escape after your \n selection to go back to menu!", font);

	backButton.setPosition(sf::Vector2f(100, 500));



	text.setPosition(sf::Vector2f(10, 200));
	text2.setPosition(sf::Vector2f(10, 100));
	askDisplay.setPosition(sf::Vector2f(10, 10));




	sf::RenderWindow window(sf::VideoMode(640, 640), "Enter your Pokemon");

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::TextEntered)
			{
				// Handle ASCII characters only
				if (event.text.unicode < 128)
				{
					str += static_cast<char>(event.text.unicode);
					text.setString(str);
					pokemon.SetPokemon(str);




				}
			}
			if (pokemon.SearchPokemon(str) != -1)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
				{

					window.close();

				}
			}
			else
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
				{

					window.clear();
					str.erase();
					window.draw(text2);

					window.display();



				}



			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();

			}

		}
		window.draw(text);

		window.draw(backButton);
		window.draw(askDisplay);
		window.display();
		window.clear();




	}



}




void Draw_Window(sf::Vector2i &loadCounter, string& str, Pokemon& pokemon)
{
	loadCounter = sf::Vector2i(-1, 0);

	sf::RenderWindow window(sf::VideoMode(640, 640), "Pokemon Display");
	std::string name = pokemon.GetPokemon();

	sf::View view2(sf::Vector2f(75, 75), sf::Vector2f(150, 150));
	sf::View view4;


	sf::Texture pokemonText;



	sf::Font font;
	if (!font.loadFromFile("data/arial.ttf"))
	{
		// error...
	}
	sf::Text text(pokemontype(loadCounter, pokemon, str), font);
	text.setCharacterSize(100);
	text.setPosition(sf::Vector2f(250, 100));


	sf::Text backButton("Press escape after your \n selection to go back to menu!", font);

	backButton.setPosition(sf::Vector2f(100, 500));
	backButton.setCharacterSize(45);


	if (!pokemonText.loadFromFile("sprites.png"))
	{
		// error...
	}


	sf::Sprite pokeSprite;

	pokeSprite.setTexture(pokemonText);

	sf::Event event;


	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{


			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close(); //closes the window if escaped is pressed


		}

		window.setView(view4);
		window.draw(backButton);
		window.draw(text);


		window.setView(view2);


		pokeSprite.setTextureRect(sf::IntRect(40 * loadCounter.x, 30 * loadCounter.y, 32, 32));


		window.draw(pokeSprite);
		window.display();
		window.clear();
	}


}



void textPosition(sf::Vector2i &loadCounter, Pokemon& pokemon, string& str)
{


	//loadCounter = sf::Vector2i(-1, 0);

	vector<int> pokemonIndex;
	int foundPokemon;

	vector<string> pokemons;



	ifstream FindPokemon2("pokedex.txt");

	if (FindPokemon2.fail())
	{
		//error
	}

	string name = "";




	ifstream FindPokemon("locationlocation.txt");

	if (FindPokemon.fail())
	{
		//error
	}

	char read;



	int counter = 0;


	while (!FindPokemon.eof())
	{

		FindPokemon >> read;

		if (FindPokemon.peek() == '\n')
		{
			loadCounter.x = 0;
			loadCounter.y++;
		}
		else
			loadCounter.x++;


		while (!FindPokemon2.eof())
		{

			FindPokemon2 >> name;

			pokemons.push_back(name);



		}

		if (pokemons.at(counter) == str)
		{

			break;
		}

		counter++;

	}





}






string pokemontype(sf::Vector2i &loadCounter, Pokemon& pokemon, string& str)
{
	vector<string> pokemonType;


	vector<string> pokemonName;

	loadCounter = sf::Vector2i(-1, 0);

	ifstream FindPokemon2("pokemonType.txt");

	if (FindPokemon2.fail())
	{
		//error
	}





	ifstream FindPokemon("locationlocation.txt");

	if (FindPokemon.fail())
	{
		//error
	}

	int index;

	char read;
	string name = "";
	string type = "";



	int counter = 0;


	while (!FindPokemon.eof())
	{

		FindPokemon >> read;

		if (FindPokemon.peek() == '\n')
		{
			loadCounter.x = 0;
			loadCounter.y++;
		}
		else
			loadCounter.x++;


		while (!FindPokemon2.eof())
		{

			FindPokemon2 >> name >> type;

			pokemonName.push_back(name);

			pokemonType.push_back(type);





		}

		if (pokemonName.at(counter) == str)
		{
			index = counter;
			break;
		}



		counter++;

	}






	string words = pokemonName.at(index) + "\n" + pokemonType.at(index);





	return words;
}



void WhoThatPokemon(sf::Vector2i &loadCounter, string& str, Pokemon& pokemon)
{


	str = "";

	std::string name = pokemon.GetPokemon();

	sf::View view2(sf::Vector2f(75, 75), sf::Vector2f(150, 150));
	sf::View view1;


	sf::Texture pokemonText;



	int isCorrect = 0;



	sf::RenderWindow window(sf::VideoMode(640, 640), "Pokemon Display");



	sf::Font font;
	if (!font.loadFromFile("data/arial.ttf"))
	{
		// error...
	}





	sf::Music JohnCena;

	if (!JohnCena.openFromFile("JohnCena.wav")) {
		cerr << "The file could not be found.";
	}

	JohnCena.play();




	sf::Text text(str, font);
	text.setCharacterSize(35);
	text.setPosition(200, 400);

	sf::Text backButton("Press escape after your \n selection to go back to menu!", font);
	backButton.setCharacterSize(35);
	backButton.setPosition(100, 500);

	sf::Text text2("Who's That Pokemon?", font);
	text2.setCharacterSize(35);
	text2.setPosition(200, 300);

	sf::Text wrong("Wrong", font);
	wrong.setCharacterSize(50);
	wrong.setPosition(200, 600);


	sf::Text correct("Correct", font);
	correct.setCharacterSize(50);
	correct.setPosition(200, 600);


	if (!pokemonText.loadFromFile("sprites.png"))
	{
		// error...
	}


	sf::Sprite pokeSprite;

	pokeSprite.setTexture(pokemonText);

	sf::Event event;




	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{


			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close(); //closes the window if escaped is pressed

			if (event.type == sf::Event::TextEntered)
			{
				// Handle ASCII characters only
				if (event.text.unicode < 128)
				{

					str += static_cast<char>(event.text.unicode);
					text.setString(str);
					pokemon.SetPokemon(str);
					break;

				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{

				if (name == str)
					isCorrect = 1;
				else
					isCorrect = 2;


			}

		}

		window.setView(view1);

		window.draw(text2);
		window.draw(backButton);
		window.draw(text);



		if (isCorrect == 1)
			window.draw(correct);
		else if (isCorrect == 2)
			window.draw(wrong);



		window.setView(view2);

		pokeSprite.setTextureRect(sf::IntRect(40 * loadCounter.x, 30 * loadCounter.y, 32, 32));

		window.draw(pokeSprite);


		window.display();
		window.clear();


	}



}