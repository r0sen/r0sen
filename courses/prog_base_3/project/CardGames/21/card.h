#include <string>
#include <SFML/Graphics.hpp>
using namespace sf;
#ifndef CARD_H
#define CARD_H


class Card

{
	private:
		short int valueIdentifier;
		short int colorIdentifier;
        short int sideIdentifier;
		std::string imagePath;

	public:
	    Card();
	    		Sprite sprite;
		short int getValueIdentifier();
		std::string getImagePath();
		void setValueIdentifier(short int valueInput);
		void setImagePath(std::string pathInput);
		void drawOnScreen();
		short int getColorIdentifier();
		void setColorIdentifier(short int id);
		int posX;
		int posY;
		int height;
		int width;
		bool isClicked(int x, int y);
};

#endif
