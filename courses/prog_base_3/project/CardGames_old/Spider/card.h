#include <string>

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
		short int getValueIdentifier();
		std::string getImagePath();
		void setValueIdentifier(short int valueInput);
		void setImagePath(std::string pathInput);
		void drawOnScreen();
		short int getColorIdentifier();
		void setColorIdentifier(short int id);
};

#endif
