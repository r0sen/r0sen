#ifndef CARD_H
#define CARD_H
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

class Card
{
	private:
		short int valueIdentifier;
		short int colorIdentifier;




	public:
	    Card();

	    bool isClicked(int x, int y);
		short int getValueIdentifier();

		void setValueIdentifier(short int valueInput);

		void drawOnScreen();
		short int getColorIdentifier();
		void setColorIdentifier(short int id);
		Sprite sprite;
		int posX;
		int posY;
		int width;
		int height;
		bool visible;
		void setTexture();
		Texture texture;

};

#endif
