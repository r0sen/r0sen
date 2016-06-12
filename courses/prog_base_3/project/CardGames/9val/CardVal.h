#ifndef CARDVAL_H
#define CARDVAL_H
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

class CardVal
{
	private:
		short int valueIdentifier;
		short int colorIdentifier;

	public:
	    CardVal();

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
